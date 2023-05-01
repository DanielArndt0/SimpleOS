#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/Heap.h"

namespace SimpleOS
{
  namespace Root
  {
    template <Data::UInt HeapSize>
    class VRam
    {
    private:
      SimpleOS::Data::Heap<HeapSize> heap;

    protected:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
      virtual void *malloc(Data::Size size)
      {
        if (heap.stack + size + sizeof(Data::Size) > SYSM_ARRAY_SIZE(heap.heap) || size <= 0)
          return nullptr;
        heap.stack += size + sizeof(Data::Size);
        void *ptr = &heap.heap[heap.stack];
        *reinterpret_cast<Data::Size *>(ptr - sizeof(Data::Size)) = size;
        return ptr;
      }

      virtual void free(void *ptr)
      {
        if (
            ptr == nullptr ||
            ptr < heap.heap ||
            ptr >= heap.heap + getHeapSize())
          return;
        Data::Char *hdrPtr = static_cast<Data::Char *>(ptr) - sizeof(Data::Size);
        Data::Size size = *reinterpret_cast<Data::Size *>(hdrPtr);
        heap.stack -= size + sizeof(Data::Size);
      }
#pragma GCC diagnostic pop

      // Getters
      constexpr Data::UInt getHeapSize() const { return HeapSize; }
      constexpr Data::Size getTotal() const { return sizeof(heap.heap) / sizeof(heap.heap[0]); }
      constexpr Data::Size getFreeHeap() const { return getTotal() - heap.stack; }
      constexpr Data::Size getUsedHeap() const { return heap.stack; }
      void *getHeapStartAddr() { return heap.heap; }
      void *getHeapEndAddr() { return heap.heap + HeapSize; }

    protected:
      ~VRam() = default;
    };
  }
}
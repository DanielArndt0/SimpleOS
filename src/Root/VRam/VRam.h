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
      static SimpleOS::Data::Heap<HeapSize> heap;

    public:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
      [[nodiscard]] static void *malloc(Data::Size size)
      {
        if (heap.stack + size + sizeof(Data::Size) > SYSM_ARRAY_SIZE(heap.heap) || size <= 0)
          return nullptr;
        heap.stack += size + sizeof(Data::Size);
        void *ptr = &heap.heap[heap.stack];
        *reinterpret_cast<Data::Size *>(ptr - sizeof(Data::Size)) = size;
        return ptr;
      }

      [[nodiscard]] static void *calloc(Data::Size nElements, Data::Size elementSize) { return malloc(nElements * elementSize); }

      static void free(void *ptr)
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
      static constexpr Data::Size getHeapSize() { return sizeof(heap.heap) / sizeof(heap.heap[0]); }
      static constexpr Data::Size getFreeHeap() { return getHeapSize() - heap.stack; }
      static constexpr Data::Size getUsedHeap() { return heap.stack; }
      static void *getHeapStartAddr() { return heap.heap; }
      static void *getHeapEndAddr() { return heap.heap + HeapSize; }

    public:
      ~VRam() = default;
    };

    template <SimpleOS::Data::UInt HeapSize>
    SimpleOS::Data::Heap<HeapSize> SimpleOS::Root::VRam<HeapSize>::heap;
  }
}
#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/Containers/List/LinkedList.h"


namespace SimpleOS
{
  namespace Memory
  {
    template <typename T>
    class Block
    {
    public:
      Block &operator=(Block &cpy)
      {
        this->startAddr = cpy.startAddr;
        this->endAddr = cpy.endAddr;
        this->id = cpy.id;
        return *this;
      }

      //bool operator==(const Block &cpy) { return this->startAddr == cpy.startAddr && this->endAddr == cpy.endAddr; }

    public:
      T *startAddr;
      T *endAddr;
      Data::ID id;

    public:
      Block() = default;
      Block(T *startAddr, T *endAddr, Data::ID id)
          : startAddr(startAddr), endAddr(endAddr), id(id) {}

      //bool equals(Block & cmp) { return this == cmp; }
    };

    template <typename T, Data::UInt Size>
    class Allocator
    {
    private:
      T heap[Size];
      Data::UInt heap_pos = 0;
      SimpleOS::Beta::Data::LinkedList<Block<T>> blockList;

    public:
      Allocator()
      {
      }

      SimpleOS::Beta::Data::LinkedList<Block<T>> &getBlockList() { return blockList; }

      constexpr Data::Size getTotal() const { return sizeof(heap) / sizeof(heap[0]); }

      constexpr Data::Size getFreeHeap() const { return getTotal() - heap_pos; }

      constexpr Data::Size getUsedHeap() const { return heap_pos; }

      constexpr Data::Size getBlockBytes() const { return getTotal() * sizeof(T); }

      constexpr T *getHeapStartAddr() { return heap; }

      constexpr T *getHeapEndAddr() { return heap + Size; }

      T *malloc(Data::Size size)
      {
        if (heap_pos + size > SYSM_ARRAY_SIZE(heap))
          return nullptr;
        blockList.add(
            Block<T>(&heap[heap_pos], &heap[heap_pos] + size, heap_pos));
        heap_pos += size;
        return &heap[heap_pos];
      }

      void free(T *ptr, Data::Size size)
      {
        if (
            ptr == nullptr ||
            ptr < reinterpret_cast<T *>(heap) ||
            ptr >= reinterpret_cast<T *>(heap) + Size)
          return;
        heap_pos -= size;
      }
    };
  }
}
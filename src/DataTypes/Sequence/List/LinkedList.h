#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Sequence/LinkedStruct/LinkedContainer.h"
#include "DataTypes/Sequence/List/List.h"
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class LinkedList : extends LinkedContainer<T> ,  List<T>
    {
    public:
      // Operators
      T operator[](Index key) const override { return this->cGet(key); }

      List<T> &operator=(List<T> &list) override
      {
        this->Copy(list);
        return *this;
      }

    public:
      // Capacity
      bool isEmpty() const override { return this->cIsEmpty(); }

      unsigned long Size() const override { return this->cSize(); }

      bool Exist(T value) const override { return this->cExist(value); }

      T Error() const override { return this->cError(); }

      // Element Acess
      T First() const override { return this->cGet((Index)0); }

      T Last() const override { return this->cGet((Index)(this->cSize() - 1)); }

      T Get(Index key) const override { return this->cGet(key); }

      Index Get(T value) const override { return this->cGetIndex(value); }

      // Modifiers
      T Put(Index key, T value) override { return this->cPut(key, value); }

      T PushFront(T value) override { return this->cPush(0x00, value); }

      T PushBack(T value) override { return this->cPush(this->cSize(), value); }

      T Push(Index key, T value) override { return this->cPush(key, value); }

      T PopFront() override { return this->cPop(0x00); }

      T PopBack() override { return this->cPop(this->cSize() - 1); }

      T Pop(Index key) override { return this->cPop(key); }

      T Pop(T value) override { return this->cPop(this->cGetIndex(value)); }

      void Reset() override { this->cReset(); }

      void Delete() override { this->cDelete(); }

      void Swap(List<T> &list) override
      {
        LinkedList<T> tmp;
        tmp.Copy(list);
        list.Copy(*this);
        this->Copy(tmp);
      }
    };
  }
}
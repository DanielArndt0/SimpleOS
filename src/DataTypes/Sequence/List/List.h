#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Object/Object.h"
/**
 * array list   // Ok
 * linked list          // Ok
 * doubly linked list   // To Do
 * circular list        // To Do
 */
namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class List implements Root::Object
    {
    public:
      // Operators
      virtual List<T> &operator=(List<T> &list) = 0;
      virtual T operator[](Index key) const = 0;

      // Capacity
      virtual bool isEmpty() const = 0;
      virtual unsigned long Size() const = 0;
      virtual bool Exist(T value) const = 0;

      // Element Acess
      virtual T First() const = 0;
      virtual T Last() const = 0;
      virtual T Get(Index key) const = 0;
      virtual Index Get(T value) const = 0;
      virtual T Error() const = 0;

      // Modifiers
      virtual T Put(Index key, T value) = 0;
      virtual T PushFront(T value) = 0;
      virtual T PushBack(T value) = 0;
      virtual T Push(Index key, T value) = 0;
      virtual T PopFront() = 0;
      virtual T PopBack() = 0;
      virtual T Pop(Index key) = 0;
      virtual T Pop(T value) = 0;

      // Operations
      virtual void Copy(List<T> &list)
      {
        this->Reset();
        unsigned int size = list.Size();
        for (Index i = 0; i < size; i++)
          this->PushBack(list.Get(i));
      }

      virtual void Swap(List<T> &list) = 0;

      virtual void Merge(List<T> &list)
      {
        unsigned long size = list.Size();
        for (Index i = 0; i < size; i++)
          this->PushBack(list.Get(i));
        list.Reset();
      }

      virtual void Concat(List<T> &list)
      {
        unsigned long size = list.Size();
        for (Index i = 0; i < size; i++)
          this->PushBack(list.Get(i));
      }

      virtual void Reverse()
      {
        unsigned long size = this->Size();
        for (Index i = 0; i < size; i++)
          this->Push(0x00, this->Pop(i));
      }

      virtual void Reset() = 0;

      virtual void Delete() = 0;
    };
  }
}

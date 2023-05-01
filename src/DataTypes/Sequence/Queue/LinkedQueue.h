#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Sequence/SimpleContainer.h"
#include "DataTypes/Sequence/LinkedStruct/LinkedContainer.h"
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class LinkedQueue : extends LinkedContainer<T> ,  SimpleContainer<T>
    {
    public:
      bool isEmpty() const override { return this->cIsEmpty(); }

      unsigned long Size() const override { return this->cSize(); }

      T Error() const override { return this->cError(); }

      T First() const override { return this->cGet((Index)0); }

      T Last() const override { return this->cGet((Index)(this->cSize() - 1)); }

      T Push(T value) override { return this->cPushBack(value); }

      T Pop() override { return this->cPopFront(); }

      void Reset() override { this->cReset(); }

      void Delete() override { this->cDelete(); }
    };
  }
}
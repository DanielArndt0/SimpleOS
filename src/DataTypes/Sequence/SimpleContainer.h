#pragma once
#include "SimpleOS/Macros.h"
#include "DataTypes/Object/Object.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class SimpleContainer : implements Root::Object
    {
    public:
      // Capacity
      virtual bool isEmpty() const = 0;
      virtual unsigned long Size() const = 0;

      // Element Acess
      virtual T First() const = 0;
      virtual T Last() const = 0;
      virtual T Error() const = 0;

      // Modifiers
      virtual T Push(T value) = 0;
      virtual T Pop() = 0;

      // Operations
      virtual void Reset() = 0;
      virtual void Delete() = 0;
    };
  }
}

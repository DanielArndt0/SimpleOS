#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename Derived>
    class EquatableMethods
    {
    public:
      // Methods
      virtual bool equals(const Derived &cmp) const = 0;
      
      // Destructor
      virtual ~EquatableMethods() = default;

    protected:
      // Constructor
      EquatableMethods() = default;
    };

    template <typename Derived>
    class Equatable
        : implements EquatableMethods<Derived>
    {
    public:
      // Operators
      bool operator==(const Derived &cmp) const { return this->equals(cmp); }
      bool operator!=(const Derived &cmp) const { return !this->equals(cmp); }

      // Destructor
      virtual ~Equatable() = default;

    protected:
      Equatable() = default;
    };
  }
}

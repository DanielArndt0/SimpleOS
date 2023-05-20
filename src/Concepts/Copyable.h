#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename Derived>
    class CopyableMethods
    {
    public:
      // Methods
      virtual Derived &copy(const Derived &copy) = 0;

    public:
      // Destructor
      virtual ~CopyableMethods() = default;
    };

    template <typename Derived>
    class Copyable
        : implements CopyableMethods<Derived>
    {
    public:
      // Operators
      virtual Derived &operator=(const Derived &copy) { return this->copy(copy); }

    public:
      // Destructor
      virtual ~Copyable() = default;
    };
  }
}
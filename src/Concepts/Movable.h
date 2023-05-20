#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename Derived>
    class MovableMethods
    {
    public:
      // Methods
      virtual Derived &move(Derived &&move) = 0;

    public:
      // Destructor
      virtual ~MovableMethods() = default;
    };

    template <typename Derived>
    class Movable
        : conceptualize MovableMethods<Derived>
    {
    public:
      // Operators
      virtual Derived &operator=(Derived &&move) { return this->move(static_cast<Derived &&>(move)); }

    public:
      // Destructor
      virtual ~Movable() = default;
    };
  }
}
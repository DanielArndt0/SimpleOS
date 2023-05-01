#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename Derived>
    class Default
    {
    public:
      // Methods
      virtual Derived defaultValue() { return Derived(); }

      // Destructors
      virtual ~Default() = default;
    };
  }
}
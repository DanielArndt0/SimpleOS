#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename T = void>
    class Bootable
    {
    public:
      // Methods
      virtual T boot(void) = 0;

      // Destructors
      virtual ~Bootable() = default;
    };
  }
}
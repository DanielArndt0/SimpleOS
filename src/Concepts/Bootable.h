#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Bootable
    {
    public:
      // Methods
      virtual int boot(void) = 0;

      // Destructors
      virtual ~Bootable() = default;
    };
  }
}
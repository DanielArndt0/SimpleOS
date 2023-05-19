#pragma once
#include "SimpleOS/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Bootable
    {
    public:
      // Methods
      virtual Data::Int boot(void) = 0;

      // Destructors
      virtual ~Bootable() = default;
    };
  }
}
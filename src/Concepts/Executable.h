#pragma once
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Executable
    {
    public:
      // Methods
      virtual Data::Int execute(void) = 0;

      // Destructors
      virtual ~Executable() = default;
    };
  }
}
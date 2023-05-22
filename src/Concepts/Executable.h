#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Executable
    {
    public:
      // Methods
      virtual int execute(void) = 0;

      // Destructors
      virtual ~Executable() = default;
    };
  }
}
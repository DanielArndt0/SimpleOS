#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Executable
    {
    public:
      // Methods
      virtual void execute(void) = 0;

      // Destructors
      virtual ~Executable() = default;
    };
  }
}
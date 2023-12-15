#pragma once
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template<typename ReturnType = void>    
    class Executable
    {
    public:
      // Methods
      virtual ReturnType execute(void) = 0;

      // Destructors
      virtual ~Executable() = default;
    };
  }
}
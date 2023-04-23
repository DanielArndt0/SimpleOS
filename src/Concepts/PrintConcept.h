#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class PrintConcept
    {
    public: // Methods
      virtual void print() = 0;
    };
  }
}
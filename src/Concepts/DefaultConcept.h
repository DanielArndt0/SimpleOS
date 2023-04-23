#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename T>
    conceptClass DefaultConcept
    {
    public: // Methods
      virtual T getDefaultValue() = 0;
    };
  }
}
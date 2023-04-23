#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename T>
    conceptClass CopyConcept
    {
    public: // Operators
      virtual T &operator=(T &cpy) = 0;
      virtual T &operator=(T &&move) = 0;

    public: // Methods
      virtual T &copy(T & cpy) = 0;
      virtual T &move(T && move) = 0;
    };
  }
}
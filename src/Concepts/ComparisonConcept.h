#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename T>
    conceptClass ComparisonConcept
    {
    public: // Operators
      virtual bool operator==(T &cmp) = 0;
      virtual bool operator!=(T &cmp) = 0;
      virtual bool operator>=(T &cmp) = 0;
      virtual bool operator>(T &cmp) = 0;
      virtual bool operator<=(T &cmp) = 0;
      virtual bool operator<(T &cmp) = 0;
      
    public: // Methods
      virtual bool equals(T & cmp) = 0;
    };
  }
}
#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Root
  {
    template <unsigned int Size>
    struct Heap
    {
      void *heap[Size];
      unsigned int stack = 0;
    };
  }
}
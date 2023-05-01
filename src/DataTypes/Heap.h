#pragma once
#include "SimpleOS/Base.h"

namespace SimpleOS
{
  namespace Data
  {
    template<UInt Size>
    struct Heap
    {
      void *heap[Size];
      UInt stack = 0;
    };
  }
}
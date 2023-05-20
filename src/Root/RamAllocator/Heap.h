#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Root
  {
    template<Data::UInt Size>
    struct Heap
    {
      void *heap[Size];
      Data::UInt stack = 0;
    };
  }
}
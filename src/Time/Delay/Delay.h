#pragma once
#include "System/Base.h"
#include "System/Instances/Timer0/Timer0.h"

namespace SimpleOS
{
  namespace Time
  {
    class Delay
    {
    public:
      void delay(unsigned long ms);

    public:
      Delay() = default;
      ~Delay() = default;
    }; // class Delay
  }  // namespace Time
} // namespace SimpleOS

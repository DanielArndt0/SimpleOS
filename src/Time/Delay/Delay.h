#pragma once
#include "System/Base.h"
#include "Interrupt/Timer0/Timer0.h"


namespace SimpleOS
{
  namespace Time
  {
    class Delay
    {
    public:
      void wait(unsigned long ms);

    public:
      Delay(unsigned long ms);
      ~Delay() = default;
    }; // class Delay
  }    // namespace Time
} // namespace SimpleOS

#pragma once
#include "System/Base.h"
#include "System/Instances/Timer0/Timer0.h"
#include "Communication/UART/UART.h"

namespace SimpleOS
{
  namespace Time
  {
    class Delay
    {
    private:
      Com::UART com;

    public:
      void delay(unsigned long ms);

    public:
      Delay() = default;
      ~Delay() = default;
    }; // class Delay
  } // namespace Time
} // namespace SimpleOS

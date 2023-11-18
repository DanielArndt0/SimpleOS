#pragma once
#include <avr/interrupt.h>
#include <avr/io.h>
#include "System/Base.h"

#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Core
  {
    class TMR0Core
    {
    protected:
      void enable();
      void disable();
      bool status();
      void reset();

    public:
      TMR0Core();
      ~TMR0Core() = default;
    }; // class TMR0Core
  }    // namespace Core
} // namespace SimpleOS

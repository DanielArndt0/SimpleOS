#pragma once
#include <avr/io.h>
#include "System/Base.h"

namespace SimpleOS
{
  namespace Core
  {
    class TWICore
    {
    public:
      void begin(unsigned long freq);
      void start(void);
      void restart(void);
      void write(unsigned char byte);
      unsigned char read();
      void stop(void);
      void disable(void);

    public:
      TWICore() = default;
      ~TWICore() = default;
    }; // class TWICore
  }    // namespace Core
} // namespace SimpleOS

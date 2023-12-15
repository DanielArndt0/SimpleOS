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
      void write(char data);
      char read();
      void stop(void);
      void send(char data, unsigned char addr);
      char receive(unsigned char addr);
      void disable(void);

    public:
      TWICore() = default;
      ~TWICore() = default;
    }; // class TWICore
  }    // namespace Core
} // namespace SimpleOS

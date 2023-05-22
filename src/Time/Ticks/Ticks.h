#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Time
  {
    class Ticks
    {
    private:
      unsigned long ticks;

    public:
      Ticks() = default;
      virtual ~Ticks() = default;

    private:
      void decrement();

    public:
      unsigned long get();
      void increment();
      void reset();
    };
  } // namespace Time
} // namespace SimpleOS

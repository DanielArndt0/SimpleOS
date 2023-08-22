#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Time
  {
    class Counter
    {
    private:
      unsigned long ticks;

    public:
      Counter();
      ~Counter() = default;

    public:
      unsigned long get()const ;
      unsigned long set(unsigned long quantity);
      unsigned long increment();
      unsigned long increment(unsigned long quantity);
      unsigned long decrement();
      unsigned long decrement(unsigned long quantity);
      unsigned long reset();

    public:
      operator unsigned long() const;
    };
  } // namespace Time
} // namespace SimpleOS

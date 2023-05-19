#pragma once
#include "SimpleOS/Base.h"

namespace SimpleOS
{
  namespace Time
  {
    class Ticks
    {
    private:
      Data::ULong ticks;

    public:
      Ticks() = default;
      virtual ~Ticks() = default;

    protected:
      void decrement();

    public:
      Data::ULong get();
      void increment();
      void reset();
    };
  } // namespace Time
} // namespace SimpleOS

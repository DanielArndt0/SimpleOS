#include "Ticks.h"

SimpleOS::Data::ULong SimpleOS::Time::Ticks::get() { return ticks; }

void SimpleOS::Time::Ticks::increment() { ticks += 1; }

void SimpleOS::Time::Ticks::decrement() { ticks -= 1; }

void SimpleOS::Time::Ticks::reset() { ticks = 0; }
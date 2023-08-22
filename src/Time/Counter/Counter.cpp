#include "Counter.h"

SimpleOS::Time::Counter::Counter() : ticks(0) {}

unsigned long SimpleOS::Time::Counter::get() const { return ticks; }

unsigned long SimpleOS::Time::Counter::set(unsigned long quantity) { return ticks = quantity; }

unsigned long SimpleOS::Time::Counter::increment() { return ticks += 1; }

unsigned long SimpleOS::Time::Counter::increment(unsigned long quantity) { return ticks += quantity; }

unsigned long SimpleOS::Time::Counter::decrement() { return ticks -= 1; }

unsigned long SimpleOS::Time::Counter::decrement(unsigned long quantity) { return ticks -= quantity; }

unsigned long SimpleOS::Time::Counter::reset() { return ticks = 0; }

SimpleOS::Time::Counter::operator unsigned long() const { return ticks; }
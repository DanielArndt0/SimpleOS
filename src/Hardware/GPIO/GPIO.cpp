#include "Hardware/GPIO/GPIO.h"

SimpleOS::Hardware::Pin SimpleOS::Hardware::GPIO::getPin(SimpleOS::Data::UInt pin) const { return Pin(pin); }
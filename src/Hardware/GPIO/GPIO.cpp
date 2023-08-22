#include "Hardware/GPIO/GPIO.h"

SimpleOS::Hardware::Pin SimpleOS::Hardware::GPIO::getPin(unsigned int pin)  { return Pin(pin); }
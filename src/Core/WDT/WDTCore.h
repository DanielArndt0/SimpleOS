#pragma once
#include <avr/interrupt.h>
#include <avr/io.h>
#include "System/Base.h"
#include "Core/WDT/WDTPrescaler.h"
#include "Core/WDT/WDTMode.h"

// Watchdog Timer Core
namespace SimpleOS
{
  namespace Core
  {
    class WDTCore
    {
    private:
      WDTPrescaler prescaler;
      WDTMode mode;

    protected:
      void setup(WDTPrescaler prescaler = WDTPrescaler::C2048, WDTMode mode = WDTMode::Interrupt)
      {
        cli();
        wdtReset();
        editMode();
        setPrescaler(prescaler);
        setMode(mode);
        sei();
      }

      WDTPrescaler getPrescaler() const { return prescaler; }

      WDTMode getMode() const { return mode; }

      void setPrescaler(WDTPrescaler prescaler)
      {
        this->prescaler = prescaler;
        BIT_WRITE_REG(WDTCSR, WDP0, BIT_CHECK((unsigned char)prescaler, 0));
        BIT_WRITE_REG(WDTCSR, WDP1, BIT_CHECK((unsigned char)prescaler, 1));
        BIT_WRITE_REG(WDTCSR, WDP2, BIT_CHECK((unsigned char)prescaler, 2));
        BIT_WRITE_REG(WDTCSR, WDP3, BIT_CHECK((unsigned char)prescaler, 3));
      }

      void setMode(WDTMode mode)
      {
        this->mode = mode;
        BIT_WRITE_REG(WDTCSR, WDIE, BIT_CHECK((unsigned char)mode, 0));
        BIT_WRITE_REG(WDTCSR, WDE, BIT_CHECK((unsigned char)mode, 1));
      }

      void wdtReset() { BIT_CLEAR(MCUSR, WDRF); }

      void editMode() { BIT_WRITE_REG(WDTCSR, WDCE, true); }
    };
  } // namespace Core
} // namespace SimpleOS

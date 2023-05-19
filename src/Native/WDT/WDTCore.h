#pragma once
#include <avr/interrupt.h>
#include <avr/io.h>
#include "SimpleOS/Base.h"
#include "Native/WDT/WDTPrescaler.h"
#include "Native/WDT/WDTMode.h"

// Watchdog Timer Core
namespace SimpleOS
{
  namespace Native
  {
    class WDTCore
    {
    private:
      WDTPrescaler prescaler;
      WDTMode mode;

    public:
      WDTCore(WDTPrescaler prescaler = WDTPrescaler::C2048, WDTMode mode = WDTMode::Interrupt)
      {
        setPrescaler(prescaler);
        setMode(mode);
      }
      virtual ~WDTCore() = default;

    protected:
      WDTPrescaler gerPrescaler() const { return prescaler; }

      WDTMode getMode() const { return mode; }

      void setPrescaler(WDTPrescaler prescaler)
      {
        this->prescaler = prescaler;
        SYSM_WRITE_REG(WDTCSR, WDP0, SYSM_CHECK((Data::UChar)prescaler, 0));
        SYSM_WRITE_REG(WDTCSR, WDP1, SYSM_CHECK((Data::UChar)prescaler, 1));
        SYSM_WRITE_REG(WDTCSR, WDP2, SYSM_CHECK((Data::UChar)prescaler, 2));
        SYSM_WRITE_REG(WDTCSR, WDP3, SYSM_CHECK((Data::UChar)prescaler, 3));
      }

      void setMode(WDTMode mode)
      {
        this->mode = mode;
        cli();
        SYSM_WRITE_REG(WDTCSR, WDIE, SYSM_CHECK((Data::UChar)mode, 0));
        SYSM_WRITE_REG(WDTCSR, WDE, SYSM_CHECK((Data::UChar)mode, 1));
        sei();
      }
    };
  } // namespace Native
} // namespace SimpleOS

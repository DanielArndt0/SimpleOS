#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "ResetType.h"

namespace SimpleOS
{
  namespace Core
  {
    class ResetCore
    {
    public:
      ResetType getResetType()
      {
        unsigned char resetStatus = MCUSR;
        MCUSR = 0;

        switch (resetStatus)
        {
        case static_cast<unsigned char>(ResetType::PowerOn):
          return ResetType::PowerOn;

        case static_cast<unsigned char>(ResetType::External):
          return ResetType::External;

        case static_cast<unsigned char>(ResetType::BrownOut):
          return ResetType::BrownOut;

        case static_cast<unsigned char>(ResetType::WatchdogSystem):
          return ResetType::WatchdogSystem;

        default:
          return ResetType::Unknown;
        }
      }
    };
  } // namespace Core
} // namespace  SimpleOS

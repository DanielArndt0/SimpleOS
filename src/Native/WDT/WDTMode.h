#pragma once
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Native
  {
    enum class WDTMode : Data::UChar
    {
      Stopped,
      Interrupt,
      Reset,
      InterruptAndReset
    };
  }
}
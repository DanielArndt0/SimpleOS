#pragma once

namespace SimpleOS
{
  namespace Native
  {
    enum class WDTMode : unsigned char
    {
      Stopped,
      Interrupt,
      Reset,
      InterruptAndReset
    };
  }
}
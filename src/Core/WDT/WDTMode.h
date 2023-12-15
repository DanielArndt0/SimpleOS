#pragma once

namespace SimpleOS
{
  namespace Core
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
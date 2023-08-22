#pragma once

namespace SimpleOS
{
  namespace Hardware
  {
    enum class PinMode : unsigned char
    {
      OUTPUT = 0x01,
      INPUT = 0x00,
    };
  }
}

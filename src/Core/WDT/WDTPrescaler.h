#pragma once

namespace SimpleOS
{
  namespace Core
  {
    enum class WDTPrescaler : unsigned char
    {
      C2048 = 0,
      C4096 = 1,
      C8192 = 2,
      C16K = 3,
      C32K = 4,
      C64K = 5,
      C128K = 6,
      C256K = 7,
      C512K = 8,
      C1024K = 9
    };
  }
}
#pragma once

namespace SimpleOS
{
  namespace Core
  {
    enum class ResetType : unsigned char
    {
      PowerOn = 1,
      External = 2,
      BrownOut = 4,
      WatchdogSystem = 8,
      Unknown = 0
    };
  } // namespace Core
} // namespace SimpleOS

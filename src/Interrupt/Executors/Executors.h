#include "WatchdogExecutor.h"
#include "TimerExecutor.h"
#include "ThreadExecutor.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class Executors
    {
    public:
      static WatchdogExecutor watchdogExecutor;
      static TimerExecutor timerExecutor;
    };
    SimpleOS::Interrupt::WatchdogExecutor SimpleOS::Interrupt::Executors::watchdogExecutor;
    SimpleOS::Interrupt::TimerExecutor SimpleOS::Interrupt::Executors::timerExecutor;
  } // namespace Interrupt
} // namespace SimpleOS

#pragma once
#include "System/Base.h"
#include "System/Instances/Executors.h"
#include "System/Instances/Watchdog/WatchdogTimer.h"
#include "System/Instances/Timer0/Timer0.h"
#include "System/Instances/Drivers.h"

INT(WDT_vect)
{
  SimpleOS::Instance::WatchdogTimer::watchdogTicks.increment();
  if (SimpleOS::Instance::Executors::watchdogExecutor.isEnabled())
    SimpleOS::Instance::Executors::watchdogExecutor.execute();
}

INT(TIMER0_OVF_vect)
{
  SimpleOS::Instance::Timer0::timerTicks.increment();
  if (SimpleOS::Instance::Executors::timerExecutor.isEnabled())
    SimpleOS::Instance::Executors::timerExecutor.execute();
}

INT(USART_RX_vect) { SimpleOS::Instance::Drivers::serial.virtualReceiverBufferTask(); }

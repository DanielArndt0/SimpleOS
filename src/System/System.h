#pragma once

// Macros
#include "Macros.h" // DONE

// Concepts
#include "Concepts.h" // DONE

// Interrupts
#include "System/Instances/Watchdog/WatchdogTimer.h" // DONE
#include "System/Instances/Timer0/Timer0.h"       // DONE
#include "Interrupt/Executors/WatchdogExecutor.h" // DONE
#include "Interrupt/Executors/TimerExecutor.h"    // DONE

// System
#include "System/SystemMacros.h"
#include "System/Methods.h"    // DONE
#include "System/Instances/Drivers.h" // DONE
#include "System/ISRVectors.h" // DONE

// Core's
#include "Core/EEPROM/EECore.h"   // DONE Core methods - EEPROM
#include "Core/UART/UARTCore.h"   // DONE Core methods - UART
#include "Core/GPIO/GPIOCore.h"   // DONE Core methods - GPIO
#include "Core/WDT/WDTCore.h"     // DONE Core methods - WDT
#include "Core/RESET/ResetCore.h" // DONE Core methods - RESET
#include "Core/TIMER0/TMR0Core.h" // DONE Core methods - TIMER0
#include "Core/TWI/TWICore.h"     // DONE Core methods - TWI
#include "Core/THREAD/Thread.h"   // DONE Core methods - Threads

// RAM
#include "Memory/SRAM/RamInfo.h" // DONE

// Hardware
#include "Communication/UART/UART.h" // DONE
#include "Hardware/Pin/Pin.h"        // DONE
#include "Memory/EEPROM/EEPROM.h"    // DONE

// System Status
#include "SystemStatus/Status.h"    // DONE
#include "SystemStatus/ErrorCode.h" // DONE

// Time
#include "Time/Counter/Counter.h" // DONE
#include "Time/Delay/Delay.h"     // DONE

// Data types
#include "DataTypes/Number.h"                           // DONE
#include "DataTypes/Duet.h"                             // DONE
#include "DataTypes/String/SimpleString/SimpleString.h" // DONE

// Containers
#include "DataTypes/Containers/List/List.h"       // DONE
#include "DataTypes/Containers/List/ArrayList.h"  // DONE
#include "DataTypes/Containers/List/LinkedList.h" // DONE

// Utils
#include "Utils/IsPrimitive.h"     // DONE
#include "Utils/Typeof.h"          // DONE
#include "Utils/IsSame.h"          // DONE
#include "Utils/RValueReference.h" // DONE
#include "Utils/Declval.h"         // DONE

namespace SimpleOS
{
  class System
      : implements Concepts::Bootable<Handler::Status>,
        implements Concepts::Executable<Handler::Status>,
        implements Instance::Executors,
        implements Instance::WatchdogTimer,
        implements Instance::Timer0,
        implements Instance::Drivers,
        extends Core::ResetCore,
        extends Time::Delay,
        extends Methods
  {
  public:
    System() = default;
    ~System() = default;
  };
}
#pragma once

// Macros
#include "Macros.h" // TODO Organize System Macros and Hardware Macros

// Concepts
#include "Concepts.h" // DONE

// Interrupts
#include "Interrupt/Watchdog/WatchdogTimer.h" // DONE

// System Methods
#include "System/Methods.h"

// Core's
#include "Native/EEPROM/EECore.h" // DONE Native methods - EEPROM
#include "Native/UART/UARTCore.h" // DONE Native methods - UART
#include "Native/GPIO/GPIOCore.h" // DONE Native methods - GPIO
#include "Native/WDT/WDTCore.h"   // DONE Native methods - WDT

// Hardware
#include "Communication/UART/UART.h" // DONE
#include "Hardware/GPIO/GPIO.h"      // DONE
#include "Hardware/Pin/Pin.h"        // DONE
#include "Memory/EEPROM/EEPROM.h"    // CHECK Check if it needs standardization and if it is complete

// Time
#include "Time/Ticks/Ticks.h"

// Root RAM Allocator
#include "Root/RamAllocator/RamAllocator.h" // DONE
#include "Root/RamAllocator/Heap.h"         // DONE

// Root Task
#include "Root/Task/TaskLifecycle.h"                 // DONE
#include "Root/Task/TaskState.h"                     // DONE
#include "Root/Task/TaskController/TaskController.h" // DONE
#include "Root/Task/TaskProperties/TaskProperties.h" // DONE
#include "Root/Task/Task.h"                          // DONE

// Managers
#include "Manager/MemoryManager/MemoryManager.h" // TODO

// Data types
#include "DataTypes/String/String.h"              // FIX Optimize reducing the use of memory and time of use
#include "DataTypes/Duet.h"                       // CHECK
#include "DataTypes/Containers/List/LinkedList.h" // CHECK
#include "DataTypes/Number.h"                     // TODO Add Increment, Decrement and Bitwise operators

// Operators
#include "Operators/Typeof.h"          // DONE
#include "Operators/IsSame.h"          // DONE
#include "Operators/RValueReference.h" // DONE
#include "Operators/Declval.h"         // DONE

namespace SimpleOS
{
  template <Data::UInt HeapSize>
  class System
      : extends Methods,
        extends Root::RamAllocator<HeapSize>,
        extends Interrupt::WatchdogTimer,
        implements Concepts::Bootable,
        implements Concepts::Executable
  {
  protected:
    static Com::UART serial;
    static Hardware::GPIO gpio;
    static Memory::EEPROM eeprom;

  protected:
    virtual ~System() = default;
  };

  template <Data::UInt HeapSize>
  Com::UART System<HeapSize>::serial;

  template <Data::UInt HeapSize>
  Hardware::GPIO System<HeapSize>::gpio;

  template <Data::UInt HeapSize>
  Memory::EEPROM System<HeapSize>::eeprom;
}
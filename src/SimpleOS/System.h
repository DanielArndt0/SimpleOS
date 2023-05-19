#pragma once

// Macros
#include "Macros.h" // TODO Organizar

// Concepts
#include "Concepts.h" // DONE

// Interrupts
#include "Interrupt/Watchdog/WatchdogTimer.h"

// Core's
#include "Native/EEPROM/EECore.h" // DONE Métodos nativos - EEPROM
#include "Native/UART/UARTCore.h" // DONE Métodos nativos - UART
#include "Native/GPIO/GPIOCore.h" // DONE Métodos nativos - GPIO
#include "Native/WDT/WDTCore.h"   // DONE Métodos nativos - WDT

// Hardware
#include "Communication/UART/UART.h" // DONE
#include "Hardware/GPIO/GPIO.h"      // DONE
#include "Hardware/Pin/Pin.h"        // DONE
#include "Memory/EEPROM/EEPROM.h"    // CHECK Verificar se é preciso padronizar e se está completa

// Time
#include "Time/Ticks/Ticks.h"

// Root RAM Allocator
#include "Root/RamAllocator/RamAllocator.h" // DONE

// Root Task
#include "Root/Task/TaskLifecycle.h"                 // DONE
#include "Root/Task/TaskState.h"                     // DONE
#include "Root/Task/TaskController/TaskController.h" // DONE
#include "Root/Task/TaskProperties/TaskProperties.h" // DONE
#include "Root/Task/Task.h"                          // DONE

// Managers
#include "Manager/MemoryManager/MemoryManager.h" // TODO

// Data types
#include "DataTypes/String/String.h"              // FIX Otimizar reduzindo a utilização de memória e tempo de utilização
#include "DataTypes/Duet.h"                       // CHECK
#include "DataTypes/Containers/List/LinkedList.h" // CHECK
#include "DataTypes/Heap.h"                       // DONE
#include "DataTypes/Number.h"                     // TODO Adicionar operadores de incremento e decremento e logica bitwise

// Operators
#include "Operators/Typeof.h"          // DONE
#include "Operators/IsSame.h"          // DONE
#include "Operators/RValueReference.h" // DONE
#include "Operators/Declval.h"         // DONE

namespace SimpleOS
{
  template <Data::UInt HeapSize>
  class System
      : extends Root::RamAllocator<HeapSize>,
        conceptualize Concepts::Bootable,
        conceptualize Concepts::Executable
  {
  protected:
    static Com::UART serial;
    static Hardware::GPIO gpio;
    static Memory::EEPROM eeprom;
    static Interrupt::WatchdogTimer watchdog;

  protected:
    template <typename T>
    static constexpr T getArgs(void *args, int index = 0) { return reinterpret_cast<T>(reinterpret_cast<void **>(args)[index]); }

  public:
    Data::String systemVersion() { return SYSM_VERSION; }

  protected:
    virtual ~System() = default;
  };

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Interrupt::WatchdogTimer SimpleOS::System<HeapSize>::watchdog;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Com::UART SimpleOS::System<HeapSize>::serial;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Hardware::GPIO SimpleOS::System<HeapSize>::gpio;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Memory::EEPROM SimpleOS::System<HeapSize>::eeprom;
}
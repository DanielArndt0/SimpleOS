#pragma once

// Macros
#include "Macros.h" // TODO Organizar

// Interrupts
#include "SimpleOS/Interrupts.h"

// Concepts
#include "Concepts.h" // DONE

// Core's
#include "Native/EEPROM/EECore.h" // DONE Métodos nativos - EEPROM
#include "Native/UART/UARTCore.h" // DONE Métodos nativos - UART
#include "Native/GPIO/GPIOCore.h" // DONE Métodos nativos - GPIO
#include "Native/WDT/WDTCore.h"   // DONE Métodos nativos - WDT

// Root RAM Allocator
#include "Root/RamAllocator/RamAllocator.h" // DONE

// Root Task
#include "Root/Task/TaskLifecycle.h"                 // DONE
#include "Root/Task/TaskState.h"                     // DONE
#include "Root/Task/TaskController/TaskController.h" // DONE
#include "Root/Task/TaskProperties/TaskProperties.h" // DONE
#include "Root/Task/Task.h"                          // DONE

// Root Ticks
#include "Root/Ticks.h"

// Hardware
#include "Communication/UART/UART.h" // DONE
#include "Hardware/GPIO/GPIO.h"      // DONE
#include "Hardware/Pin/Pin.h"        // DONE

// EEPROM
#include "Memory/EEPROM/EEPROM.h" // CHECK Verificar se é preciso padronizar e se está completa

// Managers
#include "Manager/MemoryManager/MemoryManager.h" // TODO

// Virtual RAM
#include "Others/VirtualRAM.h" // CHECK

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
  class System : extends Root::RamAllocator<HeapSize>
  {
  protected:
    static Com::UART serial;
    static Hardware::GPIO gpio;
    static Memory::EEPROM eeprom;
    Native::WDTCore wdt;

  protected:
    template <typename T>
    static constexpr T getArgs(void *args, int index = 0) { return reinterpret_cast<T>(reinterpret_cast<void **>(args)[index]); }

  public:
    virtual Data::Int startup() = 0;
    virtual Data::Int run() = 0;
    Data::String systemVersion() { return SYSM_VERSION; }

  protected:
    virtual ~System() = default;
  };

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Com::UART SimpleOS::System<HeapSize>::serial;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Hardware::GPIO SimpleOS::System<HeapSize>::gpio;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Memory::EEPROM SimpleOS::System<HeapSize>::eeprom;
}
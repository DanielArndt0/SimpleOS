#pragma once

// Macros
#include "Macros.h" // TODO Organizar

// Root
#include "Root/VRam/VRam.h" // DONE
#include "Root/Task/TaskProperties.h" // BETA

// Core's
#include "Native/EEPROM/EECore.h" // DONE Métodos nativos - EEPROM
#include "Native/UART/UARTCore.h" // DONE Métodos nativos - UART
#include "Native/GPIO/GPIOCore.h" // DONE Métodos nativos - GPIO

// EEPROM
#include "Memory/EEPROM/EEPROM.h" // CHECK Verificar se é preciso padronizar e se está completa

// Hardware
#include "Communication/UART/UART.h" // DONE
#include "Hardware/GPIO/GPIO.h"      // DONE
#include "Hardware/Pin/Pin.h"        // DONE

// Virtual RAM
#include "Others/VirtualRAM.h" // CHECK

// Managers
#include "Manager/MemoryManager/MemoryManager.h"  // TODO

// Data types
#include "DataTypes/String/String.h"              // FIX Otimizar reduzindo a utilização de memória e tempo de utilização
#include "DataTypes/Duet.h"                       // CHECK
#include "DataTypes/Containers/List/LinkedList.h" // CHECK
#include "DataTypes/Heap.h"                       // DONE
#include "DataTypes/Number.h"                     // TODO Adicionar operadores de incremento e decremento e logica bitwise

// Concepts
#include "Concepts.h" // CHECK

// Operators
#include "Operators/Typeof.h"          // DONE
#include "Operators/IsSame.h"          // DONE
#include "Operators/RValueReference.h" // DONE
#include "Operators/Declval.h"         // DONE

namespace SimpleOS
{
  template <Data::UInt HeapSize>
  class System : extends Root::VRam<HeapSize>
  {
  protected:
    static Com::UART serial;
    static Hardware::GPIO gpio;
    static Memory::EEPROM eeprom;

  public:
    virtual Data::Int startup() = 0;
    virtual Data::Int run() = 0;
    Data::String systemVersion() { return SYSM_VERSION; }

  protected:
    ~System() = default;
  };

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Com::UART SimpleOS::System<HeapSize>::serial;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Hardware::GPIO SimpleOS::System<HeapSize>::gpio;

  template <SimpleOS::Data::UInt HeapSize>
  SimpleOS::Memory::EEPROM SimpleOS::System<HeapSize>::eeprom;
}
#pragma once

// Macros
#include "Macros.h" // TODO Organizar

// Root
#include "SimpleOS/Root/VRam.h"

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
#include "Memory/SRAM/Allocator.h" // CHECK

// Managers
#include "Manager/MemoryManager/MemoryManager.h"  // TODO
#include "DataTypes/String/String.h"              // FIX Otimizar reduzindo a utilização de memória e tempo de utilização
#include "DataTypes/Duet.h"                       // CHECK
#include "DataTypes/Containers/List/LinkedList.h" // CHECK
#include "DataTypes/Heap.h"                       // DONE

// Concepts
#include "Concepts.h" // CHECK

// Operators
#include "Operators/Typeof.h" // DONE
#include "Operators/IsSame.h" // DONE

// Fase de testes
#include "DataTypes/StringNew/String.h"

// FIX Biblioteca sequence está muito pesada, padronizar utilizando sistema de concepts
// TODO priorizar a otimização do consumo de memória
// #include "DataTypes/Sequence/List/List.h"         // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/List/LinkedList.h"   // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/List/ArrayList.h"    // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/SimpleContainer.h"   // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/Queue/LinkedQueue.h" // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/Queue/ArrayQueue.h"  // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/Stack/LinkedStack.h" // TODO Padronizar e otimizar
// #include "DataTypes/Sequence/Stack/ArrayStack.h"  // TODO Padronizar e otimizar
// #include "DataTypes/Buffer/Buffer.h" // CHECK Avaliar necessidade da biblioteca
// #include "Addons/EEPROMPartitions/EEPartition.h" // TODO Remontar arquitetura para compatibilizar com sistema de partições
// #include "Addons/EEPROMPartitions/EEProperties/EEProperties.h"
// #include "Addons/Partition/Partition.h"                      // CHECK Verificar se sistema funciona
// #include "Addons/Partition/Properties/PartitionProperties.h" // CHECK Verificar se sistema funciona
// #include "Helper/MemoryHelper.h"

namespace SimpleOS
{
  template <Data::UInt HeapSize>
  class System : extends Root::VRam<HeapSize>
  {
  protected:
    Com::UART serial;
    Hardware::GPIO gpio;
    Memory::EEPROM eeprom;

  public:
    virtual Data::Int startup() = 0;
    virtual Data::Int run() = 0;
    Data::String systemVersion() { return SYSM_VERSION; }

  protected:
    ~System() = default;
  };
}
#pragma once

// Macros
#include "Macros.h"

// EEPROM
#include "Memory/EEPROM/NativeEEPROM.h" // DONE
#include "Memory/EEPROM/EEPROM.h" // CHECK Verificar se é preciso padronizar e se está completa

// RAM
#include "Memory/SRAM/Allocator.h" // CHECK

// Managers
#include "Manager/MemoryManager/MemoryManager.h" // TODO

// Hardware API
#include "Communication/UART/UART.h" // TODO Desenvolver métodos nativos
#include "Hardware/GPIO/GPIO.h"      // TODO Desenvolver métodos nativos

// Data
#include "DataTypes/Object/Object.h" // TODO Adicionar mais métodos nativos de metadados
#include "DataTypes/String/String.h" // FIX Otimizar focando em desempenho de memória e tempo de utilização
#include "DataTypes/Duet.h"                       // DONE
#include "DataTypes/Containers/List/LinkedList.h" // CHECK

// Concepts
#include "Concepts/ComparisonConcept.h" // DONE
#include "Concepts/DefaultConcept.h"    // DONE
#include "Concepts/PrintConcept.h"      // DONE
#include "Concepts/CopyConcept.h"       // DONE

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
  class System final implements Root::Object
  {
  public:
    Data::Int startup();
    Data::Int run();
    Data::String getSystemVersion() { return SYSM_VERSION; }
  };
}
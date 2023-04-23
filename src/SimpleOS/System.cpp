#include "System.h"

using namespace SimpleOS;
using namespace Com;
using namespace Memory;
using namespace Data;
using namespace Operators;
using namespace Hardware;
using namespace Root;
// using namespace Addons;
// using namespace Helpers;

UART Serial;
Allocator<UInt, 64> mem;

Int SimpleOS::System::startup()
{
  Serial.begin(9600);


  
  
  // mem<UInt, 128> mem;
  // mem.malloc(sizeof(unsigned int));
  // Block<UInt> result = mem
  //                          .getBlockList()
  //                          .setDefaultValue(Block<UInt>(nullptr, nullptr, ""))
  //                          .get(0);

  // Serial << (result.id == "" ? "not found" : result.id) << endl;
  // Serial << (result.startAddr == nullptr ? "null" : "not null") << endl;
  // Serial << (result.endAddr == nullptr ? "null" : "not null") << endl;

  Serial << "Memory leak" << endl;
  while (1)
  {
    Serial << "Free Heap: " << mem.getFreeHeap() << " Used heap: " << mem.getUsedHeap() << endl;
    if (mem.malloc(sizeof(UInt)) == nullptr)
      break;
  }

  Serial << endl
         << "Memory trace" << endl;
  mem.getBlockList().setDefaultValue(Block<UInt>(nullptr, nullptr, 0));
  mem
      .getBlockList()
      .foreach (
          [](Block<UInt> &block) -> void
          { Serial << "Id: " << block.id
                   << " Start addr.: " << reinterpret_cast<uintptr_t>(block.startAddr)
                   << " End addr.: " << reinterpret_cast<uintptr_t>(block.endAddr) << endl; });

  Serial << endl
         << "Memory release" << endl;
  mem
      .getBlockList()
      .foreach ([](Block<UInt> &block) -> void
                {
                  Serial << "Free Heap: " << mem.getFreeHeap() << " Used heap: " << mem.getUsedHeap() << endl; 
                  mem.free(block.startAddr, (reinterpret_cast<uintptr_t>(block.endAddr) - reinterpret_cast<uintptr_t>(block.startAddr)) / sizeof(UInt)); });

  
  Serial << endl
         << "Blocks: " << mem.getBlockList().getSize() << endl;
  Serial << "Heap Start: " << reinterpret_cast<uintptr_t>(mem.getHeapStartAddr()) << endl;
  Serial << "Heap End: " << reinterpret_cast<uintptr_t>(mem.getHeapEndAddr()) << endl;
  Serial << "Free Heap: " << mem.getFreeHeap() << " Used heap: " << mem.getUsedHeap() << endl;

  return 0;
}

Int SimpleOS::System::run()
{
  return 0;
}

// TODO Execução geral

//  Sistema:
//   DONE Desenvolvido sistema de Threads;
//   DONE Desenvolvido ThreadManager;
//   DONE ThreadStack automatizada;
//   DONE Configurações de Sistema adicionadas;
//   DONE ThreadManager e Threads remodelados;

//  Periféricos:
//   DONE Desenvolvidas Funções básicas de Tempo;
//   DONE Desenvolvidas Funções básicas de Comunicação serial;
//   DONE Desenvolvidas Funções básicas de Protocolo I2C;
//   DONE Desenvolvidas Funções básicas de EEPROM;
//   DONE Desenvolvidas Funções de Leitura analógica;

//  Tipos:
//   DONE Desenvolvido tipo de dado String;
//   DONE Desenvolvido tipo de dado Vector;
//   DONE Desenvolvido tipo de dado Duet;
//   DONE Desenvolvido tipo de dado LIFO;
//   DONE Desenvolvido tipo de dado FIFO;
//   DONE Desenvolver operador Typeof;
//   DONE Desenvolver operador IsSame;
//   DONE Desenvolver tipo de dado List;

//  EEPROM:
//   DONE Desenvolvido funções WriteString, ReadString e outras para controle de memória.
//   DONE Adicionado funções para escrita de dados primitivos maiores de 1 byte.
//   DONE Otimizado funções da EEPROM;
//   DONE Desenvolver sistema de partições;

//  RAM:
//   DONE Desenvolvido classe para monitorar consumo da RAM;
//   DONE Adicionado metodo para vizualizar stackFrame;

//  Afazeres:
//    TODO Organizar software no geral;
//    TODO Desenvolver gerenciador de memória;
//    TODO Desenvolver programação por eventos de hardware;
//    TODO Desenvolver Sistema de erros com stack trace;

//   Tipos:
//    TODO Desenvolver tipo Tuple;
//    TODO Desenvolver tipo de dado Array;
//    TODO Desenvolver tipo de dado Map;
//    TODO Desenvolver tipo de dado Bitset;
//    TODO Desenvolver tipo de dado UniqueSet;
//    TODO Desenvolver tipo de dado Optional;

//   EEPROM:
//    TODO Otimizar sistema de Get partições;
//    FIX Arrumar biblioteca de partições;

//   String:
//    FIX Corrigir vazamento de memória na função _concat_()
//    TODO Desenvolver um formatador de strings;

//   Serial:
//    TODO Desenvolver StackBuffer Serial;

//   I2C:
//    TODO Otimizar Funções de I2C, adicionando verificações contra erros e buffers virtuais;

//   PWM:
//    TODO Desenvolver Funções de PWM;

//   Interrupções:
//    TODO Adicionar mais funções para configurar interrupções;

//   SSD1306:
//    TODO Adicionar classe fonte;
//    TODO Organizar bibliotecas graficas;
//    TODO Desenvolver funções praticas para posicionamento de strings;
//    TODO Desalocar memoria quando o display for desligado;
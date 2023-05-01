#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Duet.h"
#include "SimpleOS/Macros.h"
#include "Addons/EEPROMPartitions/EEProperties/EEProperties.h"
#include "Memory/EEPROM/EEPROM.h"

/*
   Criação de uma partição:
   - O Nome de uma partição é um caractere que não pode ser nulo.
   - O endereço 1 não pode ser maior ou igual que o endereço 2.
   - O endereço 1 não pode receber um valor menor que 3.
   - O endereço 2 não pode receber um valor maior que 1020.
   - Ponta inicial (Inicio da partição) -> bloco 3 bytes antes do valor passado ao endereço 1.
     - Byte 1 -> Nome da partição.
     - Byte 2 -> Endereço de tamanho partição 1.
     - Byte 3 -> Endereço de tamanho partição 2.
   - Ponta final (Fim da partição) -> bloco 3 bytes depois do valor passado ao endereço 2.
     - Byte 1 -> Endereço de verificação 1.
     - Byte 2 -> Endereço de verificação 2.
     - Byte 3 -> Nome da partição.
   - O Nome será alocado na ponta inicial.
   - A diferença entre o endereço 1 e o endereço 2 é o Tamanho disponível na partição.
   - O tamanho é alocado na ponta inicial.
   - O valor do tamanho será dividido em 2 bytes e alocados respectivamente após a alocação do Nome.
   - O endereço de verificação ficará alocado na ponta final da partição.
   - O valor no endereço de verificação é a soma entre o Tamanho e o Nome.
   - Por fim, o Nome é alocado novamente na ponta final. Sendo o último byte.

   Verificação de ponta inicial à ponta final (inicio ao fim da partição):
   - O inicio da partição SEMPRE começa 3 bytes antes do endereço passado como parâmetro. Tendo assim um offset de 3 bytes.
   - Valor do Offset: 3;
   - Acesso ao endereço do Nome: mem[i];
   - Acesso ao endereço 1 do Tamanho: mem[Nome + 1];
   - Acesso ao endereço 2 do Tamanho: mem[Nome + 2];
   - A concatenação dos valores nos endereços dos tamanhos, retornarão um inteiro com o TamanhoReal.
   - Acesso ao endereço 1 do byte de verificação: mem[(Nome + Offset) + TamanhoReal];
   - Acesso ao endereço 2 do byte de verificação: mem[(Nome + Offset) + (TamanhoReal + 1)];
   - A concatenação dos valores nos endereços dos bytes de verificação, retornarão um inteiro
   com o VerificadorReal.
   - Acesso ao endereço do Nome final: mem[(Nome + Offset) + (TamanhoReal + 2)];
   - O final da partição SEMPRE termina 3 bytes depois do TamanhoReal da da partição;
   - A primeira etapa verifica se a soma entre o Nome e o TamanhoReal correspondem com o valor
   do VerificadorReal.
   - A segunda etapa se o Nome encontrado no final da partição corresponde com o nome no início da partição.

   Verificação de ponta final à ponta inicial(fim ao inicio da partição)
   - Acesso ao endereço 1 do byte de verificação: mem[pos];
   - Acesso ao endereço 2 do byte de verificação: mem[pos + 1];
   - Acesso ao endereço do Nome final: mem[pos + 2];
   - Acesso ao endereço do Nome inicial: mem[((VerificadorReal - Nome) - i) - 3]
   - Acesso ao endereço 1 do Tamanho: mem[((VerificadorReal - Nome) - i) - 2]
   - Acesso ao endereço 2 do Tamanho: mem[((VerificadorReal - Nome) - i) - 1]
   - A concatenação dos valores nos endereços dos bytes de verificação, retornarão um inteiro
   com o VerificadorReal.
   - A concatenação dos valores nos endereços dos tamanhos, retornarão um inteiro com o TamanhoReal.
   - A primeira etapa verifica se a diferença entre o VerificadorReal e o Nome final correspondem com o valor
   do TamanhoReal.
   - A segunda etapa se o Nome encontrado no final da partição corresponde com o nome no início da partição.
 */

namespace SimpleOS
{
  namespace Addons
  {
    class EEPartition
    {
    private:
      bool firstCheck;
      bool secondCheck;
      Data::UInt size;
      Data::UInt checker;

    private:
      Data::Duet<bool, EEProperties> itsStart(Data::UInt addr, Data::UChar *buff);
      Data::Duet<bool, EEProperties> itsBetween(Data::UInt addr, Data::UChar *buff);
      Data::Duet<bool, EEProperties> itsEnd(Data::UInt addr, Data::UChar *buff);
      void _delete_(Data::UInt addr);
      bool _create_(char name, Data::UInt addr0, Data::UInt addr1);
      bool _is_partition_(Data::UInt addr);
      EEProperties _get_partition_(Data::UInt addr);

    public:
      // Delete
      void remove(Data::UInt addr);

      // Create
      bool create(char name, Data::UInt addr0, Data::UInt addr1);

      // Check
      bool isPartition(Data::UInt addr);

      // Get
      EEProperties get(Data::UInt addr);

    public:
      // virtual ~EEPartition() {}
    };
  }
}
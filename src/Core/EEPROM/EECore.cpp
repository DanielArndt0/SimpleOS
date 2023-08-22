#include "EECore.h"

unsigned int SimpleOS::Core::EECore::eeprom_size = HW_EEPROM_SIZE;

void SimpleOS::Core::EECore::eepromClearWrite(unsigned char selectWriteOp, char data, unsigned int addr)
{
  if (addr >= eeprom_size)
    return;
  BIT_WRITE_REG(SREG, SREG_I, false);
  while (BIT_CHECK(EECR, EEPE))
    ;
  while (BIT_CHECK(SPMCSR, SELFPRGEN))
    ;
  BIT_WRITE_REG(EECR, EEPM1, false);
  BIT_WRITE_REG(EECR, EEPM0, false);
  EEAR = addr;
  if (selectWriteOp)
    EEDR = data;
  BIT_WRITE_REG(EECR, EEMPE, true);
  BIT_WRITE_REG(EECR, EEPE, true);
  BIT_WRITE_REG(SREG, SREG_I, true);
}

char SimpleOS::Core::EECore::readChar(unsigned int addr)
{
  if (addr >= eeprom_size)
    return 0x00;
  while (BIT_CHECK(EECR, EEPE))
    ;
  EEAR = addr;
  BIT_WRITE_REG(EECR, EERE, true);
  return EEDR;
}

unsigned int SimpleOS::Core::EECore::size() { return eeprom_size; }
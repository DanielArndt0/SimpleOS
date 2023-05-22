#include "EECore.h"

unsigned int SimpleOS::Native::EECore::eeprom_size = SYSM_EEPROSYSM_SIZE;

void SimpleOS::Native::EECore::eepromClearWrite(unsigned char selectWriteOp, unsigned char data, unsigned int addr)
{
  if (addr >= eeprom_size)
    return;
  SYSM_WRITE_REG(SREG, SREG_I, false);
  while (SYSM_CHECK(EECR, EEPE))
    ;
  while (SYSM_CHECK(SPMCSR, SELFPRGEN))
    ;
  SYSM_WRITE_REG(EECR, EEPM1, false);
  SYSM_WRITE_REG(EECR, EEPM0, false);
  EEAR = addr;
  if (selectWriteOp)
    EEDR = data;
  SYSM_WRITE_REG(EECR, EEMPE, true);
  SYSM_WRITE_REG(EECR, EEPE, true);
  SYSM_WRITE_REG(SREG, SREG_I, true);
}

unsigned char SimpleOS::Native::EECore::readChar(unsigned int addr)
{
  if (addr >= eeprom_size)
    return 0x00;
  while (SYSM_CHECK(EECR, EEPE))
    ;
  EEAR = addr;
  SYSM_WRITE_REG(EECR, EERE, true);
  return EEDR;
}

unsigned int SimpleOS::Native::EECore::size() { return eeprom_size; }
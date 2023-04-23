#include "Memory/EEPROM/NativeEEPROM.h"

SimpleOS::Data::UInt SimpleOS::Native::Memory::EEPROM::eeprom_size = SYSM_EEPROSYSM_SIZE;

void SimpleOS::Native::Memory::EEPROM::eepromClearWrite(SimpleOS::Data::UChar selectWriteOp, SimpleOS::Data::UChar data, SimpleOS::Data::UInt addr)
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

SimpleOS::Data::UChar SimpleOS::Native::Memory::EEPROM::readChar(SimpleOS::Data::UInt addr)
{
  if (addr >= eeprom_size)
    return 0x00;
  while (SYSM_CHECK(EECR, EEPE))
    ;
  EEAR = addr;
  SYSM_WRITE_REG(EECR, EERE, true);
  return EEDR;
}

SimpleOS::Data::UInt SimpleOS::Native::Memory::EEPROM::size() { return eeprom_size; }
#include "Memory/EEPROM/EEPROM.h"

SimpleOS::Data::SimpleString *SimpleOS::Memory::EEPROM::buffer;

unsigned int
SimpleOS::Memory::EEPROM::used_mem(unsigned int addr1, unsigned int addr2)
{
  if (addr1 >= size() && addr2 > size() && addr1 >= addr2)
    return 0x00;
  unsigned int cnt = 0x00;
  for (unsigned int i = addr1; i < addr2; i++)
    if (readChar(i) != 0x00)
      cnt += 0x01;
  return cnt;
}

unsigned int SimpleOS::Memory::EEPROM::used() { return used_mem(0, size()); }

unsigned int SimpleOS::Memory::EEPROM::empty() { return size() - used_mem(0, size()); }

void SimpleOS::Memory::EEPROM::clear(unsigned int addr)
{
  if (addr >= size())
    return;
  eepromClearWrite(0x00, 0x00, addr);
}

void SimpleOS::Memory::EEPROM::clear(unsigned int addr1, unsigned int addr2)
{
  if (addr1 >= addr2 && addr2 >= size())
    return;
  for (unsigned int i = addr1; i < addr2; i++)
    eepromClearWrite(0x00, 0x00, i);
}

void SimpleOS::Memory::EEPROM::deleteBuffer()
{
  SimpleOS::Data::SimpleString *temp = buffer;
  buffer = nullptr;
  delete temp;
}
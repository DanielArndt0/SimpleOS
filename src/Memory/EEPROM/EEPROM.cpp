#include "Memory/EEPROM/EEPROM.h"

SimpleOS::Data::UChar *SimpleOS::Memory::EEPROM::mem_buff = nullptr;

SimpleOS::Data::UInt SimpleOS::Memory::EEPROM::used_mem(SimpleOS::Data::UInt addr1, SimpleOS::Data::UInt addr2)
{
  if (addr1 >= size() && addr2 > size() && addr1 >= addr2)
    return 0x00;
  SimpleOS::Data::UInt cnt = 0x00;
  for (SimpleOS::Data::UInt i = addr1; i < addr2; i++)
    if (readChar(i) != 0x00)
      cnt += 0x01;
  return cnt;
}

SimpleOS::Memory::EEPROM::~EEPROM() { releaseArray(); }

SimpleOS::Data::UInt SimpleOS::Memory::EEPROM::used() { return used_mem(0, size()); }

SimpleOS::Data::UInt SimpleOS::Memory::EEPROM::empty() { return size() - used_mem(0, size()); }

void SimpleOS::Memory::EEPROM::write(SimpleOS::Data::C_String data, SimpleOS::Data::UInt addr)
{
  if (addr >= size())
    return;
  SimpleOS::Data::UChar len = (SimpleOS::Data::UChar)strlen(data);
  for ( SimpleOS::Data::UInt i = 0; i <= len; i++)
    eepromClearWrite(0x01, data[i], addr + i);
}

void SimpleOS::Memory::EEPROM::write(const SimpleOS::Data::String &data, SimpleOS::Data::UInt addr) { write(data.c_str(), addr); }

SimpleOS::Data::String SimpleOS::Memory::EEPROM::readString(SimpleOS::Data::UInt addr)
{
  if (addr >= size())
    return "";
  Data::String str;
  Data::UChar currentChar = 0;
  for (Data::UInt i = 0; (currentChar = readChar(addr + i)) != 0x00; i++)
    str += currentChar;
  return str;
}

void SimpleOS::Memory::EEPROM::free(SimpleOS::Data::UInt addr)
{
  if (addr >= size())
    return;
  eepromClearWrite(0x00, 0x00, addr);
}

void SimpleOS::Memory::EEPROM::free(SimpleOS::Data::UInt addr1, SimpleOS::Data::UInt addr2)
{
  if (addr1 >= addr2 && addr2 >= size())
    return;
  for (SimpleOS::Data::UInt i = addr1; i < addr2; i++)
    eepromClearWrite(0x00, 0x00, i);
}

// void SimpleOS::Memory::EEPROM::commitArray(SimpleOS::Data::Buffer &buffer)
// {
//   for (SimpleOS::Data::UInt i = 0; i < size(); i++)
//     eepromClearWrite(0x01, buffer.read<Data::UChar>(i), i);
//   releaseArray();
// }

SimpleOS::Data::UChar *SimpleOS::Memory::EEPROM::toArray(SimpleOS::Data::UInt addr1, SimpleOS::Data::UInt addr2)
{
  if (addr1 >= addr2 && addr2 > size())
    return nullptr;
  if (mem_buff == nullptr)
    mem_buff = new SimpleOS::Data::UChar[size()];
  for ( SimpleOS::Data::UInt i = addr1; i < addr2; i++)
    mem_buff[i] = readChar(i);
  return mem_buff;
}

SimpleOS::Data::UChar *SimpleOS::Memory::EEPROM::toArray() { return toArray(0, size());}

void SimpleOS::Memory::EEPROM::releaseArray()
{
  if (mem_buff)
  {
    delete[] mem_buff;
    mem_buff = nullptr;
  }
}
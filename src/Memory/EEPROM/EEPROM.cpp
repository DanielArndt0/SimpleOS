#include "Memory/EEPROM/EEPROM.h"

unsigned char *SimpleOS::Memory::EEPROM::mem_buff = nullptr;

unsigned int SimpleOS::Memory::EEPROM::used_mem(unsigned int addr1, unsigned int addr2)
{
  if (addr1 >= size() && addr2 > size() && addr1 >= addr2)
    return 0x00;
  unsigned int cnt = 0x00;
  for (unsigned int i = addr1; i < addr2; i++)
    if (readChar(i) != 0x00)
      cnt += 0x01;
  return cnt;
}

SimpleOS::Memory::EEPROM::~EEPROM() { releaseArray(); }

unsigned int SimpleOS::Memory::EEPROM::used() { return used_mem(0, size()); }

unsigned int SimpleOS::Memory::EEPROM::empty() { return size() - used_mem(0, size()); }

void SimpleOS::Memory::EEPROM::write(const char* data, unsigned int addr)
{
  if (addr >= size())
    return;
  unsigned char len = (unsigned char)strlen(data);
  for ( unsigned int i = 0; i <= len; i++)
    eepromClearWrite(0x01, data[i], addr + i);
}

void SimpleOS::Memory::EEPROM::write(const SimpleOS::Data::String &data, unsigned int addr) { write(data.c_str(), addr); }

SimpleOS::Data::String SimpleOS::Memory::EEPROM::readString(unsigned int addr)
{
  if (addr >= size())
    return "";
  Data::String str;
  unsigned char currentChar = 0;
  for (unsigned int i = 0; (currentChar = readChar(addr + i)) != 0x00; i++)
    str += currentChar;
  return str;
}

void SimpleOS::Memory::EEPROM::free(unsigned int addr)
{
  if (addr >= size())
    return;
  eepromClearWrite(0x00, 0x00, addr);
}

void SimpleOS::Memory::EEPROM::free(unsigned int addr1, unsigned int addr2)
{
  if (addr1 >= addr2 && addr2 >= size())
    return;
  for (unsigned int i = addr1; i < addr2; i++)
    eepromClearWrite(0x00, 0x00, i);
}

// void SimpleOS::Memory::EEPROM::commitArray(SimpleOS::Data::Buffer &buffer)
// {
//   for (unsigned int i = 0; i < size(); i++)
//     eepromClearWrite(0x01, buffer.read<unsigned char>(i), i);
//   releaseArray();
// }

unsigned char *SimpleOS::Memory::EEPROM::toArray(unsigned int addr1, unsigned int addr2)
{
  if (addr1 >= addr2 && addr2 > size())
    return nullptr;
  if (mem_buff == nullptr)
    mem_buff = new unsigned char[size()];
  for ( unsigned int i = addr1; i < addr2; i++)
    mem_buff[i] = readChar(i);
  return mem_buff;
}

unsigned char *SimpleOS::Memory::EEPROM::toArray() { return toArray(0, size());}

void SimpleOS::Memory::EEPROM::releaseArray()
{
  if (mem_buff)
  {
    delete[] mem_buff;
    mem_buff = nullptr;
  }
}
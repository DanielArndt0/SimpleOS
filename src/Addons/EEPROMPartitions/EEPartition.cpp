#include "Addons/EEPROMPartitions/EEPartition.h"

SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> SimpleOS::Addons::EEPartition::itsStart(Data::UInt addr, Data::UChar *buff)
{
  Data::UInt offset_ = 3;
  Data::UInt part_addr_ = addr - offset_;
  if (buff[part_addr_] && (buff[part_addr_ + 1] || buff[part_addr_ + 2]))
  {
    size = buff[part_addr_ + 1] | buff[part_addr_ + 2] << 8;
    checker = buff[(part_addr_ + offset_) + size] | buff[(part_addr_ + offset_) + (size + 1)] << 8;
    firstCheck = (buff[part_addr_] + size) == checker;
    secondCheck = buff[part_addr_] == buff[(part_addr_ + offset_) + (size + 2)];
    if (firstCheck && secondCheck)
      return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(true, SimpleOS::Addons::EEProperties(buff[part_addr_], addr, addr + size));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(false, SimpleOS::Addons::EEProperties(0x00, 0x00, 0x00));
}

SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> SimpleOS::Addons::EEPartition::itsBetween(Data::UInt addr, Data::UChar *buff)
{
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> _start_;
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> _end_;
  for (Data::UInt i = 0; i < SimpleOS::Memory::EEPROM::size(); i++)
  {
    _start_ = itsStart(i, buff);
    _end_ = itsEnd(i, buff);
    if (_start_.getFirst())
      if (_start_.getSecond().getStartAddr() < addr && _start_.getSecond().getEndAddr() > addr)
        return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(true, SimpleOS::Addons::EEProperties(_start_.getSecond().getName(), _start_.getSecond().getStartAddr(), _start_.getSecond().getEndAddr()));
    if (_end_.getFirst())
      if (_end_.getSecond().getStartAddr() < addr && _end_.getSecond().getEndAddr() > addr)
        return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(true, SimpleOS::Addons::EEProperties(_end_.getSecond().getName(), _end_.getSecond().getStartAddr(), _end_.getSecond().getEndAddr()));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(false, SimpleOS::Addons::EEProperties(0x00, 0x00, 0x00));
}

SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> SimpleOS::Addons::EEPartition::itsEnd(Data::UInt addr, Data::UChar *buff)
{
  if (buff[addr] && (buff[addr + 1] || buff[addr + 2]))
  {
    checker = buff[addr] | buff[addr + 1] << 8;
    size = buff[(addr - (checker - buff[addr + 2])) - 2] | buff[(addr - (checker - buff[addr + 2])) - 1] << 8;
    firstCheck = (checker - buff[addr + 2]) == size;
    secondCheck = buff[addr + 2] == buff[(addr - size) - 3];
    if (firstCheck && secondCheck)
      return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(true, SimpleOS::Addons::EEProperties(buff[addr + 2], addr - size, addr));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties>::create(false, SimpleOS::Addons::EEProperties(0x00, 0x00, 0x00));
}

void SimpleOS::Addons::EEPartition::_delete_(Data::UInt addr)
{
  SimpleOS::Addons::EEProperties props = _get_partition_(addr);
  if (props.getSize() > 0)
    SimpleOS::Memory::EEPROM::free(props.getStartAddr() - 3, props.getEndAddr() + 3);
}

bool SimpleOS::Addons::EEPartition::_create_(char name, Data::UInt addr0, Data::UInt addr1)
{
  if (!name && addr0 >= addr1 && addr0 < 3 && addr1 > 1020)
    return false;

  // name : 67
  Data::UInt _diff_ = addr1 - addr0; // 47
  Data::UInt _check_digit_ = name + _diff_; //114
  SimpleOS::Memory::EEPROM::write(name, addr0 - 3); // endereço 0, nome
  SimpleOS::Memory::EEPROM::write(_diff_, addr0 - 2); // endereço 1 e 2, tamanho
  SimpleOS::Memory::EEPROM::write(_check_digit_, addr1); // endereço 50 e 51, digito verificador
  SimpleOS::Memory::EEPROM::write(name, addr1 + 2); // endereco 52, nome
  for (Data::UInt i = addr0; i < addr1; i++) // dados escritos do endereço 3 até o 49
    SimpleOS::Memory::EEPROM::write((Data::UChar)111, i);
  return true;
}

bool SimpleOS::Addons::EEPartition::_is_partition_(Data::UInt addr)
{
  Data::UChar *mem = SimpleOS::Memory::EEPROM::toArray(0, SimpleOS::Memory::EEPROM::size());
  bool is_part = itsStart(addr, mem).getFirst() || itsBetween(addr, mem).getFirst() || itsEnd(addr, mem).getFirst() ? true : false;
  SimpleOS::Memory::EEPROM::releaseArray();
  return is_part;
}

SimpleOS::Addons::EEProperties SimpleOS::Addons::EEPartition::_get_partition_(Data::UInt addr)
{
  Data::UChar *mem = SimpleOS::Memory::EEPROM::toArray(0, SimpleOS::Memory::EEPROM::size());
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> _start_ = itsStart(addr, mem);
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::EEProperties> _final_ = itsEnd(addr, mem);
  SimpleOS::Memory::EEPROM::releaseArray();
  return _start_.getFirst() ? _start_.getSecond() : (_final_.getFirst() ? _final_.getSecond() : _final_.getSecond());
}

bool SimpleOS::Addons::EEPartition::create(char name, Data::UInt addr0, Data::UInt addr1) { return _create_(name, addr0, addr1); }

void SimpleOS::Addons::EEPartition::remove(Data::UInt addr) { return _delete_(addr); }

bool SimpleOS::Addons::EEPartition::isPartition(Data::UInt addr) { return _is_partition_(addr); }

SimpleOS::Addons::EEProperties SimpleOS::Addons::EEPartition::get(Data::UInt addr) { return _get_partition_(addr); }
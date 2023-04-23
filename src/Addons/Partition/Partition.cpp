#include "Addons/Partition/Partition.h"

SimpleOS::Addons::Partition::Partition(SimpleOS::Data::Buffer &Buffer) : buffer(Buffer) {}

SimpleOS::Addons::Partition::~Partition() { buffer.freeBuffer(); }

SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> SimpleOS::Addons::Partition::itsStart(Data::UInt addr)
{
  Data::UInt offset_ = 3;
  Data::UInt part_addr_ = addr - offset_;
  if (buffer.read<Data::UChar>(part_addr_) && (buffer.read<Data::UChar>(part_addr_ + 1) || buffer.read<Data::UChar>(part_addr_ + 2)))
  {
    size = buffer.read<Data::UChar>(part_addr_ + 1) | buffer.read<Data::UChar>(part_addr_ + 2) << 8;
    checker = buffer.read<Data::UChar>((part_addr_ + offset_) + size) | buffer.read<Data::UChar>((part_addr_ + offset_) + (size + 1)) << 8;
    firstCheck = (buffer.read<Data::UChar>(part_addr_) + size) == checker;
    secondCheck = buffer.read<Data::UChar>(part_addr_) == buffer.read<Data::UChar>((part_addr_ + offset_) + (size + 2));
    if (firstCheck && secondCheck)
      return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(true, SimpleOS::Addons::PartitionProperties(buffer.read<Data::UInt>(part_addr_), addr, addr + size));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(false, SimpleOS::Addons::PartitionProperties(0x00, 0x00, 0x00));
}

SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> SimpleOS::Addons::Partition::itsBetween(Data::UInt addr)
{
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> _start_;
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> _end_;
  for (Data::UInt i = 0; i < buffer.size(); i++)
  {
    _start_ = itsStart(i);
    _end_ = itsEnd(i);
    if (_start_.getFirst())
      if (_start_.getSecond().startAddr() < addr && _start_.getSecond().endAddr() > addr)
        return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(true, SimpleOS::Addons::PartitionProperties(_start_.getSecond().name(), _start_.getSecond().startAddr(), _start_.getSecond().endAddr()));
    if (_end_.getFirst())
      if (_end_.getSecond().startAddr() < addr && _end_.getSecond().endAddr() > addr)
        return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(true, SimpleOS::Addons::PartitionProperties(_end_.getSecond().name(), _end_.getSecond().startAddr(), _end_.getSecond().endAddr()));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(false, SimpleOS::Addons::PartitionProperties(0x00, 0x00, 0x00));
}

SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> SimpleOS::Addons::Partition::itsEnd(Data::UInt addr)
{
  if (buffer.read<Data::UChar>(addr) && (buffer.read<Data::UChar>(addr + 1) || buffer.read<Data::UChar>(addr + 2)))
  {
    checker = buffer.read<Data::UChar>(addr) | buffer.read<Data::UChar>(addr + 1) << 8;
    size = buffer.read<Data::UChar>((addr - (checker - buffer.read<Data::UChar>(addr + 2))) - 2) | buffer.read<Data::UChar>((addr - (checker - buffer.read<Data::UChar>(addr + 2))) - 1) << 8;
    firstCheck = (checker - buffer.read<Data::UChar>(addr + 2)) == size;
    secondCheck = buffer.read<Data::UChar>(addr + 2) == buffer.read<Data::UChar>((addr - size) - 3);
    if (firstCheck && secondCheck)
      return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(true, SimpleOS::Addons::PartitionProperties(buffer.read<Data::UChar>(addr + 2), addr - size, addr));
  }
  return SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties>::create(false, SimpleOS::Addons::PartitionProperties(0x00, 0x00, 0x00));
}

void SimpleOS::Addons::Partition::_delete_(Data::UInt addr)
{
  SimpleOS::Addons::PartitionProperties props = _get_partition_(addr);
  if (props.size() > 0)
    for (SimpleOS::Data::UInt i = props.startAddr() - 3; i < props.endAddr() + 3; i++)
      buffer.write(0, i);
}

bool SimpleOS::Addons::Partition::_create_(Data::Char name, Data::UInt addr0, Data::UInt addr1)
{
  if (!name && addr0 >= addr1 && addr0 < 3 && addr1 > 1020)
    return false;

  Data::UInt _diff_ = addr1 - addr0;
  Data::UInt _check_digit_ = name + _diff_;
  buffer.write(name, addr0 - 3);
  buffer.write(_diff_, addr0 - 2);
  buffer.write(_check_digit_, addr1);
  buffer.write(name, addr1 + 2);
  for (Data::UInt i = addr0; i < addr1; i++)
    buffer.write((Data::UChar)111, i);
  return true;
}

bool SimpleOS::Addons::Partition::_is_partition_(Data::UInt addr)
{
  bool is_part = itsStart(addr).getFirst() || itsBetween(addr).getFirst() || itsEnd(addr).getFirst() ? true : false;
  return is_part;
}

SimpleOS::Addons::PartitionProperties SimpleOS::Addons::Partition::_get_partition_(Data::UInt addr)
{
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> _start_ = itsStart(addr);
  SimpleOS::Data::Duet<bool, SimpleOS::Addons::PartitionProperties> _final_ = itsEnd(addr);
  return _start_.getFirst() ? _start_.getSecond() : (_final_.getFirst() ? _final_.getSecond() : _final_.getSecond());
}

bool SimpleOS::Addons::Partition::create(char name, Data::UInt addr0, Data::UInt addr1) { return _create_(name, addr0, addr1); }

void SimpleOS::Addons::Partition::remove(Data::UInt addr) { return _delete_(addr); }

bool SimpleOS::Addons::Partition::isPartition(Data::UInt addr) { return _is_partition_(addr); }

SimpleOS::Addons::PartitionProperties SimpleOS::Addons::Partition::get(Data::UInt addr) { return _get_partition_(addr); }
#include "Addons/Partition/Properties/PartitionProperties.h"

SimpleOS::Addons::PartitionProperties::PartitionProperties() {}

SimpleOS::Addons::PartitionProperties::PartitionProperties(SimpleOS::Data::Char name, SimpleOS::Data::ULong addr_start, SimpleOS::Data::ULong addr_final) : _name(name), addr_start(addr_start), addr_final(addr_final) {}

SimpleOS::Data::Char SimpleOS::Addons::PartitionProperties::name() { return _name; }

SimpleOS::Data::ULong SimpleOS::Addons::PartitionProperties::size() { return addr_final - addr_start; }

SimpleOS::Data::ULong SimpleOS::Addons::PartitionProperties::startAddr() { return addr_start; }

SimpleOS::Data::ULong SimpleOS::Addons::PartitionProperties::endAddr() { return addr_final; }

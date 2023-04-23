#include "Addons/EEPROMPartitions/EEProperties/EEProperties.h"

SimpleOS::Addons::EEProperties::EEProperties() {}

SimpleOS::Addons::EEProperties::EEProperties(SimpleOS::Data::Char name, SimpleOS::Data::ULong addr_start, SimpleOS::Data::ULong addr_final) : name(name), addr_start(addr_start), addr_final(addr_final) {}

SimpleOS::Data::Char SimpleOS::Addons::EEProperties::getName() { return name; }

SimpleOS::Data::ULong SimpleOS::Addons::EEProperties::getSize() { return addr_final - addr_start; }

SimpleOS::Data::ULong SimpleOS::Addons::EEProperties::getStartAddr() { return addr_start; }

SimpleOS::Data::ULong SimpleOS::Addons::EEProperties::getEndAddr() { return addr_final; }

// SimpleOS::Data::UChar *SimpleOS::Addons::EEProperties::getData() { return __data__; }
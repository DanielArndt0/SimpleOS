#include "Object.h"

SimpleOS::Data::ID SimpleOS::Root::Object::totalIDs = 0;

SimpleOS::Root::Object::Object()
{
  thisID = totalIDs;
  totalIDs++;
}

SimpleOS::Data::ID SimpleOS::Root::Object::objectId() { return thisID; }

SimpleOS::Data::C_String SimpleOS::Root::Object::toString() { return "object"; }

SimpleOS::Data::Hashcode SimpleOS::Root::Object::hashCode() { return thisID; }
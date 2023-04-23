#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/String/String.h"

using namespace SimpleOS;
using namespace Data;

class Person implements Root::Object, conceptualize SimpleOS::Concepts::DefaultConcept<Person>//, conceptualize SimpleOS::Concepts::CopyConcept
{
private:
  String name;
  String surname;

public:
  Person() : name(""), surname("") {}
  Person(String name, String surname) : name(name), surname(surname) {}

  C_String toString() override { return (name += String(" ") += surname).c_str(); }
  Person getDefaultValue() override { return Person("", ""); }
};
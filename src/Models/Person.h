#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/String/String.h"

using namespace SimpleOS;
using namespace Data;

class Person
    : conceptualize SimpleOS::Concepts::Equatable<Person>,
      conceptualize SimpleOS::Concepts::Default<Person>,
      conceptualize SimpleOS::Concepts::Copyable<Person>,
      conceptualize SimpleOS::Concepts::Movable<Person>
{
private:
  String name;
  String surname;
  int age;

public:
  // Constructors
  Person() : name(""), surname(""), age(0) {}
  // Person(const Person &copy) { this->copy(copy); }
  // Person(Person &&move) { this->move(static_cast<Person &&>(move)); }
  Person(String name, String surname, int age) : name(name), surname(surname), age(age) {}
  ~Person() = default;

  // Copyable overrides
  Person &copy(const Person &copy) override
  {
    this->name = copy.name;
    this->surname = copy.surname;
    this->age = copy.age;
    return *this;
  }
  //  Movable overrides
  Person &move(Person &&move) override
  {
    this->name = move.name;
    this->surname = move.surname;
    this->age = move.age;
    move.name = defaultValue().name;
    move.surname = defaultValue().surname;
    move.age = defaultValue().age;
    return *this;
  }

  // Object overrides
  C_String toString() { return (name += String(" ") += surname).c_str(); }

  // Equatable overrides
  bool equals(const Person &cmp) const override { return this->name.equals(cmp.name) && this->surname.equals(cmp.surname) && this->age == cmp.age; }
};
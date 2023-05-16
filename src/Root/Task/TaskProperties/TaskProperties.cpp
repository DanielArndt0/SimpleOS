#include "TaskProperties.h"

SimpleOS::Data::ID SimpleOS::Root::Task::TaskProperties::idCounter;

SimpleOS::Root::Task::TaskProperties::TaskProperties()
    : id(0),
      state(TaskState::created),
      priority(0),
      stackPointer(nullptr),
      stackCounter(0),
      stackSize(0),
      taskFunction(nullptr),
      taskParams(nullptr)
{
}

SimpleOS::Root::Task::TaskProperties::TaskProperties(SimpleOS::Data::UInt priority, SimpleOS::Data::UInt stackSize, void (*taskFunction)(void *), void *params)
    : id(idCounter++),
      state(TaskState::created),
      priority(priority),
      stackPointer(nullptr),
      stackCounter(0),
      stackSize(stackSize),
      taskFunction(taskFunction),
      taskParams(params)
{
}

SimpleOS::Root::Task::TaskProperties::TaskProperties(const SimpleOS::Root::Task::TaskProperties &other)
    : id(idCounter++),
      state(other.state),
      priority(other.priority),
      stackPointer(other.stackPointer),
      stackCounter(other.stackCounter),
      stackSize(other.stackSize),
      taskFunction(other.taskFunction),
      taskParams(other.taskParams)
{
}

SimpleOS::Root::Task::TaskProperties::TaskProperties(SimpleOS::Root::Task::TaskProperties &&other)
    : id(idCounter++),
      state(other.state),
      priority(other.priority),
      stackPointer(other.stackPointer),
      stackCounter(other.stackCounter),
      stackSize(other.stackSize),
      taskFunction(other.taskFunction),
      taskParams(other.taskParams)
{
  other.state = TaskState::null;
  other.priority = 0;
  other.stackPointer = nullptr;
  other.stackCounter = 0;
  other.stackSize = 0;
  other.taskFunction = nullptr;
  other.taskParams = nullptr;
}

SimpleOS::Root::Task::TaskProperties::~TaskProperties()
{
  Root::VRam<SYSM_HEAP_SIZE>::free(stackPointer);
  stackCounter = 0;
  stackSize = 0;
}

SimpleOS::Root::Task::TaskProperties &SimpleOS::Root::Task::TaskProperties::operator=(const SimpleOS::Root::Task::TaskProperties &other)
{
  if (this != &other)
  {
    state = other.state;
    priority = other.priority;
    stackPointer = other.stackPointer;
    stackCounter = other.stackCounter;
    stackSize = other.stackSize;
    taskFunction = other.taskFunction;
    taskParams = other.taskParams;
  }
  return *this;
}

SimpleOS::Root::Task::TaskProperties &SimpleOS::Root::Task::TaskProperties::operator=(SimpleOS::Root::Task::TaskProperties &&other)
{
  if (this != &other)
  {
    state = other.state;
    priority = other.priority;
    stackPointer = other.stackPointer;
    stackCounter = other.stackCounter;
    stackSize = other.stackSize;
    taskFunction = other.taskFunction;
    taskParams = other.taskParams;
    other.state = TaskState::null;
    other.priority = 0;
    other.stackPointer = nullptr;
    other.stackCounter = 0;
    other.stackSize = 0;
    other.taskFunction = nullptr;
    other.taskParams = nullptr;
  }
  return *this;
}
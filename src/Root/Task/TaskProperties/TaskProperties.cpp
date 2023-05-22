#include "TaskProperties.h"

SimpleOS::Data::ID SimpleOS::Root::TaskProperties::idCounter;

SimpleOS::Root::TaskProperties::TaskProperties()
    : id(0),
      state(TaskState::created),
      priority(0),
      interval(0),
      remainingTime(0),
      stackPointer(nullptr),
      stackCounter(0),
      stackSize(0),
      taskFunction(nullptr),
      taskParams(nullptr)
{
}

SimpleOS::Root::TaskProperties::TaskProperties(unsigned int priority, unsigned int stackSize, unsigned int interval, void (*taskFunction)(void *), void *params)
    : id(idCounter++),
      state(TaskState::created),
      priority(priority),
      interval(interval),
      remainingTime(interval),
      stackPointer(nullptr),
      stackCounter(0),
      stackSize(stackSize),
      taskFunction(taskFunction),
      taskParams(params)
{
}

SimpleOS::Root::TaskProperties::TaskProperties(const SimpleOS::Root::TaskProperties &other)
    : id(idCounter++),
      state(other.state),
      priority(other.priority),
      interval(other.interval),
      remainingTime(other.remainingTime),
      stackPointer(other.stackPointer),
      stackCounter(other.stackCounter),
      stackSize(other.stackSize),
      taskFunction(other.taskFunction),
      taskParams(other.taskParams)
{
}

SimpleOS::Root::TaskProperties::TaskProperties(SimpleOS::Root::TaskProperties &&other)
    : id(idCounter++),
      state(other.state),
      priority(other.priority),
      interval(other.interval),
      remainingTime(other.remainingTime),
      stackPointer(other.stackPointer),
      stackCounter(other.stackCounter),
      stackSize(other.stackSize),
      taskFunction(other.taskFunction),
      taskParams(other.taskParams)
{
  other.state = TaskState::null;
  other.priority = 0;
  other.interval = 0;
  other.remainingTime = 0;
  other.stackPointer = nullptr;
  other.stackCounter = 0;
  other.stackSize = 0;
  other.taskFunction = nullptr;
  other.taskParams = nullptr;
}

SimpleOS::Root::TaskProperties::~TaskProperties()
{
  Root::RamAllocator<SYSM_HEAP_SIZE>::free(stackPointer);
  stackCounter = 0;
  stackSize = 0;
}

SimpleOS::Root::TaskProperties &SimpleOS::Root::TaskProperties::operator=(const SimpleOS::Root::TaskProperties &other)
{
  if (this != &other)
  {
    state = other.state;
    priority = other.priority;
    interval = other.interval;
    remainingTime = other.remainingTime;
    stackPointer = other.stackPointer;
    stackCounter = other.stackCounter;
    stackSize = other.stackSize;
    taskFunction = other.taskFunction;
    taskParams = other.taskParams;
  }
  return *this;
}

SimpleOS::Root::TaskProperties &SimpleOS::Root::TaskProperties::operator=(SimpleOS::Root::TaskProperties &&other)
{
  if (this != &other)
  {
    state = other.state;
    priority = other.priority;
    interval = other.interval;
    remainingTime = other.remainingTime;
    stackPointer = other.stackPointer;
    stackCounter = other.stackCounter;
    stackSize = other.stackSize;
    taskFunction = other.taskFunction;
    taskParams = other.taskParams;
    other.state = TaskState::null;
    other.priority = 0;
    other.interval = 0;
    other.remainingTime = 0;
    other.stackPointer = nullptr;
    other.stackCounter = 0;
    other.stackSize = 0;
    other.taskFunction = nullptr;
    other.taskParams = nullptr;
  }
  return *this;
}
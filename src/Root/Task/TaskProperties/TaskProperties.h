#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/Typedefs.h"
#include "Root/Task/TaskState.h"
#include "Root/RamAllocator/RamAllocator.h"

namespace SimpleOS
{
  namespace Root
  {
    class TaskProperties // TODO Desenvolver stack
    {
    private:
      static Data::ID idCounter;

    public:
      Data::ID id;
      TaskState state;
      Data::UInt priority;
      Data::UInt interval;
      Data::UInt remainingTime;
      Data::UChar *stackPointer;
      Data::UInt stackCounter;
      Data::UInt stackSize;
      void (*taskFunction)(void *);
      void *taskParams;

    public:
      TaskProperties();
      TaskProperties(Data::UInt priority, Data::UInt stackSize, Data::UInt interval, void (*taskFunction)(void *), void *params);
      TaskProperties(const TaskProperties &other);
      TaskProperties(TaskProperties &&other);

    public:
      TaskProperties &operator=(const TaskProperties &other);
      TaskProperties &operator=(TaskProperties &&other);

    public:
      ~TaskProperties();
    };
  } // namespace Root
} // namespace SimpleOS

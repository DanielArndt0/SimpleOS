#pragma once
#include "System/Base.h"
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
      unsigned int priority;
      unsigned int interval;
      unsigned int remainingTime;
      unsigned char *stackPointer;
      unsigned int stackCounter;
      unsigned int stackSize;
      void (*taskFunction)(void *);
      void *taskParams;

    public:
      TaskProperties();
      TaskProperties(unsigned int priority, unsigned int stackSize, unsigned int interval, void (*taskFunction)(void *), void *params);
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

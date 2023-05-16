#pragma once
#include "SimpleOS/Base.h"
#include "Root/Task/TaskAdapter/TaskAdapter.h"
#include "Root/Task/TaskProperties/TaskProperties.h"

namespace SimpleOS
{
  namespace Root
  {
    namespace Task
    {
      class TaskExample : implements TaskAdapter
      {
      public:
        TaskExample(const TaskProperties &properties) : TaskAdapter(properties) {}
        virtual ~TaskExample() = default;
      };
    }
  }
}
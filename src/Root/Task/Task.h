#pragma once
#include "System/Base.h"
#include "Root/Task/TaskAdapter/TaskAdapter.h"
#include "Root/Task/TaskProperties/TaskProperties.h"

namespace SimpleOS
{
  namespace Root
  {
    class Task : extends TaskAdapter
    {
    public:
      Task() = default;
      Task(const TaskProperties &properties) : TaskAdapter(properties) {}
      virtual ~Task() = default;

    public:
      TaskProperties &getProperties() { return properties; }
    };
  }
}
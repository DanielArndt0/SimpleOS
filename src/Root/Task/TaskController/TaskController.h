#pragma once
#include "System/Base.h"
#include "DataTypes/Typedefs.h"

#include "Root/Task/TaskAdapter/TaskAdapter.h"
#include "Root/Task/TaskProperties/TaskProperties.h"

namespace SimpleOS
{
  namespace Root
  {
    class TaskController
    {
    private:
      TaskAdapter *taskAdapter;

    public:
      TaskController();
      TaskController(TaskAdapter &adapter);
      virtual ~TaskController() = default;

    public:
      TaskController &setAdapter(TaskAdapter &adapter);

    public:
      void start();
      void restart();
      void pause();
      void resume();
      void stop();
    };
  } // namespace Root
} // namespace SimpleOS

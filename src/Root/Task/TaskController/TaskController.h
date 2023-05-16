#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/Typedefs.h"

#include "Root/Task/TaskAdapter/TaskAdapter.h"
#include "Root/Task/TaskProperties/TaskProperties.h"

namespace SimpleOS
{
  namespace Root
  {
    namespace Task
    {
      class TaskController
      {
      private:
        TaskAdapter &taskAdapter;

      public:
        TaskController(TaskAdapter &adapter);
        virtual ~TaskController() = default;

      public:
        void start();
        void restart();
        void pause();
        void resume();
        void stop();
      };
    } // namespace Task
  }   // namespace Root
} // namespace SimpleOS

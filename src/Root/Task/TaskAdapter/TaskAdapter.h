#pragma once
#include "SimpleOS/Base.h"
#include "Root/Task/TaskProperties/TaskProperties.h"
#include "Root/Task/TaskLifecycle.h"

namespace SimpleOS
{
  namespace Root
  {
    namespace Task
    {
      class TaskAdapter : implements TaskLifecycle
      {
      private:
        TaskProperties properties;

      public:
        TaskAdapter(const TaskProperties &properties);

      public:
        virtual void onCreate();
        virtual void onStart();
        virtual void onResume();
        virtual void onPause();
        virtual void onSuspend();
        virtual void onTerminate();
        virtual void onRestart();

      public:
        TaskProperties &getProperties();

      protected:
        virtual ~TaskAdapter() = default;
      };
    } // namespace Task
  }   // namespace Root
} // namespace SimpleOS

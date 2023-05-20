#pragma once
#include "System/Base.h"
#include "Root/Task/TaskProperties/TaskProperties.h"
#include "Root/Task/TaskLifecycle.h"

namespace SimpleOS
{
  namespace Root
  {
    class TaskAdapter : implements TaskLifecycle
    {
      friend class TaskController;

    protected:
      TaskProperties properties;

    public:
      TaskAdapter() = default;
      TaskAdapter(const TaskProperties &properties);

    protected:
      virtual void onCreate();
      virtual void onStart();
      virtual void onResume();
      virtual void onPause();
      virtual void onSuspend();
      virtual void onTerminate();
      virtual void onRestart();

    protected:
      virtual ~TaskAdapter() = default;
    };
  } // namespace Root
} // namespace SimpleOS

#pragma once

namespace SimpleOS
{
  namespace Root
  {
    namespace Task
    {
      class TaskLifecycle
      {
      public:
        virtual void onCreate() = 0;
        virtual void onStart() = 0;
        virtual void onResume() = 0;
        virtual void onPause() = 0;
        virtual void onSuspend() = 0;
        virtual void onTerminate() = 0;
        virtual void onRestart() = 0;

      protected:
        virtual ~TaskLifecycle() = default;
      };
    } // namespace Task
  }   // namespace Root
} // namespace SimpleOS

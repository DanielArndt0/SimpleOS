#include "TaskController.h"

SimpleOS::Root::Task::TaskController::TaskController(SimpleOS::Root::Task::TaskAdapter &adapter) : taskAdapter(adapter) { this->taskAdapter.onCreate(); }

void SimpleOS::Root::Task::TaskController::start()
{
  taskAdapter.getProperties().state = TaskState::starting;
  taskAdapter.onStart();
  taskAdapter.getProperties().state = TaskState::started;

  this->resume();
}

void SimpleOS::Root::Task::TaskController::restart()
{
  taskAdapter.getProperties().state = TaskState::restarting;
  taskAdapter.onRestart();
  taskAdapter.getProperties().state = TaskState::restarted;

  this->start();
}

void SimpleOS::Root::Task::TaskController::pause()
{
  taskAdapter.getProperties().state = TaskState::pausing;
  taskAdapter.onPause();
  taskAdapter.getProperties().state = TaskState::paused;
}

void SimpleOS::Root::Task::TaskController::resume()
{
  taskAdapter.getProperties().state = TaskState::resuming;
  taskAdapter.onResume();
  taskAdapter.getProperties().state = TaskState::resumed;
}

void SimpleOS::Root::Task::TaskController::stop()
{
  taskAdapter.getProperties().state = TaskState::suspending;
  taskAdapter.onSuspend();
  taskAdapter.getProperties().state = TaskState::suspended;

  taskAdapter.getProperties().state = TaskState::terminating;
  taskAdapter.onTerminate();
  taskAdapter.getProperties().state = TaskState::terminated;
}
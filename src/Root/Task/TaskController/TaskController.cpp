#include "TaskController.h"

SimpleOS::Root::TaskController::TaskController() : taskAdapter(nullptr) {}

SimpleOS::Root::TaskController::TaskController(SimpleOS::Root::TaskAdapter &adapter) : taskAdapter(&adapter) { this->taskAdapter->onCreate(); }

SimpleOS::Root::TaskController &SimpleOS::Root::TaskController::setAdapter(SimpleOS::Root::TaskAdapter &adapter)
{
  this->taskAdapter = &adapter;
  return *this;
}

void SimpleOS::Root::TaskController::start()
{
  if (taskAdapter == nullptr)
    return;
  taskAdapter->properties.state = TaskState::starting;
  taskAdapter->onStart();
  taskAdapter->properties.state = TaskState::started;

  this->resume();
}

void SimpleOS::Root::TaskController::restart()
{
  if (taskAdapter == nullptr)
    return;
  taskAdapter->properties.state = TaskState::restarting;
  taskAdapter->onRestart();
  taskAdapter->properties.state = TaskState::restarted;

  this->start();
}

void SimpleOS::Root::TaskController::pause()
{
  if (taskAdapter == nullptr)
    return;
  taskAdapter->properties.state = TaskState::pausing;
  taskAdapter->onPause();
  taskAdapter->properties.state = TaskState::paused;
}

void SimpleOS::Root::TaskController::resume()
{
  if (taskAdapter == nullptr)
    return;
  taskAdapter->properties.state = TaskState::resuming;
  taskAdapter->onResume();
  taskAdapter->properties.state = TaskState::resumed;
}

void SimpleOS::Root::TaskController::stop()
{
  if (taskAdapter == nullptr)
    return;
  taskAdapter->properties.state = TaskState::suspending;
  taskAdapter->onSuspend();
  taskAdapter->properties.state = TaskState::suspended;

  taskAdapter->properties.state = TaskState::terminating;
  taskAdapter->onTerminate();
  taskAdapter->properties.state = TaskState::terminated;
}
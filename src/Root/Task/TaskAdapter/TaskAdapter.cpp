#include "TaskAdapter.h"

SimpleOS::Root::Task::TaskAdapter::TaskAdapter(const SimpleOS::Root::Task::TaskProperties &properties) : properties(properties) {}

void SimpleOS::Root::Task::TaskAdapter::onCreate() {}
void SimpleOS::Root::Task::TaskAdapter::onStart() {}
void SimpleOS::Root::Task::TaskAdapter::onResume() { properties.taskFunction(properties.taskParams); }
void SimpleOS::Root::Task::TaskAdapter::onPause() {}
void SimpleOS::Root::Task::TaskAdapter::onRestart() {}
void SimpleOS::Root::Task::TaskAdapter::onSuspend() {}
void SimpleOS::Root::Task::TaskAdapter::onTerminate() {}

SimpleOS::Root::Task::TaskProperties &SimpleOS::Root::Task::TaskAdapter::getProperties() { return properties; }
#include "TaskAdapter.h"

SimpleOS::Root::TaskAdapter::TaskAdapter(const SimpleOS::Root::TaskProperties &properties) : properties(properties) {}

void SimpleOS::Root::TaskAdapter::onCreate() {}
void SimpleOS::Root::TaskAdapter::onStart() {}
void SimpleOS::Root::TaskAdapter::onResume() { properties.taskFunction(properties.taskParams); }
void SimpleOS::Root::TaskAdapter::onPause() {}
void SimpleOS::Root::TaskAdapter::onRestart() {}
void SimpleOS::Root::TaskAdapter::onSuspend() {}
void SimpleOS::Root::TaskAdapter::onTerminate() {}
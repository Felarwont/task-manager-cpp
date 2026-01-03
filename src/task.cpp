#include <task.hpp>
#include <string>

std::string Task::getTitle() { return title_; }

bool Task::isDone() { return done_; }

void Task::complete() { done_ = true; }
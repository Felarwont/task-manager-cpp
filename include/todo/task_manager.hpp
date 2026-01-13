#pragma once

#include <vector>
#include <string>

#include "todo/task.hpp"
#include "todo/task_info.hpp"

class TaskManager {
public:
    void addTask(const std::string title);
    void removeTasks(size_t index);
    void completeTask(size_t index);
    TaskInfo getTaskInfo(size_t index);
    std::vector<TaskInfo> getAllTaskInfo();
private:
    std::vector<Task> tasks;
};
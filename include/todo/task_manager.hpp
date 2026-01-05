#pragma once

#include <vector>
#include <string>
#include <todo/task.hpp>
#include <todo/task_info.hpp>

class TaskManager {
public:
    void addTask(const std::string title);
    void removeTasks(uint index);
    void completeTask(uint index);
    TaskInfo getTaskInfo(uint index);
    std::vector<TaskInfo> getAllTaskInfo();
private:
    std::vector<Task> tasks;
};
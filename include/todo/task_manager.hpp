#pragma once

#include <vector>
#include <string>
#include <todo/task.hpp>
#include <todo/task_info.hpp>

class TaskManager {
public:
    void addTask(const std::string title);
    void printTasks();
    void removeTasks(int index);
    void completeTask(int index);
    TaskInfo getTaskInfo(int index);
private:
    std::vector<Task> tasks;
};
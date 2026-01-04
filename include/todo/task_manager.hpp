#pragma once

#include <vector>
#include <string>
#include <todo/task.hpp>

class TaskManager {
public:
    void addTask(const std::string title);
    void printTasks();
    void removeTasks(int index);
    void completeTask(int index);
    Task* getTask(int index);
private:
    std::vector<Task> tasks;
};
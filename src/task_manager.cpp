#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "todo/task_manager.hpp"
#include "todo/task.hpp"

void TaskManager::addTask(const std::string title) { tasks.push_back(Task(title)); }

void TaskManager::removeTasks(uint index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks.erase(tasks.begin() + index - 1);
}

void TaskManager::completeTask(uint index) {
    if (index - 1 > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks[index - 1].complete();
}

TaskInfo TaskManager::getTaskInfo(uint index) {
    if (index - 1 > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    return TaskInfo{tasks[index - 1].getTitle(), tasks[index - 1].isDone(), index};
}

std::vector<TaskInfo> TaskManager::getAllTaskInfo() {
    std::vector<TaskInfo> info;
    for (uint i = 0; i < tasks.size(); i++) {
        info.push_back(TaskInfo{tasks[i].getTitle(), tasks[i].isDone(), i + 1});
    }
    return info;
}
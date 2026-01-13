#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "todo/task_manager.hpp"
#include "todo/task.hpp"

void TaskManager::addTask(const std::string title) { tasks.push_back(Task(title)); }

void TaskManager::removeTasks(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks.erase(tasks.begin() + index);
}

void TaskManager::completeTask(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks[index].complete();
}

TaskInfo TaskManager::getTaskInfo(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    return TaskInfo{tasks[index].getTitle(), tasks[index].isDone(), index};
}

std::vector<TaskInfo> TaskManager::getAllTaskInfo() {
    std::vector<TaskInfo> info;
    for (size_t i = 0; i < tasks.size(); i++) {
        info.push_back(TaskInfo{tasks[i].getTitle(), tasks[i].isDone(), i});
    }
    return info;
}
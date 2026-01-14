#include <stdexcept>
#include <string>
#include <vector>

#include "todo/task_manager.hpp"
#include "todo/task.hpp"

void todo::TaskManager::addTask(const std::string title) { tasks.push_back(Task(title)); }

void todo::TaskManager::removeTask(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks.erase(tasks.begin() + index);
}

void todo::TaskManager::completeTask(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks[index].complete();
}

void todo::TaskManager::deleteCompleted() {
    for (int i = tasks.size() - 1; i >= 0; i--) {
        if (tasks[i].isDone()) {
            removeTask(i);
        }
    }
}

todo::TaskInfo todo::TaskManager::getTaskInfo(size_t index) {
    if (index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    return TaskInfo{tasks[index].getTitle(), tasks[index].isDone(), index};
}

std::vector<todo::TaskInfo> todo::TaskManager::getAllTaskInfo() {
    std::vector<todo::TaskInfo> info;
    for (size_t i = 0; i < tasks.size(); i++) {
        info.push_back(TaskInfo{tasks[i].getTitle(), tasks[i].isDone(), i});
    }
    return info;
}
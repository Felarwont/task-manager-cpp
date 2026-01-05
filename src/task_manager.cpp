#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <todo/task_manager.hpp>
#include <todo/task.hpp>

void TaskManager::addTask(const std::string title) { tasks.push_back(Task(title)); }

void TaskManager::printTasks() {
    if (tasks.size() == 0) {
        std::cout << "The task list is empty. Enjoy!" << std::endl;
        return;
    }
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ".\t" << tasks[i].getTitle() << '\t' << ((tasks[i].isDone()) ? "✓" : "✘") << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void TaskManager::removeTasks(int index) {
    if (index - 1 < 0 || index > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks.erase(tasks.begin() + index - 1);
}

void TaskManager::completeTask(int index) {
    if (index - 1 < 0 || index - 1 > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    tasks[index - 1].complete();
}

TaskInfo TaskManager::getTaskInfo(int index) {
    if (index - 1 < 0 || index - 1 > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    return TaskInfo{tasks[index - 1].getTitle(), tasks[index - 1].isDone()};
}

std::vector<TaskInfo> TaskManager::getAllTaskInfo() {
    std::vector<TaskInfo> info;
    for (auto& task : tasks) {
        info.push_back(TaskInfo{task.getTitle(), task.isDone()});
    }
    return info;
}
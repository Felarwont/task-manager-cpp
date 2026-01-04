#include <iostream>
#include <stdexcept>
#include <string>
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

Task* TaskManager::getTask(int index) {
    if (index - 1 < 0 || index - 1 > tasks.size()) {
        throw std::out_of_range("Index out of range");
    }
    return tasks.data() + index - 1;
}
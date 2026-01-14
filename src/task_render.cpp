#include <iostream>

#include "todo/task_render.hpp"

void todo::TaskRender::printTasks(TaskManager& manager) {
    std::vector<TaskInfo> tasks = manager.getAllTaskInfo();
    if (tasks.size() == 0) {
        std::cout << "The task list is empty. Enjoy!" << std::endl;
        return;
    }
    std::cout << "------------------------" << std::endl;
    for (auto& task : tasks) {
        std::cout << task.index << ".\t" << task.title << '\t' << ((task.done) ? "✓" : "✘") << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}
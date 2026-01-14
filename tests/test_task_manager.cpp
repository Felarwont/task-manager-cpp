#include <iostream>

#include "todo/task_manager.hpp"
#include "todo/task_render.hpp"

int main() {
    todo::TaskManager manager;
    todo::TaskRender::printTasks(manager);

    manager.addTask("Xz ya bezdelnik");
    todo::TaskRender::printTasks(manager);

    for (int i = 0; i < 5; i++) {
        manager.addTask("xz" + std::to_string(i + 1));
    }
    todo::TaskRender::printTasks(manager);

    manager.removeTask(3);
    todo::TaskRender::printTasks(manager);

    for (int i = 0; i < 4; i++) {
        manager.completeTask(i);
    }
    todo::TaskRender::printTasks(manager);

    todo::TaskInfo task = manager.getTaskInfo(4);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    todo::TaskRender::printTasks(manager);

    manager.deleteCompleted();
    todo::TaskRender::printTasks(manager);

    manager.completeTask(0);
    task = manager.getTaskInfo(0);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    todo::TaskRender::printTasks(manager);

    std::vector<todo::TaskInfo> tasks = manager.getAllTaskInfo();
    for (auto& task : tasks) {
        std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    }

    manager.deleteCompleted();
    todo::TaskRender::printTasks(manager);
}
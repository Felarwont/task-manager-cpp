#include <iostream>

#include "todo/task_manager.hpp"
#include "todo/task_render.hpp"

int main() {
    TaskManager manager;
    TaskRender::printTasks(manager);

    manager.addTask("Xz ya bezdelnik");
    TaskRender::printTasks(manager);

    for (int i = 0; i < 5; i++) {
        manager.addTask("xz" + std::to_string(i + 1));
    }
    TaskRender::printTasks(manager);

    manager.removeTask(3);
    TaskRender::printTasks(manager);

    for (int i = 0; i < 4; i++) {
        manager.completeTask(i);
    }
    TaskRender::printTasks(manager);

    TaskInfo task = manager.getTaskInfo(4);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    TaskRender::printTasks(manager);

    manager.deleteCompleted();
    TaskRender::printTasks(manager);

    manager.completeTask(0);
    task = manager.getTaskInfo(0);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    TaskRender::printTasks(manager);

    std::vector<TaskInfo> tasks = manager.getAllTaskInfo();
    for (auto& task : tasks) {
        std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    }

    manager.deleteCompleted();
    TaskRender::printTasks(manager);
}
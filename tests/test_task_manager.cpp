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

    manager.removeTasks(3);
    TaskRender::printTasks(manager);

    for (int i = 0; i < 4; i++) {
        manager.completeTask(i + 1);
    }
    TaskRender::printTasks(manager);

    TaskInfo task = manager.getTaskInfo(5);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    TaskRender::printTasks(manager);
    manager.completeTask(5);
    task = manager.getTaskInfo(5);
    std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    TaskRender::printTasks(manager);

    std::vector<TaskInfo> tasks = manager.getAllTaskInfo();
    for (auto& task : tasks) {
        std::cout << "Index: " << task.index << " title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    }
}
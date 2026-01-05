#include <iostream>
#include <todo/task_manager.hpp>

int main() {
    TaskManager manager;
    manager.printTasks();

    manager.addTask("Xz ya bezdelnik");
    manager.printTasks();

    for (int i = 0; i < 5; i++) {
        manager.addTask("xz" + std::to_string(i + 1));
    }
    manager.printTasks();

    manager.removeTasks(3);
    manager.printTasks();

    for (int i = 0; i < 4; i++) {
        manager.completeTask(i + 1);
    }
    manager.printTasks();

    TaskInfo task = manager.getTaskInfo(5);
    std::cout << "Title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    manager.printTasks();
    manager.completeTask(5);
    task = manager.getTaskInfo(5);
    std::cout << "Title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    manager.printTasks();
    std::vector<TaskInfo> info = manager.getAllTaskInfo();
    for (auto& task : info) {
        std::cout << "Title: " << task.title << " done: " << ((task.done) ? "true" : "false") << std::endl;
    }
}
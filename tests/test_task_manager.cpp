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

    Task* task = manager.getTask(5);
    task->complete();
    manager.printTasks();
}
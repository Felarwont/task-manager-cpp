#include "todo/task_manager.hpp"
#include "todo/ui/task_render.hpp"

int main() {
    todo::TaskManager manager;
    manager.addTask("sometask");
    todo::ui::TaskRender::printTasks(manager);

    auto taskinfo = manager.getAllTaskInfo();

    for(auto& task : taskinfo) {
        manager.completeTask(task.index);
    }

    todo::ui::TaskRender::printTasks(manager);

    manager.deleteCompleted();

    todo::ui::TaskRender::printTasks(manager);
}
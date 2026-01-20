#pragma once

#include "todo/task_manager.hpp"

namespace todo {
    namespace ui {

        class TaskRender {
        public:
            static void printTasks(TaskManager& manager);
        };

    }
}
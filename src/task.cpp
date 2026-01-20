#include <iostream>
#include <string>

#include "todo/task.hpp"

std::string todo::Task::getTitle() { return title_; }

bool todo::Task::isDone() { return done_; }

void todo::Task::complete() {
    if (done_) {
        std::cout << "[*] The task has already been completed" << std::endl;
        return;
    }
    done_ = true;
}
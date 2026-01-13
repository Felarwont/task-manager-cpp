#include <iostream>
#include <string>

#include "todo/task.hpp"

std::string Task::getTitle() { return title_; }

bool Task::isDone() { return done_; }

void Task::complete() {
    if (done_) {
        std::cout << "[*] The task has already been completed" << std::endl;
        return;
    }
    done_ = true;
}
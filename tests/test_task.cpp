#include <cassert>
#include <iostream>
#include <todo/task.hpp>

int main() {
    Task empty_task;

    assert(empty_task.getTitle() == "Empty task");

    Task task("Cook a pie");

    assert(task.getTitle() == "Cook a pie");
    assert(!task.isDone());

    task.complete();

    assert(task.isDone());

    std::cout << "class Task test completed successfully!" << std::endl;
}
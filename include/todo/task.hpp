#pragma once

#include <string>

class Task {
public:
    Task(std::string title) : title_(title) {}

    std::string getTitle();
    bool isDone() ;
    void complete();

private:
    std::string title_;
    bool done_;
};

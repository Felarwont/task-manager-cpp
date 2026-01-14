#pragma once

#include <string>

namespace todo {
    class Task {
    public:
        Task(const std::string title = "Empty task") : title_(title) {}

        std::string getTitle();
        bool isDone();
        void complete();

    private:
        std::string title_;
        bool done_ = false;
    };
}
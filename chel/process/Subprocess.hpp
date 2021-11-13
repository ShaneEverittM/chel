#pragma once

#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace process
{
    class Subprocess;

    class ProcessHandle
    {
    public:
        explicit ProcessHandle(Subprocess *owner) : owner(owner)
        {}

        void execute();

    private:
        Subprocess *owner;
    };

    class Subprocess
    {
    public:
        template<typename... Args>
        explicit Subprocess(std::string path, Args &&...args)
                : path(std::move(path)), arguments({args...})
        {}

    private:
        std::string path;
        std::vector<std::string> arguments;
    };

}
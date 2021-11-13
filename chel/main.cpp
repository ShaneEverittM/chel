#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include <chel/process/Subprocess.hpp>

using process::Subprocess;

enum ShouldBreak
{
    Yes,
    No
};

void prompt()
{
    std::cout << "user> ";
}

std::vector<Subprocess> parse(std::string line)
{
    return {};
}

bool is_io_error()
{
    return std::cin.bad() or !std::cin.eof();
}

ShouldBreak run(std::vector<Subprocess> &commands)
{
    return ShouldBreak::No;
}

int main()
{
    // Initial prompt
    prompt();

    // REPL
    std::string line;
    while (std::getline(std::cin, line))
    {
        prompt();

        // Parse line into a list of commands
        auto commands = parse(line);

        // Spawn and run subprocesses, managing cleanup and communication
        auto should_break = run(commands);

        // Only really here for built-in command "quit"
        if (should_break == Yes)
            break;
    }

    // If we get here, use typed quit, or Ctrl-D, or a read error occurred
    // or some other fatal error
    if (is_io_error())
        return EXIT_FAILURE;
    else // EOF
        return EXIT_SUCCESS;
}


#ifndef __COMMANDS_PRINT_HPP__
#define __COMMANDS_PRINT_HPP__

#include <string>

class App;
namespace Commands {
    int print_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif

#ifndef __COMMANDS_PRINTLN_HPP__
#define __COMMANDS_PRINTLN_HPP__

#include <string>

class App;
namespace Commands {
    int println_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif

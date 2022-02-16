#ifndef __VIM_COMMANDS_WRITECOMMAND_HPP__
#define __VIM_COMMANDS_WRITECOMMAND_HPP__

#include <string>

namespace Vim {
    class App;
    namespace Commands {
        int write_command_exec(App *app, int argc, char **argv, std::string *error_message);
    }
}

#endif

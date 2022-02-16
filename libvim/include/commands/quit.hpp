#ifndef __VIM_COMMANDS_QUIT_HPP__
#define __VIM_COMMANDS_QUIT_HPP__

#include <string>

namespace Vim {
    class App;
    namespace Commands {
        int quit_exec(App *app, int argc, char **argv, std::string *error_message);
    }
}

#endif

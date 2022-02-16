#include <stdlib.h>
#include <glib.h>
#include "vim/commands/quit.hpp"
#include "vim/app.hpp"



namespace Vim::Commands {
    int quit_exec(App *app, int, char **, std::string *)
    {
        app->quit_when_possible();
        return 0;
    }
}

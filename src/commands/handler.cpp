#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <glib.h>
#include <unistd.h>
#include "app.hpp"
#include "commands/handler.hpp"

namespace Commands {

Handler::Handler(App *_app)
    : Vim::Commands::Handler(_app), app(_app)
{}

Handler::~Handler() {}


bool Handler::_has_command(const std::string &command_name) const
{
    return COMMANDS.count(command_name) > 0;
}
int Handler::_exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const
{
    return COMMANDS.at(command_name)(app, argc, argv, error_message);
}

/*
void Handler::set_global_variables(App *app, char **argv, int argc) const
{
    for (int i=0; i < argc; i++) {
        std::string arg(argv[i]);
        if (global_vars_getters.count(arg) > 0) {
            const std::string replacement = global_vars_getters.at(arg)(app);
            free(argv[i]);
            argv[i] = strdup(replacement.c_str());
        }
    }
}
*/

}

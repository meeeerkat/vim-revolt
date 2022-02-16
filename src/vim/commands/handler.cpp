#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <glib.h>
#include <unistd.h>
#include "vim/app.hpp"
#include "vim/input_handler.hpp"
#include "vim/widgets/command.hpp"
#include "vim/commands/handler.hpp"

namespace Vim::Commands {

Handler::Handler(App *_app)
    : app(_app)
{}

Handler::~Handler() {}

int Handler::_exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const
{
    if (COMMANDS.count(command_name) == 0)
        return 1; // Command not found
    return COMMANDS.at(command_name)(app, argc, argv, error_message);
}

int Handler::exec(const std::string &command) const
{
    int argc;
    char **argv;
    GError *error = NULL;

    if (!g_shell_parse_argv (command.c_str(), &argc, &argv, &error)) {
        std::string error_message(error->message);
        print_message(app, error_message);
        g_clear_error(&error);
        return -1;
    }

    //set_global_variables(app, argv, argc);
    const std::string command_name(argv[0]);
    if (command_name[0] == '!') {
        // Shell command
        /*
        std::string modified_command;
        for (int i=0; i < argc; i++) {
            modified_command += argv[i];
            modified_command += " ";
        }
        */
        app->pause();
        system(command.c_str() + 1);
        app->getInputHandler()->wait_for_input();
        app->unpause();
        g_strfreev(argv);
        return 0;
    }

    std::string error_message;
    int err_code = _exec_command(command_name, argc, argv, &error_message);
    if (err_code < 0) {
        print_message(app, error_message);
        g_strfreev(argv);
        return -2;
    }
    if (err_code == 1) {
        print_message(app, "Unknown command.");
        g_strfreev(argv);
        return 1;
    }

    g_strfreev(argv);
    return 0;
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

void Handler::print_message(App *app, const std::string &message) const {
    app->getCommandWidget()->print_message(message);
}
}

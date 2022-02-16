#include "commands/write_command.hpp"
#include "widgets/command.hpp"
#include "app.hpp"


namespace Vim::Commands {
    int write_command_exec(App *app, int argc, char **argv, std::string *)
    {
        if (argc == 2) {
            const std::string base_command(argv[1]);
            app->get_command_widget()->handle_input(app, &base_command);
        }
        else
            app->get_command_widget()->handle_input(app, NULL);

        return 0;
    }
}

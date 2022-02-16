#include "commands/println.hpp"
#include "app.hpp"
#include "widgets/logs.hpp"


namespace Commands {
    int println_exec(App *app, int argc, char **argv, std::string *error_message)
    {
        if (argc != 2) {
            *error_message = "Usage: print string";
            return -1;
        }

        app->get_logs_widget()->print(std::string(argv[1]) + "\n");

        return 0;
    }
}

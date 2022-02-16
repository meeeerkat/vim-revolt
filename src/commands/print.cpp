#include "commands/print.hpp"
#include "app.hpp"
#include "widgets/logs.hpp"


namespace Commands {
    int print_exec(App *app, int argc, char **argv, std::string *error_message)
    {
        if (argc != 2) {
            *error_message = "Usage: print string";
            return -1;
        }

        app->getLogsWidget()->print(std::string(argv[1]));

        return 0;
    }
}
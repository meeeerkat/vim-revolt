#ifndef __COMMANDS_HANDLER_HPP__
#define __COMMANDS_HANDLER_HPP__

#include <string>
#include <map>
//#include "commands/global.hpp"
#include "vim/commands/handler.hpp"


class App;

namespace Commands {

    typedef int (*Command) (App*, int, char**, std::string*);

    #define DECLARE_COMMAND(NAME) int NAME ## _exec(App*, int, char**, std::string*);
    DECLARE_COMMAND(print);
    DECLARE_COMMAND(println);

    class Handler : public Vim::Commands::Handler {
        public:
            Handler(App *app);
            virtual ~Handler();
            int exec(const std::string &command) const;

        protected:
            virtual int _exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const;

        private:
            App *app;
            #define COMMAND(NAME)  { #NAME, NAME ## _exec }
            std::map<std::string, Command> COMMANDS = {
                COMMAND(print),
                COMMAND(println)
            };

            /*
            void set_global_variables(App *app, char **argv, int argc) const;
            std::map<std::string, const std::string& (*) (App*)> global_vars_getters = 
            {
                { "$CURRENT_URL", Global::get_current_url },
            };
            */
    };

}

#endif

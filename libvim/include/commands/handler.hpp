#ifndef __VIM_COMMANDS_HANDLER_HPP__
#define __VIM_COMMANDS_HANDLER_HPP__

#include <string>
#include <map>


namespace Vim {
    class App;
namespace Commands {

    typedef int (*Command) (App*, int, char**, std::string*);

    #define DECLARE_COMMAND(NAME) int NAME ## _exec(App*, int, char**, std::string*);
    DECLARE_COMMAND(quit)
    DECLARE_COMMAND(write_command)

    class Handler {
        public:
            Handler(App *app);
            virtual ~Handler();
            int exec(const std::string &command) const;

        protected:
            virtual int _exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const;

        private:
            App *app;
            void print_message(App *app, const std::string&) const;
            #define COMMAND(NAME)  { #NAME, NAME ## _exec }
            std::map<std::string, Command> COMMANDS = 
            {
                COMMAND(quit),
                COMMAND(write_command)
            };

    };

}
}

#endif

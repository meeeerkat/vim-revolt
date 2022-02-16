#ifndef __VIM_APP_HPP__
#define __VIM_APP_HPP__

#include <string>

namespace YAML { class Node; }

namespace Vim {

class Config;
class InputHandler;
namespace Commands { class Handler; }
namespace Widgets { class Command; }

// Mostly only initialisation & modules management
class App {

    public:
        App(Commands::Handler *commands_handler);
        ~App();

        void set_config(YAML::Node yaml_config);
        
        void wait_and_handle_input();

        virtual void pause();
        virtual void unpause();
        void quit_when_possible();
        
        virtual int exec(const std::string &command);

        Config *get_config();
        InputHandler *get_input_handler();

        Widgets::Command *get_command_widget();

    private:
        // helpers
        Config *config;
        InputHandler *input_handler;
        Commands::Handler *commands_handler; // owns the commands_handler
        // widgets
        Widgets::Command *command_widget;

        bool should_quit;
};

}


#endif

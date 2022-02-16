#ifndef __APP_HPP__
#define __APP_HPP__

#include <string>
#include "vim/app.hpp"

namespace YAML { class Node; }

class Config;
namespace Commands { class Handler; }
namespace Widgets { class Logs; }

// Mostly only initialisation & modules management
class App : public Vim::App {

    public:
        App();
        ~App();

        virtual void pause();
        virtual void unpause();
        
        Config *getConfig();
        Widgets::Logs *getLogsWidget();

    private:
        // helpers
        Config *config;
        Commands::Handler *commands_handler;
        // widgets
        Widgets::Logs *logs_widget;

};


#endif

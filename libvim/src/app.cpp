#include "app.hpp"
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/handler.hpp"
#include "config.hpp"


namespace Vim {

App::App(Commands::Handler *_commands_handler)
    : commands_handler(_commands_handler), should_quit(false)
{
    // ncurses init
    initscr();

    // helpers init
    input_handler = new InputHandler();

    // widgets init
    command_widget = new Widgets::Command();
}

App::~App()
{
    // widgets freeing
    delete command_widget;

    // helpers freeing
    delete input_handler;
    delete commands_handler;
    delete config;

    // ncurses closing
    endwin();
}

void App::set_config(YAML::Node yaml_config) {
    config = new Config(yaml_config);
}

void App::pause()
{
    command_widget->set_refresh_policy(false);

    endwin();
}

void App::unpause()
{
    initscr();
    
    command_widget->set_refresh_policy(true);
    command_widget->clear();
}

void App::quit_when_possible()
{
    should_quit = true;
}

void App::wait_and_handle_input()
{
    while (!should_quit) {
        // Here we only handle shortcuts (some redirect to the widgets)
        const uint16_t c = input_handler->get_input();
        const std::string *command = config->get_command_from_shortcut(c);
        if (command)
            exec(*command);
    }
}

int App::exec(const std::string &command)
{
    return commands_handler->exec(command);
}

Config *App::get_config() {
    return config;
}
InputHandler *App::get_input_handler() {
    return input_handler;
}
Widgets::Command *App::get_command_widget() {
    return command_widget;
}
}

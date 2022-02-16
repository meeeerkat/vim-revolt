#include "app.hpp"
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include "commands/handler.hpp"
#include "config.hpp"
#include "widgets/logs.hpp"


App::App()
    : Vim::App(new Commands::Handler(this))
{
    std::string path = std::string(getenv("HOME")) + "/.vim-base.yaml";
    YAML::Node yaml_config = YAML::LoadFile(path);
    config = new Config(yaml_config);
    Vim::App::set_config(yaml_config);

    logs_widget = new Widgets::Logs();
}

App::~App()
{
    delete logs_widget;

    delete config;
}

void App::pause()
{
    Vim::App::pause();

    logs_widget->set_refresh_policy(false);
}

void App::unpause()
{
    logs_widget->set_refresh_policy(true);
    logs_widget->refresh_display();

    Vim::App::unpause();
}

Widgets::Logs *App::get_logs_widget() {
    return logs_widget;
}

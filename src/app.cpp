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
}

void App::pause()
{
}

void App::unpause()
{
}

Widgets::Logs *App::getLogsWidget() {
    return logs_widget;
}

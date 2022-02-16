#include "app.hpp"
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include "commands/handler.hpp"
#include "config.hpp"


App::App()
    : Vim::App(new Commands::Handler(this))
{
    std::string path = std::string(getenv("HOME")) + "/.vim-browser.yaml";
    YAML::Node yaml_config = YAML::LoadFile(path);
    config = new Config(yaml_config);
    Vim::App::set_config(yaml_config);
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

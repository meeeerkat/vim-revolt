#ifndef __VIM_CONFIG_H__
#define __VIM_CONFIG_H__

#include <map>
#include <string>

namespace YAML { class Node; }

class Config {
    public:
        Config(const YAML::Node &config);
};

#endif

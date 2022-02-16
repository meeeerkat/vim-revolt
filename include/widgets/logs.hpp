#ifndef __WIDGETS_LOGS_HPP__
#define __WIDGETS_LOGS_HPP__

#include <string>
#include <ncurses.h>
#include "vim/widgets/widget.hpp"

class App;

namespace Widgets {
    class Logs : public Vim::Widgets::Widget {
        public:
            Logs();
            virtual ~Logs();

            void refresh_display() const;
            void print(const std::string &message);
            void scroll_to(uint32_t start_line_p);
            uint32_t get_start_line() const;

        private:
            WINDOW *pad;
            uint32_t start_line;
            std::string saved_logs;
            
            const uint32_t MAX_LINES_NB = 5000;
    };
}

#endif

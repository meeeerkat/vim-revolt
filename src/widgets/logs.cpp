#include <ncurses.h>
#include <ctype.h>
#include "widgets/logs.hpp"
#include "app.hpp"

namespace Widgets {

Logs::Logs()
    : Widget(), start_line(0)
{
    pad = newpad(MAX_LINES_NB, COLS);
    keypad(pad, TRUE);
}

Logs::~Logs()
{
    delwin(pad);
}

void Logs::print(const std::string &message)
{
    saved_logs += message;

    if (!isendwin())
        refresh_display();
}

void Logs::scroll_to(uint32_t start_line_p)
{
    if (start_line_p > MAX_LINES_NB)
        return;

    start_line = start_line_p;
    prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
}

void Logs::refresh_display() const
{
    if (!can_refresh())
        return;

    wclear(pad);
    wprintw(pad, saved_logs.c_str());
    prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
}

uint32_t Logs::get_start_line() const
{
    return start_line;
}

}

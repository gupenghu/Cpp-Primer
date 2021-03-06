//
//  ex7_27.h
//  Exercise 7.27
//
//  Created by pezy on 11/14/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef Test_ex7_27_h
#define Test_ex7_27_h

#include <string>
#include <iostream>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd, pos n):height(ht),width(wd),contents(n, ' '){} // 2
    Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd, c){} // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
    Screen& display(std::ostream &os) { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r*width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r*width+c] = ch;
    return *this;
}

#endif

#ifndef BASIC_STRINGS_CHAR_HPP
#define BASIC_STRINGS_CHAR_HPP

#include "../Any.hpp"
#include <iostream>

class String;
class Int;

class Char{
private:
    char holder = '\0';
public:
    Char();
    Char(char);
    Char(Char&);

    ~Char();

    Char& operator=(char);

    operator char();

    Int toInt() const;
    Int toIntC() const;

    String toString() const;
};


#endif //BASIC_STRINGS_CHAR_HPP
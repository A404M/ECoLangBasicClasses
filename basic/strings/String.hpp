#ifndef BASIC_STRINGS_STRING_HPP
#define BASIC_STRINGS_STRING_HPP

#include "../Any.hpp"
#include <string>
#include "../numberic/Int.hpp"
#include "Char.hpp"

class Boolean;

class String: public Any{
    friend std::ostream& operator<<(std::ostream&,const String&);
    friend std::istream& operator>>(std::istream&,String&);

    friend Boolean operator==(const String&,const String&);
    friend Boolean operator==(const String&,const std::string&);
    friend Boolean operator==(const std::string&,const String&);

    friend Boolean operator!=(const String&,const String&);
    friend Boolean operator!=(const String&,const std::string&);
    friend Boolean operator!=(const std::string&,const String&);

    friend String operator*(const String&,Int);

    friend String operator+(const String&,const String&);
    friend String operator+(const String&,const std::string&);
    friend String operator+(const String&,const char);
    friend String operator+(const std::string&,const String&);
    friend String operator+(const char,const String&);
private:
    std::string holder = "";
public:
    String();
    String(const String&);
    String(const std::string&);

    String& operator=(const String&);
    String& operator=(const std::string&);
    String& operator=(const char);

    String& operator+=(const String&);
    String& operator+=(const std::string&);
    String& operator+=(const char);

    String& operator*=(Int);

    const Char operator[](const Int&) const;
    Char& operator[](const Int&);

    String toString() const;
    Int toInt(short) const;

    String reverse() const;

    Int size() const;
};


#endif //BASIC_STRINGS_STRING_HPP
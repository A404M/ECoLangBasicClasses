#ifndef BASIC_NUMBERIC_INT_HPP
#define BASIC_NUMBERIC_INT_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include "../Any.hpp"

class String;
class Boolean;

typedef boost::multiprecision::cpp_int TheInt;

class Int: public Any{
    friend std::ostream& operator<<(std::ostream&,const Int&);
    friend std::istream& operator>>(std::istream&,Int&);

    friend Boolean operator==(const Int&,const Int&);
    friend Boolean operator==(const Int&,const TheInt&);
    friend Boolean operator==(const Int&,const std::string&);
    friend Boolean operator==(const Int&,const long long&);
    friend Boolean operator==(const TheInt&,const Int&);
    friend Boolean operator==(const std::string&,const Int&);
    friend Boolean operator==(const long long&,const Int&);


    friend Boolean operator!=(const Int&,const Int&);
    friend Boolean operator!=(const Int&,const TheInt&);
    friend Boolean operator!=(const Int&,const std::string&);
    friend Boolean operator!=(const Int&,const long long&);
    friend Boolean operator!=(const TheInt&,const Int&);
    friend Boolean operator!=(const std::string&,const Int&);
    friend Boolean operator!=(const long long&,const Int&);

    friend Boolean operator>(const Int&,const Int&);
    friend Boolean operator>(const Int&,const TheInt&);
    friend Boolean operator>(const Int&,const std::string&);
    friend Boolean operator>(const Int&,const long long&);
    friend Boolean operator>(const TheInt&,const Int&);
    friend Boolean operator>(const std::string&,const Int&);
    friend Boolean operator>(const long long&,const Int&);

    friend Boolean operator<(const Int&,const Int&);
    friend Boolean operator<(const Int&,const TheInt&);
    friend Boolean operator<(const Int&,const std::string&);
    friend Boolean operator<(const Int&,const long long&);
    friend Boolean operator<(const TheInt&,const Int&);
    friend Boolean operator<(const std::string&,const Int&);
    friend Boolean operator<(const long long&,const Int&);

    friend Boolean operator>=(const Int&,const Int&);
    friend Boolean operator>=(const Int&,const TheInt&);
    friend Boolean operator>=(const Int&,const std::string&);
    friend Boolean operator>=(const Int&,const long long&);
    friend Boolean operator>=(const TheInt&,const Int&);
    friend Boolean operator>=(const std::string&,const Int&);
    friend Boolean operator>=(const long long&,const Int&);

    friend Boolean operator<=(const Int&,const Int&);
    friend Boolean operator<=(const Int&,const TheInt&);
    friend Boolean operator<=(const Int&,const std::string&);
    friend Boolean operator<=(const Int&,const long long&);
    friend Boolean operator<=(const TheInt&,const Int&);
    friend Boolean operator<=(const std::string&,const Int&);
    friend Boolean operator<=(const long long&,const Int&);


    friend Int operator+(const Int&,const Int&);
    friend Int operator+(const Int&,const TheInt&);
    friend Int operator+(const Int&,const std::string&);
    friend Int operator+(const Int&,const long long&);
    friend Int operator+(const TheInt&,const Int&);
    friend Int operator+(const std::string&,const Int&);
    friend Int operator+(const long long&,const Int&);

    friend Int operator-(const Int&,const Int&);
    friend Int operator-(const Int&,const TheInt&);
    friend Int operator-(const Int&,const std::string&);
    friend Int operator-(const Int&,const long long&);
    friend Int operator-(const TheInt&,const Int&);
    friend Int operator-(const std::string&,const Int&);
    friend Int operator-(const long long&,const Int&);

    friend Int operator*(const Int&,const Int&);
    friend Int operator*(const Int&,const TheInt&);
    friend Int operator*(const Int&,const std::string&);
    friend Int operator*(const Int&,const long long&);
    friend Int operator*(const TheInt&,const Int&);
    friend Int operator*(const std::string&,const Int&);
    friend Int operator*(const long long&,const Int&);

    friend Int operator/(const Int&,const Int&);
    friend Int operator/(const Int&,const TheInt&);
    friend Int operator/(const Int&,const std::string&);
    friend Int operator/(const Int&,const long long&);
    friend Int operator/(const TheInt&,const Int&);
    friend Int operator/(const std::string&,const Int&);
    friend Int operator/(const long long&,const Int&);

    friend Int operator%(const Int&,const Int&);
    friend Int operator%(const Int&,const TheInt&);
    friend Int operator%(const Int&,const std::string&);
    friend Int operator%(const Int&,const long long&);
    friend Int operator%(const TheInt&,const Int&);
    friend Int operator%(const std::string&,const Int&);
    friend Int operator%(const long long&,const Int&);

    friend Int pow(const Int&,const long long&);
private:
    TheInt holder = 0;

    static TheInt string2TheInt(const std::string&,short);
public:
    Int();
    Int(const Int&);
    Int(const long long&);
    Int(const TheInt&);
    Int(const std::string&);

    ~Int();

    Int& operator=(const Int&);
    Int& operator=(const long long&);
    Int& operator=(const TheInt&);
    Int& operator=(const std::string&);

    const Int operator-() const;
    const Int operator+() const;

    const Int operator++(int);
    const Int operator--(int);
    Int& operator++();
    Int& operator--();

    Int& operator+=(const Int&);
    Int& operator+=(const long long&);
    Int& operator+=(const TheInt&);
    Int& operator+=(const std::string&);

    Int& operator-=(const Int&);
    Int& operator-=(const long long&);
    Int& operator-=(const TheInt&);
    Int& operator-=(const std::string&);

    Int& operator*=(const Int&);
    Int& operator*=(const long long&);
    Int& operator*=(const TheInt&);
    Int& operator*=(const std::string&);

    Int& operator/=(const Int&);
    Int& operator/=(const long long&);
    Int& operator/=(const TheInt&);
    Int& operator/=(const std::string&);

    Int& operator%=(const Int&);
    Int& operator%=(const long long&);
    Int& operator%=(const TheInt&);
    Int& operator%=(const std::string&);

    Int pow(const long long&) const;

    String toRadix(const Int&) const;
    String toString() const;
    long long toLongLong() const;
};

#endif
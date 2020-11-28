#ifndef BASIC_NUMBERIC_FLOAT_HPP
#define BASIC_NUMBERIC_FLOAT_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include "../Any.hpp"

class String;

typedef boost::multiprecision::cpp_int TheInt;

class Float : public Any{
private:
    TheInt holder = 0;
    unsigned long long point = 0;
public:
    Float();
    Float(const Float&);
    Float(const long double&);
    Float(const String&);
    
    Float& operator=(const Float&);
    Float& operator=(const long double&);
    Float& operator=(const String&);
};


#endif //BASIC_NUMBERIC_FLOAT_HPP
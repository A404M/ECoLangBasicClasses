#include "Char.hpp"
#include "../numberic/Int.hpp"
#include "String.hpp"

//public
Char::Char(){
    this->holder = '\0';
}
Char::Char(char c){
    this->holder = c;
}
Char::Char(Char& c){
    this->holder = c.holder;
}
Char::~Char(){
    this->holder = '\0';
}

Char& Char::operator=(char c){
    this->holder = c;
    return *this;
}

Char::operator char(){
    return this->holder;
}

Int Char::toInt() const{
    return (this->holder - '0');
}
Int Char::toIntC() const{
    return this->holder;
}

String Char::toString() const{
    String temp;
    temp = this->holder;
    return String(temp);
}











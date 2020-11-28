#include "Boolean.hpp"
#include "../strings/String.hpp"

//public
Boolean::Boolean(){
    this->holder = false;
}
Boolean::Boolean(const Boolean& b){
    *this = b;
}
Boolean::Boolean(const bool b){
    *this = b;
}

Boolean::~Boolean() = default;

Boolean& Boolean::operator=(const Boolean& b){
    this->holder = b.holder;
    return *this;
}
Boolean& Boolean::operator=(const bool b){
    this->holder = b;
    return *this;
}

Boolean::operator bool(){
    return this->holder;
}












//friends

std::ostream& operator<<(std::ostream& os,const Boolean& b){
    os << ((b.holder)?"true":"false");
    return os;
}
std::istream& operator>>(std::istream& is,Boolean& b){
    String str;
    is >> str;
    b = (str == "true")?true:false;
    return is;
}


Boolean operator==(const Boolean& a,const Boolean& b){
    return a.holder == b.holder;
}
Boolean operator==(const Boolean& a,bool b){
    return a.holder == b;
}
Boolean operator==(bool a,const Boolean& b){
    return a == b.holder;
}

Boolean operator!=(const Boolean& a,const Boolean& b){
    return a.holder != b.holder;
}
Boolean operator!=(const Boolean& a,bool b){
    return a.holder != b;
}
Boolean operator!=(bool a,const Boolean& b){
    return a != b.holder;
}

#include "String.hpp"
#include "../numberic/Int.hpp"
#include "../logical/Boolean.hpp"
#include <map>

String::String(){
    holder = "";
}
String::String(const String& str){
    *this = str;
}
String::String(const std::string& str){
    holder = str;
}

String& String::operator=(const String& str){
    this->holder = str.holder;
    return *this;
}
String& String::operator=(const std::string& str){
    this->holder = str;
    return *this;
}
String& String::operator=(const char c){
    this->holder = c;
    return *this;
}

String& String::operator+=(const String& str){
    this->holder += str.holder;
    return *this;
}
String& String::operator+=(const std::string& str){
    this->holder += str;
    return *this;
}
String& String::operator+=(const char c){
    this->holder += c;
    return *this;
}

String& String::operator*=(Int i){
    std::string str = this->holder;
    for(;i > 0;i--){
        this->holder += str;
    }
    return *this;
}

const Char String::operator[](const Int& i) const{
    return Char(this->holder[i.toLongLong()]);
}
Char& String::operator[](const Int& i){
    return (Char&)this->holder[i.toLongLong()];
}

String String::toString() const{
    return *this;
}
Int String::toInt(short radix = 10) const{
    std::map<char,short> elements = {
        {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},
        {'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15},{'G',16},{'H',17},{'I',18},{'J',19},{'K',20},{'L',21},{'M',22},{'N',23},{'O',24},{'P',25},{'Q',26},{'R',27},{'S',28},{'T',29},{'U',30},{'V',31},{'W',32},{'X',33},{'Y',34},{'Z',35},
      /*{'a',36},{'b',37},{'c',38},{'d',39},{'e',40},{'f',41},{'g',42},{'h',43},{'i',44},{'j',45},{'k',46},{'l',47},{'m',48},{'n',49},{'o',50},{'p',51},{'q',52},{'r',53},{'s',54},{'t',55},{'u',56},{'v',57},{'w',58},{'x',59},{'y',60},{'z',61} */};
    
    Int result = 0;
    for(unsigned long long int i = holder.size()-1;i != ULLONG_MAX;i--){
        short temp = elements[std::toupper(holder[i])];
        if(temp >= radix || temp < 0){
            std::cout << std::endl << "error in converting \"" << holder << "\" to radix " << radix << std::endl
            << "in value '" << holder[i] << "'" << std::endl;
            exit(-1);
        }else{
            result += temp * pow(radix,i);
        }
    }
    return result;
}

String String::reverse() const{
    std::string result;
    for(unsigned long long i = this->holder.size();i != ULLONG_MAX;i--){
        result += this->holder[i];
    }
    return result;
}

Int String::size() const{
    return Int(this->holder.size());
}











//friend

std::ostream& operator<<(std::ostream& os,const String& str){
    os << str.holder;
    return os;
}
std::istream& operator>>(std::istream& is,String& str){
    is >> str.holder;
    return is;
}


Boolean operator==(const String& str1,const String& str2){
    return str1.holder == str2.holder;
}
Boolean operator==(const String& str1,const std::string& str2){
    return str1.holder == str2;
}
Boolean operator==(const std::string& str1,const String& str2){
    return str1 == str2.holder;
}

Boolean operator!=(const String& str1,const String& str2){
    return str1.holder != str2.holder;
}
Boolean operator!=(const String& str1,const std::string& str2){
    return str1.holder != str2;
}
Boolean operator!=(const std::string& str1,const String& str2){
    return str1 != str2.holder;
}

String operator*(const String& str,Int i){
    String result;
    for(;i > 0;i--){
        result.holder += str.holder;
    }
    return result;
}
String operator+(const String& str1,const String& str2){
    return String(str1.holder+str2.holder);
}
String operator+(const String& str1,const std::string& str2){
    return String(str1.holder + str2);
}
String operator+(const String& str,const char c){
    return String(str.holder + c);
}
String operator+(const std::string& str1,const String& str2){
    return String(str1 + str2.holder);
}
String operator+(const char c,const String& str){
    return String(str.holder + c);
}


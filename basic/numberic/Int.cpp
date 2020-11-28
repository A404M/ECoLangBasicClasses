#include "Int.hpp"
#include "../strings/String.hpp"
#include "../logical/Boolean.hpp"
#include <map>
#include <sstream>

//public
Int::Int(){
    holder = 0;
}
Int::Int(const Int& i){
    *this = i;
}
Int::Int(const long long& v){
    holder = v;
}
Int::Int(const TheInt& v){
    holder = v;
}
Int::Int(const std::string& v){
    *this = v;
}

Int::~Int(){
    holder = 0;
}


Int& Int::operator=(const Int& i){
    this->holder = i.holder;
    return *this;
}
Int& Int::operator=(const long long& v){
    holder = v;
    return *this;
}
Int& Int::operator=(const TheInt& v){
    holder = v;
    return *this;
}
Int& Int::operator=(const std::string& v){
    holder = string2TheInt(v,10);
    return *this;
}

const Int Int::operator-() const{
    Int temp = *this;
    temp.holder *= -1;
    return temp;
}
const Int Int::operator+() const{
    return *this;
}

const Int Int::operator++(int){
    Int temp = *this;
    this->holder++;
    return temp;
}
const Int Int::operator--(int){
    Int temp = *this;
    this->holder--;
    return temp;
}
Int& Int::operator++(){
    ++this->holder;
    return *this;
}
Int& Int::operator--(){
    --this->holder;
    return *this;
}


Int& Int::operator+=(const Int& v){
    this->holder += v.holder;
    return *this;
}
Int& Int::operator+=(const long long& v){
    this->holder += v;
    return *this;
}
Int& Int::operator+=(const TheInt& v){
    this->holder += v;
    return *this;
}
Int& Int::operator+=(const std::string& v){
    this->holder += string2TheInt(v,10);
    return *this;
}

Int& Int::operator-=(const Int& v){
    this->holder -= v.holder;
    return *this;
}
Int& Int::operator-=(const long long& v){
    this->holder -= v;
    return *this;
}
Int& Int::operator-=(const TheInt& v){
    this->holder -= v;
    return *this;
}
Int& Int::operator-=(const std::string& v){
    this->holder -= string2TheInt(v,10);
    return *this;
}

Int& Int::operator*=(const Int& v){
    this->holder *= v.holder;
    return *this;
}
Int& Int::operator*=(const long long& v){
    this->holder *= v;
    return *this;
}
Int& Int::operator*=(const TheInt& v){
    this->holder *= v;
    return *this;
}
Int& Int::operator*=(const std::string& v){
    this->holder *= string2TheInt(v,10);
    return *this;
}

Int& Int::operator/=(const Int& v){
    this->holder /= v.holder;
    return *this;
}
Int& Int::operator/=(const long long& v){
    this->holder /= v;
    return *this;
}
Int& Int::operator/=(const TheInt& v){
    this->holder /= v;
    return *this;
}
Int& Int::operator/=(const std::string& v){
    this->holder /= string2TheInt(v,10);
    return *this;
}

Int& Int::operator%=(const Int& v){
    this->holder %= v.holder;
    return *this;
}
Int& Int::operator%=(const long long& v){
    this->holder %= v;
    return *this;
}
Int& Int::operator%=(const TheInt& v){
    this->holder %= v;
    return *this;
}
Int& Int::operator%=(const std::string& v){
    this->holder %= string2TheInt(v,10);
    return *this;
}

Int Int::pow(const long long& i) const{
    return Int(TheInt(boost::multiprecision::pow(this->holder,i)));
    
}

String Int::toRadix(const Int& i) const{
    String result;
    Int num = *this;
 
    char elements[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    /* ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' */};

    do{
        short temp = (num%i).toLongLong();
        num /= i;
        result += elements[temp];
    }while(num != 0);

    return result;
}
String Int::toString() const{
    std::stringstream ss;
    ss << this->holder;
    String str;
    ss >> str;
    return str;
}
long long Int::toLongLong() const{
    return this->holder.convert_to<long long>();
}






//private

TheInt Int::string2TheInt(const std::string& str,short radix = 10){
    TheInt result = 0;
    short sign = 0;

    if(str[0] == '-'){
        sign = -1;
    }else if(str[1] == '+'){
        sign = +1;
    }

    for(unsigned long long i = sign?1:0;i < str.size();i++){
        TheInt temp = toupper(str[i])-'0';
        if(temp >= radix||temp < 0){
            std::cout << "\nError in conver \"" << str << "\" to integer\n"
            << "In char '" << str[i] << "'\n";
            exit(-1);
        }
        for(unsigned long long j = 0;j < i;j++){
            temp *= 10;
        }
        result += temp;
    }
    

    return result;
}













//friend

std::ostream& operator<<(std::ostream& os,const Int& i){
    os << i.holder;
    return os;
}
std::istream& operator>>(std::istream& is,Int& i){
    is >> i.holder;
    return is;
}


Boolean operator==(const Int& a,const Int& b){
    return a.holder == b.holder;
}
Boolean operator==(const Int& a,const TheInt& b){
    return a.holder == b;
}
Boolean operator==(const Int& a,const std::string& b){
    return a.holder == Int::string2TheInt(b);
}
Boolean operator==(const Int& a,const long long& b){
    return a.holder == b;
}
Boolean operator==(const TheInt& b,const Int& a){
    return a == b;
}
Boolean operator==(const std::string& b,const Int& a){
    return a.holder == Int::string2TheInt(b);
}
Boolean operator==(const long long& b,const Int& a){
    return a.holder == b;
}

Boolean operator!=(const Int& a,const Int& b){
    return a.holder != b.holder;
}
Boolean operator!=(const Int& a,const TheInt& b){
    return a.holder != b;
}
Boolean operator!=(const Int& a,const std::string& b){
    return a.holder != Int::string2TheInt(b);
}
Boolean operator!=(const Int& a,const long long& b){
    return a.holder != b;
}
Boolean operator!=(const TheInt& b,const Int& a){
    return a != b;
}
Boolean operator!=(const std::string& b,const Int& a){
    return a.holder != Int::string2TheInt(b);
}
Boolean operator!=(const long long& b,const Int& a){
    return a.holder != b;
}

Boolean operator>(const Int& a,const Int& b){
    return a.holder > b.holder;
}
Boolean operator>(const Int& a,const TheInt& b){
    return a.holder > b;
}
Boolean operator>(const Int& a,const std::string& b){
    return a.holder > Int::string2TheInt(b);
}
Boolean operator>(const Int& a,const long long& b){
    return a.holder > b;
}
Boolean operator>(const TheInt& b,const Int& a){
    return b > a.holder;
}
Boolean operator>(const std::string& b,const Int& a){
    return Int::string2TheInt(b) > a.holder;
}
Boolean operator>(const long long& b,const Int& a){
    return b > a.holder;
}

Boolean operator<(const Int& a,const Int& b){
    return a.holder < b.holder;
}
Boolean operator<(const Int& a,const TheInt& b){
    return a.holder < b;
}
Boolean operator<(const Int& a,const std::string& b){
    return a.holder < Int::string2TheInt(b);
}
Boolean operator<(const Int& a,const long long& b){
    return a.holder < b;
}
Boolean operator<(const TheInt& b,const Int& a){
    return b < a.holder;
}
Boolean operator<(const std::string& b,const Int& a){
    return Int::string2TheInt(b) < a.holder;
}
Boolean operator<(const long long& b,const Int& a){
    return b < a.holder;
}

Boolean operator>=(const Int& a,const Int& b){
    return a.holder >= b.holder;
}
Boolean operator>=(const Int& a,const TheInt& b){
    return a.holder >= b;
}
Boolean operator>=(const Int& a,const std::string& b){
    return a.holder >= Int::string2TheInt(b);
}
Boolean operator>=(const Int& a,const long long& b){
    return a.holder >= b;
}
Boolean operator>=(const TheInt& b,const Int& a){
    return b >= a.holder;
}
Boolean operator>=(const std::string& b,const Int& a){
    return Int::string2TheInt(b) >= a.holder;
}
Boolean operator>=(const long long& b,const Int& a){
    return b >= a.holder;
}


Int operator+(const Int& a,const Int& b){
    return Int(a.holder + b.holder);
}
Int operator+(const Int& a,const TheInt& b){
    return Int(a.holder + b);
}
Int operator+(const Int& a,const std::string& b){
    return Int(a.holder + Int::string2TheInt(b));
}
Int operator+(const Int& a,const long long& b){
    return Int(a.holder + b);
}
Int operator+(const TheInt& a,const Int& b){
    return Int(a + b.holder);
}
Int operator+(const std::string& a,const Int& b){
    return Int(Int::string2TheInt(a) + b.holder);
}
Int operator+(const long long& a,const Int& b){
    return Int(a + b.holder);
}

Int operator-(const Int& a,const Int& b){
    return Int(a.holder - b.holder);
}
Int operator-(const Int& a,const TheInt& b){
    return Int(a.holder - b);
}
Int operator-(const Int& a,const std::string& b){
    return Int(a.holder - Int::string2TheInt(b));
}
Int operator-(const Int& a,const long long& b){
    return Int(a.holder - b);
}
Int operator-(const TheInt& a,const Int& b){
    return Int(a - b.holder);
}
Int operator-(const std::string& a,const Int& b){
    return Int(Int::string2TheInt(a) - b.holder);
}
Int operator-(const long long& a,const Int& b){
    return Int(a - b.holder);
}

Int operator*(const Int& a,const Int& b){
    return Int(a.holder * b.holder);
}
Int operator*(const Int& a,const TheInt& b){
    return Int(a.holder * b);
}
Int operator*(const Int& a,const std::string& b){
    return Int(a.holder * Int::string2TheInt(b));
}
Int operator*(const Int& a,const long long& b){
    return Int(a.holder * b);
}
Int operator*(const TheInt& a,const Int& b){
    return Int(a * b.holder);
}
Int operator*(const std::string& a,const Int& b){
    return Int(Int::string2TheInt(a) * b.holder);
}
Int operator*(const long long& a,const Int& b){
    return Int(a * b.holder);
}

Int operator/(const Int& a,const Int& b){
    return Int(a.holder / b.holder);
}
Int operator/(const Int& a,const TheInt& b){
    return Int(a.holder / b);
}
Int operator/(const Int& a,const std::string& b){
    return Int(a.holder / Int::string2TheInt(b));
}
Int operator/(const Int& a,const long long& b){
    return Int(a.holder / b);
}
Int operator/(const TheInt& a,const Int& b){
    return Int(a / b.holder);
}
Int operator/(const std::string& a,const Int& b){
    return Int(Int::string2TheInt(a) / b.holder);
}
Int operator/(const long long& a,const Int& b){
    return Int(a / b.holder);
}

Int operator%(const Int& a,const Int& b){
    return Int(a.holder % b.holder);
}
Int operator%(const Int& a,const TheInt& b){
    return Int(a.holder % b);
}
Int operator%(const Int& a,const std::string& b){
    return Int(a.holder % Int::string2TheInt(b));
}
Int operator%(const Int& a,const long long& b){
    return Int(a.holder % b);
}
Int operator%(const TheInt& a,const Int& b){
    return Int(a % b.holder);
}
Int operator%(const std::string& a,const Int& b){
    return Int(Int::string2TheInt(a) % b.holder);
}
Int operator%(const long long& a,const Int& b){
    return Int(a % b.holder);
}

Int pow(const Int& number,const long long& pow){
    return Int(TheInt(boost::multiprecision::pow(number.holder,pow)));
}










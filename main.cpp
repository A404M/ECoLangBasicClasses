#include <iostream>
#include "basic/numberic/Int.hpp"
#include "basic/strings/String.hpp"
#include "basic/logical/Boolean.hpp"
#include "basic/strings/Char.hpp"

using namespace std;

int size(char* s){
    int len = 0;
    while (*s){
        if((*s++ & 0xc0) != 0x80){
            len++;
        }else{

        }
    }
    return len;
}

int main(){
    String a = String("123456");

    a[0] = '9';

    cout << a << endl;

    return 0;
}
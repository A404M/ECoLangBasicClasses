#ifndef BASIC_LOGICAL_BOOLEAN
#define BASIC_LOGICAL_BOOLEAN

#include "../Any.hpp"
#include <iostream>

class Boolean : public Any{
    friend std::ostream& operator<<(std::ostream&,const Boolean&);
    friend std::istream& operator>>(std::istream&,Boolean&);

    friend Boolean operator==(const Boolean&,const Boolean&); 
    friend Boolean operator==(const Boolean&,bool); 
    friend Boolean operator==(bool,const Boolean&); 

    friend Boolean operator!=(const Boolean&,const Boolean&);
    friend Boolean operator!=(const Boolean&,bool);
    friend Boolean operator!=(bool,const Boolean&);
private:
    bool holder;
public:
    Boolean();
    Boolean(const Boolean&);
    Boolean(const bool);

    ~Boolean();

    Boolean& operator=(const Boolean&);
    Boolean& operator=(const bool);

    operator bool();
    
    String toString();
};




#endif //BASIC_LOGICAL_BOOLEAN
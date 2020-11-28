#ifndef BASIC_ANY_HPP
#define BASIC_ANY_HPP

class String;

class Any{
public:
    Any();
    virtual ~Any();
    virtual String toString() const;
    template<typename T>
    T to() const;
};


#endif //BASIC_ANY_HPP
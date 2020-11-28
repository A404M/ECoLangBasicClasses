#include "Any.hpp"
#include "strings/String.hpp"

Any::Any() = default;
Any::~Any() = default;

String Any::toString() const{
    return String();
}
template<typename T>
T Any::to() const{
    return (T)*this;
}

cmake_minimum_required(VERSION 3.16.3)
project(BasicClasses)

set(CMAKE_CXX_STANDARD 20)

add_executable(
                BasicClasses main.cpp
                basic/Any.cpp                  basic/Any.hpp
                basic/numberic/Numberic.cpp    basic/numberic/Numberic.hpp
                basic/numberic/Int.cpp         basic/numberic/Int.hpp
                basic/numberic/Float.cpp       basic/numberic/Float.hpp
                basic/strings/Char.cpp         basic/strings/Char.hpp
                basic/strings/String.cpp       basic/strings/String.hpp
                basic/logical/Boolean.cpp      basic/logical/Boolean.hpp
              )
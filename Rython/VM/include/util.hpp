#ifndef RYTHON_UTIL_HPP
#define RYTHON_UTIL_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <sstream>
#include <type_traits>


enum __xxTPT07__ {
    IDENTIFIER = 1,  // x, number, name, age, etc
    KEYWORD,  // print, if, input, return
    SEPARATOR, // }, |,
    OPERATOR, // >, +, -, =, /, //
    LITERAL,  // 10, "Jason", True
    COMMENT, // # this is a comment.
};

char* readFile(char* path);
std::ostream& operator << (std::ostream& os, const __xxTPT07__& obj);
std::vector<__xxTPT07__> Iden(char* lineBuf);
char* intToChar(int a);


#endif // RYTHON_UTIL_HPP
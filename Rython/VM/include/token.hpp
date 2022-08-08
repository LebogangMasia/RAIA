#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP
#include "../include/table.hpp"
#include "../include/util.hpp"
#include <cstring>
#include <vector>
#include <regex>
#include <cstdlib>

HashTable* Tokenize(char* lineBuffer);

#endif // RYTHON_TOKEN_HPP
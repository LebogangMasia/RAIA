#include "../include/util.hpp"
#include <fstream>
#include <sstream>

char* readFile(const char* path) {
    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file) {
        printf("Could not open file: %s\n", path);
        return nullptr;
    }

    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[fileSize + 1];
    file.read(buffer, fileSize);
    buffer[fileSize] = '\0';
    file.close();

    return buffer;
}

std::ostream& operator<<(std::ostream& os, const TokenType& obj) {
    os << static_cast<std::underlying_type<TokenType>::type>(obj);
    return os;
}

std::vector<TokenType> IdentifyTokens(const char* lineBuf) {
    std::vector<TokenType> types;
    std::string strLineBuf(lineBuf);
    std::vector<std::regex> regexes;
    regexes.emplace_back("\\w+[ ]*=[ ]*[a-z|A-Z|0-9|\"|']*"); // verbatim assignment
    regexes.emplace_back("#.*"); // comment

    for (const auto& regex : regexes) {
        std::sregex_iterator it(strLineBuf.begin(), strLineBuf.end(), regex);
        std::sregex_iterator end;
        while (it != end) {
            if (regex == regexes[0]) {
                types.push_back(TokenType::IDENTIFIER);
                types.push_back(TokenType::OPERATOR);
                types.push_back(TokenType::LITERAL);
            } else if (regex == regexes[1]) {
                types.push_back(TokenType::COMMENT);
            }
            ++it;
        }
    }

    return types;
}

char* intToChar(int a) {
    std::stringstream ss;
    ss << a;
    std::string temp_str = ss.str();
    char* ret = new char[temp_str.size() + 1];
    std::strcpy(ret, temp_str.c_str());
    return ret;
}

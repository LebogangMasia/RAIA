#include "../include/token.hpp"

// Tokenizes the given line buffer
HashTable* Tokenize(char* lineBuffer) {
    HashTable* tokenTable = createTable(50000);
    std::string lineStr(lineBuffer);
    std::string commentStr = lineStr.substr(lineStr.find("#") + 1);
    std::vector<TokenType> validTypes = {TokenType::IDENTIFIER, TokenType::OPERATOR, TokenType::LITERAL};
    std::vector<TokenType> commentType = {TokenType::COMMENT};

    std::vector<TokenType> bufferTypes = IdentifyTokens(lineBuffer);
    if (bufferTypes == validTypes) {
        std::smatch identifierMatch;
        std::smatch operatorMatch;
        std::regex identifierRegex("\\w+\\s*(?==)");
        std::regex operatorRegex("=(?=\\s*'|\\w)");

        char* identifier;
        char* operatorChar;
        char* literal;
        
        if (std::regex_search(lineStr, identifierMatch, identifierRegex)) {
            std::string identifierStr(identifierMatch.str(0));
            identifier = (char*)identifierStr.c_str();
            HashTableInsert(tokenTable, "identifier", identifier);
        }
        
        if (std::regex_search(lineStr, operatorMatch, operatorRegex)) {
            std::string operatorStr(operatorMatch.str(0));
            operatorChar = (char*)operatorStr.c_str();
            HashTableInsert(tokenTable, "operator", operatorChar);
        }
        
        std::string literalStr = lineStr.substr(lineStr.find("=") + 1);
        literal = (char*)literalStr.c_str();
        if (literal)
            HashTableInsert(tokenTable, "literal", literal);
    } 
    else if (bufferTypes == commentType) {
        char* comment = (char*)commentStr.c_str();
        if (comment)
            HashTableInsert(tokenTable, "comment", comment);
    }

    return tokenTable;
}

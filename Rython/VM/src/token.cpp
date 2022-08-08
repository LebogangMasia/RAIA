#include "../include/token.hpp"



HashTable* Tokenize(char* lineBuffer) {
    HashTable* __xLT__ = createTable(50000);
    std::string __llBB__(lineBuffer);
    std::string __CMT = __llBB__.substr(__llBB__.find("#") + 1);
    std::vector<__xxTPT07__> __VTM__AS__ = {__xxTPT07__::IDENTIFIER, __xxTPT07__::OPERATOR, __xxTPT07__::LITERAL};
    std::vector<__xxTPT07__> __CMT__ = {__xxTPT07__::COMMENT};
    // the line buffer
    std::vector<__xxTPT07__> __FRM_BF__ = Iden(lineBuffer);
    if (__FRM_BF__ == __VTM__AS__) {
        std::smatch m1;
        std::smatch m4;
        std::regex __xxTPT01__("\\w+\\s*(?==)");
        std::regex __xxTPT04__("=(?=\\s*'|\\w)");

        char* IDE;
        char* OPE;
        char* LIT;
        if (std::regex_search(__llBB__, m1, __xxTPT01__)) {
            std::string __lm(m1.str(0));
            IDE = (char*) __lm.c_str();
            HashTableInsert(__xLT__, "identifier", IDE);
        }
        if (std::regex_search(__llBB__, m4, __xxTPT04__)) {
            std::string __ldm(m4.str(0));
            OPE = (char*) __ldm.c_str();
            HashTableInsert(__xLT__, "operator", OPE);
        }
        std::string __STRLIT = __llBB__.substr(__llBB__.find("=") + 1);
        LIT = (char*)__STRLIT.c_str();
        if (LIT)
            HashTableInsert(__xLT__, "literal", LIT);
    } else if (__FRM_BF__ == __CMT__) {
        char* COM = (char*)__CMT.c_str();
        if (COM)
            HashTableInsert(__xLT__, "comment", COM);
    }


    return __xLT__;
}
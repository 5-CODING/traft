// standard libraries
#include <string>
#include <iostream>

// implemented libraries
#include "token.hpp"

namespace trf {
    token::token(tk_type type, const std::string& val,
     size_t line, size_t index)
    : type(type), val(val), line(line), index(index) {}

    // this function is for debugging only
    void token::debugPrint() {
        std::string typeStr = "NONE";

        switch (type) {
        case ID:
            typeStr = "\'ID\'";
            break;
        case STR:
            typeStr = "\'STR\'";
            break;
        case NUMBER:
            typeStr = "\'NUMBER\'";
            break;
        default:
            typeStr = '\'' + val + '\'';
            break;
        }

        std::cout << "token(" << typeStr << ", " << 
        val << ", " << line << ", " << index << ")\n";
    }
}
#pragma once

// standard libraries
#include <string>
#include <iostream>

namespace trf {
    enum tk_type {
        ID,
        STR,
        NUMBER,

        ADD,
        MIN,
        DIV,
        MUL,

        EQ,
        NOT_EQ,
        EQEQ,
        GRT_THAN,
        LS_THAN,
        GRT_EQ,
        LS_EQ,
        NOT,

        LEFT_PAREN,
        RIGHT_PAREN,
        LEFT_CURL,
        RIGHT_CURL
    };

    struct token {
        tk_type type;
        std::string val;
        size_t line;
        size_t index;

        token(tk_type, const std::string&, size_t = 0, size_t = 0);
        void debugPrint();
    };
}
#pragma once

// standard libraries
#include <string>
#include <iostream>

namespace trf {
    enum tk_type {
        NONE,
        ID,
        STR,
        NUMBER,

        ADD = '+',
        MIN = '-',
        DIV = '/',
        MUL = '*',

        INC,
        DEC,

        EQ = '=',
        NOT_EQ,
        EQEQ,
        PLUS_EQ,
        MINUS_EQ,
        MUL_EQ,
        DIV_EQ,

        GRT_THAN = '>',
        LS_THAN = '<',
        GRT_EQ,
        LS_EQ,
        NOT = '!',

        LEFT_PAREN = '(',
        RIGHT_PAREN = ')',
        LEFT_CURL = '{',
        RIGHT_CURL = '}'
    };

    struct token {
        tk_type type;
        std::string val;
        size_t line;
        size_t index;

        token(tk_type, const std::string&, size_t = 0, size_t = 0);

        // for debugging only
        void debugPrint();
    };
}
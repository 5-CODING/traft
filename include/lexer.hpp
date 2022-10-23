#pragma once

// standard libraries
#include <string>
#include <iostream>
#include <vector>

// implemented libraries
#include "token.hpp"

namespace trf {
    enum errorCode {
        UNEND_STR
    };

    using vecTok = std::vector<token>;

    class lexer {
        bool is_space(char);
        bool is_alpha(char);
        bool is_num(char);
        bool is_chrop(char);
        bool is_sepr(char);

        bool is_dquote(char);
        bool is_squote(char);

        // for error handling
        void raise_err(errorCode, const token&);

        void push_tok(token&, vecTok&);

    public:
        vecTok get_tokens(const std::string&);
    };
}
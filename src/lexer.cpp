// standard libraries
#include <string>
#include <iostream>
#include <stdexcept>

// implemented libraries
#include "token.hpp"
#include "lexer.hpp"

namespace trf {
    bool lexer::is_space(char c) {
        return c == ' ' || c == '\t';
    }

    bool lexer::is_alpha(char c) {
        return c >= 'a' && c <= 'z' ||
        c >= 'A' && c <= 'Z' ||
        c == '_';
    }

    bool lexer::is_num(char c) {
        return c >= '0' && c <= '9';
    }

    bool lexer::is_chrop(char c) {
        return c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '>' || c == '<' ||
        c == '=' || c == '!';
    }

    bool lexer::is_sepr(char c) {
        return c == '(' || c == ')' ||
        c == '{' || c == '}';
    }

    bool lexer::is_dquote (char c) {
        return c == '\"';
    }

    void lexer::raise_err(errorCode er, const token& __t) {
        switch (er)
        {
        case UNEND_STR:
            throw std::runtime_error(
                std::string("[SYNTAX ERROR] encountered unending string literal\n") +
                std::string("   At Line: ") + std::to_string(__t.line) +
                std::string("\n   At token index: ") + std::to_string(__t.index)
            );
        
        default:
            break;
        }

        throw std::runtime_error("[ERROR] program terminated.");
    }

    void lexer::push_tok(token& __t, vecTok& __x) {
        __x.push_back(__t);

        __t.type = NONE;
        __t.val = "";
        ++__t.index;
    }

    vecTok lexer::get_tokens(const std::string& str) {
        vecTok output;
        token cur_tok{NONE, ""};

        for (auto ch : str) {
            if (ch == '\n') ++cur_tok.line;

            if (is_space(ch)) {
                if (cur_tok.type == NONE)
                    continue;

                if (cur_tok.type == STR) {
                    cur_tok.val += ch;
                    continue;
                }

                push_tok(cur_tok, output);
                continue;
            }

            if (is_alpha(ch)) {
                if (cur_tok.type == NONE) {
                    cur_tok.type = ID;
                    cur_tok.val = ch;

                    continue;
                }

                if (cur_tok.type == ID ||
                    cur_tok.type == STR) {
                    cur_tok.val += ch;
                    continue;
                }

                push_tok(cur_tok, output);
                continue;
            }

            if (is_dquote(ch)) {
                if (cur_tok.type == NONE) {
                    cur_tok.type = STR;
                    continue;
                }

                if (cur_tok.type != STR) {
                    push_tok(cur_tok, output);
                    cur_tok.type = STR;
                    continue;
                }

                push_tok(cur_tok, output);
                continue;
            }

            // ignore any unknown char if it is in a string
            if (cur_tok.type == STR) cur_tok.val += ch;
        }

        if (cur_tok.type == STR) raise_err(UNEND_STR, cur_tok);
        
        if (cur_tok.type != NONE)
            push_tok(cur_tok, output);

        return output;
    }
}
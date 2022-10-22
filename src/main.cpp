// standard libraries
#include <iostream>
#include <string>
#include <vector>

// implemented libraries
#include "token.hpp"

using vecTok = std::vector<trf::token>;

int main() {
    /*
        All of this code is for testing purposes only.
        For more info, check out 'docs/DOCS.md'.
    */
   
    vecTok tokens = {
        trf::token{trf::ID, "print", 0, 0},
        trf::token{trf::LEFT_PAREN, "(", 0, 1},
        trf::token{trf::LEFT_PAREN, ")", 0, 2}
    };

    for (auto i: tokens) {
        i.debugPrint();
    }
}
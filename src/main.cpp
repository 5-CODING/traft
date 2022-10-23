// standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// implemented libraries
#include "token.hpp"
#include "lexer.hpp"

int main() {
    /*
        All of this code is for testing purposes only.
        For more info, check out 'docs/DOCS.md'.
    */
   
    trf::lexer lexr;
    std::string input;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        if (input == ":exit") break;

        try {
            auto vec = lexr.get_tokens(input);

            for (auto i : vec) {
                i.debugPrint();
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}
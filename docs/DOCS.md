# Implementation 1
Created a `token` class under the `trf` namespace.
Each `token` has a `type` (ID, NUMBER, etc...), `value`, `line` and `index`.

### `token` class function summary
1. `void debugPrint(void)` -> prints out info related to the `token` at hand. *(for debugging only)*

# Implementation 2
Created a `lexer` class under the `trf` namespace.
The `lexer` class allows the user to seperate a string into either of these token types:
1. STR
2. ID

### `lexer` class function summary
1. `bool is_space(char)` -> checks if the argument is ' ' (whitespace) or a '\t' (tab)
2. `bool is_alpha(char)` -> checks if the argument is an english alphabet
3. `bool is_num(char)` -> checks if the argument is a number
4. `bool is_chrop(char)` -> check if the argument is a single character operator (+, -, *, /, etc...)
5. `bool is_sepr(char)` -> check if the argument is a seperator (currently unused)

6. `bool is_dquote(char)` -> checks if the argument is a double quote
7. `bool is_squote(char)` -> checks if the argument is a single quote (currently unused)

8. `void raise_err(errorCode, const token&)` -> throws an error with a proper error message based on the arguments
9. `void push_tok(token&, vecTok&)` -> pushes the token to the token vector and resets the token for reuse
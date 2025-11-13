#!bin/bash
gcc src/main.cpp src/Lexer/lex.yy.c src/Parser/Parser.tab.c -lgccjit -Isrc/Parser -o out

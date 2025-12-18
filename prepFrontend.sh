cd ./src/Frontend/Parser
bison -d ./Parser.yy

cd ../../../
cd ./src/Frontend/Lexer

flex Lexer.l

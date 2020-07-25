bison -o producedFiles/parser.tab.c -d parser.y -v

flex -o producedFiles/lexer.lex.c lexer.l

gcc -g producedFiles/parser.tab.c producedFiles/lexer.lex.c ast.c funcs.c eval.c -o bin/interpr -w -lm

# lldb bin/interpr
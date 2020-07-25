/usr/local/opt/bison/bin/bison -o producedFiles/parser.tab.c -d parser.y -v

/usr/local/opt/flex/bin/flex -o producedFiles/lexer.lex.c lexer.l

gcc -g -ll producedFiles/parser.tab.c producedFiles/lexer.lex.c ast.c funcs.c eval.c -o bin/interpr -w

# lldb bin/interpr
# ************
# * MAKEFILE *
# ************
# Author: Nicola Altini

# Interpreter for subset of JS

UNAME := $(shell uname)

all:	  interpr

ifeq ($(UNAME), Linux)
interpr:	lexer.l parser.y ast.h ast.c funcs.h funcs.c eval.c
	./runLinux.sh
endif

ifeq ($(UNAME), Darwin)
interpr:	lexer.l parser.y ast.h ast.c funcs.h funcs.c eval.c
	./runDarwin.sh
endif

clean:
	rm -f bin/interpr \
	producedFiles/lexer.lex.c producedFiles/parser.tab.c producedFiles/parser.tab.h

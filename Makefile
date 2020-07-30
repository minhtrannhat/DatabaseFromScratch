build: ./src/main.c ./src/REPL/input1.h ./src/REPL/inputbuffer.h
	clang -Wall -std=c99 -pedantic ./src/main.c -o bin/database 

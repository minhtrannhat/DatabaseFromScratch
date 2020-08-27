build: ./src/main.c
	clang -Wall -std=c99 -pedantic ./src/main.c -o bin/database 

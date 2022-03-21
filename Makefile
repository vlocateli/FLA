CC=gcc
FLAGS=-Wall -Wextra -Werror -pedantic -ansi -march=native -O3
FILE=code/main.c

all: FLA 

automata:$(FILE)
	$(CC)  $(FLAGS)    $(FILE) -o $@

run: automata
	./automata

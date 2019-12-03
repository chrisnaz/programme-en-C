CC = gcc

all: Programme

Programme: listDoubleChaine.o main.o
	$(CC) -g main.o listDoubleChaine.o -o Programme

main.o: main.c
	$(CC) -c -g main.c

listChaine.o: listDoubleChaine.c
	$(CC) -c -g listDoubleChaine.c

clear:
	@rm *.o main

mrproper:
	@rm -rf listDoubleChaine

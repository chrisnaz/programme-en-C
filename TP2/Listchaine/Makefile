CC = gcc

all: Programme

Programme: listChaine.o main.o
	$(CC) -g main.o listChaine.o -o Programme

main.o: main.c
	$(CC) -c -g main.c

listChaine.o: listChaine.c
	$(CC) -c -g listChaine.c

clear:
	@rm *.o main

mrproper:
	@rm -rf listChaine

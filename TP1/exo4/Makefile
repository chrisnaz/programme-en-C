CC = gcc

all: Programme 

Programme: chaine.o test.o
	$(CC) test.o chaine.o -o Programme

chaine.o: chaine.c
	$(CC) -c chaine.c

test.o: test.c
	$(CC) -c test.c

clear:
	@rm *.o test

mrproper:
	@rm -rf chaine

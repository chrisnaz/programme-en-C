#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

void majuscule (char *chaine){
	int i = 0;
	for (i = 0; chaine[i] != '\0'; i++)
		chaine[i] = toupper(chaine[i]);
}

void copie (char tableau[], char tableaux[], int taille){
	int i;
	tableaux = tableau;
	for (i = 0; i < taille; i++)
		printf("%d\n", tableaux[i]);
}

int main (int agrc, char *argv[]){
	
	int tube1[2];
	int tube2[2];
	pid_t pid;
	char mot[200];
	int compteur = 0;
	char fils[200];
	
	printf("Entre les caractères que vous voulez : ");
	scanf("%s", mot);
	
	if (pipe(tube1)) {
		printf("Pipe failed.\n");
	}
	if (pipe(tube2)) {
		printf("Pipe failed.\n");
	}
	if (pid == -1) {
		printf ("ferreur dans la création du processus");
		exit(1);
	}
	
	else if (pid == 0) {
		
		close(tube1[1]);
		read(tube1[0], mot, strlen(mot));
		copie (mot, fils, strlen(mot));
		majuscule (mot);
		close(tube2[1]);
		write(tube2[0], mot, strlen(mot));
		printf("%s",mot);
		
	}
	else {
		//char pere[];
		close(tube1[0]);
		write(tube1[1], mot, strlen(mot));
		wait(NULL);
		close(tube2[0]);
		read(tube2[1], mot, strlen(mot));
		
	} 
	printf ("%s\n",mot);
	return 0;
}
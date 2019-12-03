#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "listChaine.h"

void viderTampan() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void affichageMenu() {
	printf ("\tMenu\n"
			"1 - Ajouter un élément dans le dictionnaire\n"
			"2 - Supprimer le premier élément du dictionnaire\n"
			"3 - Rechercher un mot dans le dictionnaire\n"
			"4 - Quitter\n");
}

void choixFonction (int c, liste * elem_un1) {
	liste elem_un = * elem_un1;
	char mot [20];
	char definition [3000];
	int i;
	char b [50];
	int tube [2];
	
	//file
	FILE* fichier;
	printf ("Ecrivez le nom du fichier : ");
	scanf ("%s", b);
	fichier = fopen (b, "w");
	
	pid_t pid;
	
	if (pipe(tube)) 
		printf ("Pipe failed.\n");
	
	if (pid == -1) {
		printf ("Erreur dans la création du processus");
		exit(1);
	}
		
		switch (c) {
			case 1 :
				if (pid == 0) {
					close(tube[1]);
					printf ("Entrer le mot : ");
					scanf ("%s", mot);
					printf ("Entrer la définition du mot : ");
					scanf ("%s", definition);
					*elem_un1 = addElement (elem_un, mot, definition);
					fputs (elem_un1, fichier);
					
					
					fclose (fichier);
				break;

			case 2 :
				if (elem_un == NULL) {
					printf ("Aucun dictionnaire\n");
					printf ("\n");
					break;
				}
				*elem_un1 = deleteHead (elem_un);
				printf ("\n");
				break;

			case 3 :
				if (elem_un == NULL) {
					printf ("Aucun dictionnaire\n");
					printf ("\n");
					break;
				}
				printf ("Entrer le mot  à rechercher : ");
				scanf ("%s", mot);
				elem_un = searchElement (elem_un, mot);
				printf ("\n");
				break;

			case 4 :
				exit (EXIT_SUCCESS);
				break;

			default :
				printf ("Aucun choix n'est correspond. \n");
				printf ("\n");
				break;
		}
	}
}

int main (int argc, char * argv[]) {
	liste elem_un = NULL;
	int c;
	while (1) {
		affichageMenu();
		scanf("%d", &c);
		printf("\n");
		viderTampan();
		choixFonction (c, &elem_un);
	}
	return 0;
}
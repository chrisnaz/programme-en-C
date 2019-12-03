#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listChaine.h"

void viderTampan(){
  int c;
  while ((c = getchar ()) != '\n' && c != EOF);
}

void affichageMenu(){
  printf ("\tMenu\n"
    "1 - Ajouter un élément au début du dictionnaire\n"
    "2 - Ajouter un élément à la fin du dictionnaire\n"
    "3 - Supprimer le premier élément du dictionnaire\n"
    "4 - Supprimer le dernier élément du dictionnaire\n"
    "5 - Afficher le dictionnaire\n"
    "6 - Rechercher un mot dans le dictionnaire\n"
    "7 - Ajouter un mot dans emplacement précis\n" //Pas réussi à le faire encore
    "8 - Quitter\n");
}

void choixFonction (int c, liste * elem_un1){
  liste elem_un = *elem_un1;
  char mot [20];
  char definition [2000];
  int i;
  switch (c) {
    case 1 :
      printf ("Entrer le mot : ");
      scanf ("%s", mot);
      printf ("Entrer la définition du mot : ");
      scanf ("%s", definition);
      *elem_un1 = addElemAtBegining (elem_un, mot, definition);
      printf ("\n");
      break;

    case 2 :
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
      }
      printf ("Entrer le mot : ");
      scanf ("%s", mot);
      printf ("Entrer la définition du mot : ");
      scanf ("%s", definition);
      *elem_un1 = addElemAtEnd (elem_un, mot, definition);
      printf ("\n");
      break;

    case 3 :
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
      }
      *elem_un1 = deleteHead (elem_un);
      printf ("\n");
      break;

    case 4 :
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
      }
      *elem_un1 = deleteTail (elem_un);
      printf ("\n");
      break;
		
    case 5 : 
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
      }
      printf("Voici votre dictionnaire\n");
      showList (elem_un);
      printf ("\n");
      break;

    case 6 :
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
      }
      printf ("Entrer le mot à rechercher : ");
      scanf ("%s", mot);
      elem_un = searhElement (elem_un, mot);
      printf ("\n");
      break;

    case 7 :
      if (elem_un == NULL){
        printf("Aucun dictionnaire en memoire\n");
        printf ("\n");
        break;
			}
      printf ("Entrer le mot : ");
      scanf ("%s", mot);
      printf ("Entrer la définition du mot : ");
      scanf ("%s", definition);
      printf ("Entrer son emplacement : ");
      scanf ("%d", &i);
      *elem_un1 = addElemWithIndex (elem_un, mot, definition, i);
      showList (elem_un);
      printf ("\n");
      break;

    case 8 : 
      exit(EXIT_SUCCESS);
      break;
		
    default : 
      printf ("Aucun choix n'est correspond. \n");
      printf ("\n");
      break;
	}
}

int main(int argc, char ** argv){
  liste elem_un = NULL;
  int c;
  while (1) {
    affichageMenu();
    scanf("%d", &c);
    printf("\n");
    viderTampan();
    choixFonction(c, &elem_un);
  }
  return 0;
}

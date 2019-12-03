#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listChaine.h"

// Add a word with and his definition, on the top
liste addElement (liste list, char word[], char def[]) {
	element * newElement = (element *) malloc (sizeof(element));
	strcpy (newElement -> mot, word);
	strcpy (newElement -> definition, def);
	newElement -> next = list;
	return newElement;
}

// Search a word
liste searchElement (liste list, char word[]) {
	element * tmp = list;
	
	while (tmp != NULL) {
		if (strcmp (tmp -> mot, word) == 0)
			printf ("'%s' exite bien dans le dictionnaire", tmp -> mot);
		printf("\n");
		tmp = tmp -> next;
	}
	return NULL;
}

// Delete a word, on the top
liste deleteHead (liste list) {
	if (list != NULL) {
		element * aDelete = list -> next;
		free (list);
		return aDelete;
	}
	else
		return NULL;
}

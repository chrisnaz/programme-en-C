#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chaine.h"

char affiche (char a[]){
	printf ("Le mot est : %s\n",a);
}

int longueur (char a[]){
	int i = 0;
	while (a[i] != '\0')
		++i;
	printf ("Sa longueur est de : %d\n", i);
	return i;
}

int estPalindrome (char a[]){
	int i, j, palindrome = 0;
	for (i = 0, j = strlen(a) - 1; i <= j; ++i, --j){
		if (a[i] == a[j])
			palindrome = 1;
		else {
			palindrome = 0;
			break;
		}
	}
	if (palindrome)
		printf ("1 (cad que c'est un palindrome)\n");
	else
		printf ("0 (cad que ce n'est pas un palindrome)\n");
}


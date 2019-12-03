#include <stdio.h>
#include <stdlib.h>
#include "chaine.h"

int main() {
	char a[10] = "bonjour";
	char b[10] = "malayalam";
	char c [5] = "aba";
	char d [5] = "non";
	char e [10] = "pourquoi";
	
	{
		affiche (a);
		longueur (a);
		estPalindrome (a);
		printf("\n");
	}

	{
		affiche (b);
		longueur (b);
		estPalindrome (b);
		printf("\n");
	
	}

	{
		affiche (c);
		longueur (c);
		estPalindrome (c);
		printf("\n");
	}

	{
		affiche (d);
		longueur (d);
		estPalindrome (d);
		printf("\n");
	}

	{
		affiche (e);
		longueur (e);
		estPalindrome (e);
		printf("\n");
	}
	
	return -1;
}

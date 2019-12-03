#include <stdio.h>
#include <stdlib.h>

int length (char s[]){
	int i = 0;
	while (s[i] != '\0'){
		++ i;
	}
	printf ("%i\n", i);
	return i;
}

int main (int argv, char **argc){
	length ("lui");
	length ("Comment tu vas ?");
	return 0;
}

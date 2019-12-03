#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char argv[]){
	int i, j, palindrome = 0;
	
	//i star at the begining and j star at the end
	for (i = 0, j = strlen (argv) - 1; i <= j; ++i, --j){
		if (argv[i] == argv [j])
			palindrome = 1;
		else {
			palindrome = 0;
			break;
		}
	}

	if (palindrome)
		printf("%s est un palindrome\n",argv);
	else
		printf ("%s n'est pas un palindrome\n", argv);
	
	
	return 0;
}

#include <stdio.h>
#include <string.h>

//Function which check is a word is palindrome
int Palindrome(char s[]) {
	int i, j, palindrome = 0;
	
	//i star at the begining and j star at the end
	for (i = 0, j = strlen (s) - 1; i <= j; ++i, --j){
		if (s[i] == s [j])
			palindrome = 1;
		else {
			palindrome = 0;
			break;
		}
	}

	if (palindrome)
		printf("%s est un palindrome\n",s);
	else
		printf ("%s n'est pas un palindrome\n", s);
}
int main (int argc, char **argv){
	char mot[30];
	
	printf("Entrez un mot : ");
	scanf("%s", mot);
	Palindrome (mot); //Call palindrome's fonction
	//getchar();
	return 0;
}

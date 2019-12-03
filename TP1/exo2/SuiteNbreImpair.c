#include <stdio.h>
#include <stdlib.h>

int main (int agrc, char *argc[]){
	int n, i;
	printf("Entrez votre nombre : ");
	scanf("%d", &n);
	
	//Start of the loop to check if the number is odd
	//And calculate the sum
	int s = 0;
	for (i = 0; i <= n; ++i){
		if (i % 2 == 1){ //Check the odd number
			s = s + i; // make the sum
			printf("%d ",i); //Show the number
		}
	} 
	printf("\n");
	printf("Leur somme vaut %d\n",s); //Show the sum
	return 0;
}

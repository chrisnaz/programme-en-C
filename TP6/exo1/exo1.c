#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


int main (int agrc, char *argv[]){
	
	int tube [2];
	pid_t pid;
	char * data = "je t'envoie des données";
	int compteur = 0;
	
	if (pipe(tube)) {
		printf("Pipe failed.\n");
	}
	if (pid == -1) {
		printf ("ferreur dans la création du processus");
		exit(1);
	}
	else if (pid == 0) {
		close(tube[1]);
		read(tube[0], data, strlen(data));
		
	}
	else {
		close(tube[0]);
		write(tube[1], data, strlen(data));
		wait(NULL);
	} 
	printf ("Voici mon pid : %d\n", getpid());
	//printf ("%s\n",data);
	return 0;
}
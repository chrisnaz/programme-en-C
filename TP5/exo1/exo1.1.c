#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	
	short int Nb_Sig;
	int val_Sig;
	pid_t pid;
	
	pid = fork();
	if (pid) {
		printf ("voici mon pid %d\n", getpid());
	}
	while (1) {}
	return 0;
}
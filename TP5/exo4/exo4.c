#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

pid_t create_process() {
	pid_t pid;
	
	do {
		pid = fork ();
	} while ((pid == -1) && (errno = EAGAIN));
	
	return pid;
}

void fils () {
	for (;;) {}
}

void pere (int child){
	pid_t pid = create_process ();
	char c[1];
	int i = 0;
	printf ("\tMenu\n"
			"s - Pour endormir le processus fils\n"
			"r - Pour redémarrer le processus fils\n"
			"q - Pour tuer le processus fils\n");
	scanf ("%s", c);
	if ((c[i] == 's') || (c[i] == 'S')) {
		sleep(pid);
	}
			
	if ((c[i] == 'r') || (c[i] == 'R')) {
		pid = fork();
		printf ("%d", getpid());
	}
			
	if ((c[i] == 'q') || (c[i] == 'Q')) {
		kill (pid);
	}
}


int main (int argc, char *argv[]){
	pid_t pid = create_process ();
	
	switch (pid) {
		case -1:
			perror ("fork");
			return EXIT_FAILURE;
			break;
		case 0:
			fils();
			break;
		default:
			pere (pid);
			break;
	}
	return 0;
}
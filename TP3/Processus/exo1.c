#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void fils(){
  printf("\n");
  printf("Nous sommes dans le fils\n"
    "Voici son pid : %d.\n"
    "Son PPID est : %d.\n", (int) getpid(), (int) getppid());
}

void pere (int child){
  printf("Nous sommes dans le père\n"
    "Son PID est : %d.\n"
    "Et son PPID est : %d.\n", (int) getpid(), (int) getppid());
}

int main (int argc, char ** argv){
  pid_t pid;
  pid = fork();

  switch (pid){
    case -1:
      perror ("fork");
      exit (EXIT_FAILURE);
      break;
  
    case 0:
      fils();
      break;

    case 1:
      pere(pid);
      break;
  }
  return 0;
}

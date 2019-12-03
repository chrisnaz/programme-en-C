#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

void fils1 (){
  int i;
  for (i = 1; i < 26; i++) {
    printf("%d ",i);
  }
}
void fils2(){
  int i;
  for (i = 26; i < 51; i++) {
    printf ("%d ",i);
  }
  printf("\n");
 }

void pere (){
  printf("Nous sommes dans le père\nSon PID est : %d.\n", (int) getpid());
}

int main (int argc, char ** argv){
  pid_t pid1;
  pid1 = fork();
  pid_t pid2;
  if (pid1 > 0) {
    wait(NULL);
    pid2 = fork();
    if (pid2 == -1){
      perror("fork 2 failed");
      exit(-1);
    }
  printf("\n");
  }

  switch (pid1){
    case -1:
      perror ("fork");
      exit (EXIT_FAILURE);

    case 0:
      fils1();
      break;

    default:
      switch (pid2){
        case -1:
          perror ("fork");
          exit (EXIT_FAILURE);

        case 0:
          fils2();
          break;

        default:
          wait(NULL);
          pere();
          break;
      }
  }
  return 0;
}

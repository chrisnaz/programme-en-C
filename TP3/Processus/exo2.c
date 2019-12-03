#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define TAILLE_MESSAGE 20
#define NB_FILS 4

int main(){

  char message[TAILLE_MESSAGE];
  int i, n, f, fils_nb;
  
  pid_t pid = 1;
  int pipefd[NB_FILS][2];
  int pid_fils[NB_FILS];
  
  for (i = 0; i < NB_FILS; i++){
    if (pid > 0){
      pipe(pipefd[i]);
      pid = fork();
      if (pid > 0){
        pid_fils[i] = pid;
        fils_nb = -1;
      }
      else{
        fils_nb = i;
      }
    }
    
  }

  if (pid == -1){
    perror("fork failed");
    exit(-1);
  }
  
  else if (pid == 0){
  
    f=open("/dev/random",O_RDONLY);
    if (f==-1) {
      perror("Error opening file");
      exit(-1);
    }
    read(f,&n,sizeof(int));
    
    printf("Je suis un fils, mon pid est %d,je choisi le numero %d\n", getpid(), n);
    
    sprintf(message,"%d",n);
    close (pipefd[fils_nb][0]);
    write(pipefd[fils_nb][1], message, TAILLE_MESSAGE );

  }
  
  else{
    for (i = 0; i < NB_FILS; i++){
      wait(NULL);
    }
    for (i = 0; i < NB_FILS; i++){
      close(pipefd[i][1]);
      read(pipefd[i][0], message, TAILLE_MESSAGE );
      printf ("Je suis pere, mon pid est %d, mon fils %d a le numero %s\n",getpid(), pid_fils[i], message);
    }
  }
  return 0;
}
  

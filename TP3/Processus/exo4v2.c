#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char * argv[]) {
    
    //Dans père, crée fils1
    pid_t pid1 = fork();
    
    if (pid1 == -1) {
        perror("fork failed");
        exit(-1);
    }
    else if (pid1 == 0) {
      //Dans fils1, crée fils4
      pid_t pid4 = fork();
    
      if (pid4 == -1) {
          perror("fork failed");
          exit(-1);
      }
      else if (pid4 == 0) {
        //Dans fils4, crée fils7
        pid_t pid7 = fork();
    
        if (pid7 == -1) {
            perror("fork failed");
            exit(-1);
        }
        else if (pid7 > 0) {
          //Fils4 attend fils7
          wait(NULL);
        }
      }
      else{
        //Dans fils1, crée fils5
        pid_t pid5 = fork();
    
        if (pid5 == -1) {
            perror("fork failed");
            exit(-1);
        }
        else if (pid5 > 0) {
          //Fils1 attend ses 2 fils
          wait(NULL);
          wait(NULL);
        }
      }
      
    }
    else {
      //Dans père, crée fils2
      pid_t pid2 = fork();
    
      if( pid2 == -1) {
        perror("fork failed");
        exit(-1);
      }
      else if (pid2 == 0) {
        //Dans fils2, crée fils6
        pid_t pid6 = fork();
    
        if (pid6 == -1) {
            perror("fork failed");
            exit(-1);
        }

        else if (pid6 > 0){
          //Fils2 attend fils6
          wait(NULL);
        }
      }
      else {
        //Dans père, crée fils3
        pid_t pid3 = fork();
    
        if( pid3 == -1) {
            perror("fork failed");
            exit(-1);
        }
        else if (pid3 > 0) {
         //Le père attend ses 3 fils
          wait(NULL);
          wait(NULL);
          wait(NULL);
        }
      }
    }
  printf("Je suis le processus pid: %d, mon père est: %d\n", getpid(), getppid());
  return 0;
}

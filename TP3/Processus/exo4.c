#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main (int argc, char ** argv){
  //déclaration de 7 fils
  int f1, f2, f3, f4, f5, f6, f7;
  printf ("je suis le père :%d\n", getpid());
  f1 = fork(); //fils1

  switch (f1) {
    case  -1 : 
      printf ("erreur dans la création du processus");
      break;
    
    case   0 : 
      printf ("je suis le fils1 , mon pid est: %d \n", getpid());
      //return(5);

      f4 = fork(); //fils4
      switch (f4) {
        case -1:
          printf ("erreur dans la création du processus");
          break;
        
        case 0:
          printf ("je suis le fils4, mon pid est: %d\n", getpid());
          
          f7 = fork(); //fils7
          switch (f7) {
            case -1:
              printf ("erreur dans la création du processus");
              break;

            case 0:
              printf ("je suis le fils7, mon pid est: %d\n", getpid());
              break;
          }
          break;

        default: f5 = fork(); //fils5
          switch (f5) {
            case -1:
              printf ("erreur dans la création du processus");
              break;

            case 0:
              printf ("je suis le fils5, mon pid est: %d\n", getpid());
              break;
          }
          break;
      }
      break;
 
    default : f2 = fork(); //fils2
      switch (f2)  {
        case  -1 : 
          printf ("erreur dans la création du processus");
          break;

        case   0 : 
          printf ("je suis le fils2, mon pid est: %d \n", getpid());
          
          f6 = fork(); //fils6
          switch (f6) {
            case -1:
              printf ("erreur dans la création du processus");
              break;

            case 0:
              printf ("je suis le fils6, mon pid est: %d\n", getpid());
              break;
          }
          break;
 
        default  :f3 = fork();  //fils3           
          switch ( f3 )  {
            case  -1 : 
              printf ("erreur dans la création du processus");
              break;
 
            case   0 : 
              printf ("je suis le fils3, mon pid est: %d \n", getpid());
              //return(3);
              break;
 
            default  : 
              printf ("c'est toujours le père en fin de traitement\n");
              waitpid(f1, NULL, 0);
              waitpid(f2, NULL, 0);
              waitpid(f3, NULL, 0);                                           
           } 
      }
  }
  return 0;
}

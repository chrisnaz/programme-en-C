#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int i = 0; // number of times user has pressed ctrl-c
int max = 1; // maximum number of times user can press ctrl-c

void sig_usr( int signo ); // handles three signals

int main() {
  int done = 0; // while still accepting user input

  // install signals and catch errors if they occur
  if( signal( SIGINT,sig_usr ) == SIG_ERR )
    printf( "n'a pas pu capturer SIGINT\n" );
  
  if( signal( SIGQUIT,sig_usr ) == SIG_ERR )
    printf("n'a pas pu capturer SIGQUIT\n");
  
  if( signal( SIGUSR1,sig_usr ) == SIG_ERR )
    printf("n'a pas pu capturer SIGUSR1\n");
	
  if( signal( SIGUSR2,sig_usr ) == SIG_ERR )
    printf("n'a pas pu capturer SIGUSR2\n");
  
  // while still accepting user input
  while(!done) {
    printf("Attende d'un autre signal ...\n");
    pause();
    /* pause until signal handler
    * has processed signal */
  }
  
  return 0;
}

void sig_usr( int signo ) { /* argument is signal number */

  // user has pressed ctrl-c
  if( signo == SIGINT ) {
   
    // while user is under max number of times of pressing ctrl-c
    if (i < max) {
      signal(SIGINT, sig_usr); // install signal handler
      printf(" C'est la %d fois que vous appuyer sur ctrl-c\n", ++i);
      
      // user has reached limit of number of times they can press ctrl-c
      if (i == max) {
        printf("Vous avez appuyer %d sur ctrl. La prochaine fois c'est la terminaison.\n", max);
        signal(signo, SIG_DFL); // use default action to handle signal (will terminate on next press)
      }
    } 
  } 
  
  /* user has pressed ctrl-\ */
  else if( signo == SIGQUIT ) {
    pid_t pid = fork(); // create child and parent process
    
    // error
    if( pid < 0) {
      perror("fork failed");
      exit(1); 
    }
    
    // child
    if(pid == 0) { 
      printf( "I am the child and I am sending a signal\n" );
      kill(getppid(), SIGUSR1); // kill process
      exit(0);
    } 
    
    // parent 
    else 
      wait((int *)0); // wait for child's process
  } 
  
  // quits program after user has pressed ctrl-\ (from kill() command from child)
  else if( signo == SIGUSR1) {
    printf( "Child sent a signal so I guess you are bored, have a great day!\n" );
    exit(0);
  }

  else if( signo == SIGUSR2) {
    printf( "Child sent a signal so I guess you are bored, have a great day!\n" );
    exit(0);
  }

  // error
  else {
    printf("Error: received signal %d\n",signo);
    exit(1); 
  }
  
  return;
}
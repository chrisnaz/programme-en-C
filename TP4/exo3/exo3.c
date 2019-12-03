#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    perror("this function needs 1 argument");
    exit(-1);
  }
  
  int fd, n;
  char buf[1024];
  
  fd = open(argv[1], O_RDONLY);

  pid_t pid = fork ();
  if (pid == -1) {
    perror("fork failed");
    exit(-1);
  }
  else if (pid == 0) {
    n = read(fd, buf, 10);
    write (1, buf, n);
  }
  else{
    n = read(fd, buf, 5);
    write (1, buf, n);
    wait(NULL);
  }
  close(fd);

  
  return 0;
}

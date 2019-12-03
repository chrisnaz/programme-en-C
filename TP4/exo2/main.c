#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int n;
  char buf[1024];
  
  if (argc != 3) {
    printf ("Ce programme prend 2 arguments.\n");
    exit(EXIT_FAILURE);
  }
  
  struct stat perm;
  stat(argv[1], &perm);
  
  int fd_source = open(argv[1], O_RDONLY);
  int fd_dest = open(argv[2], O_WRONLY | O_CREAT, perm.st_mode);
  
  while ((n = read(fd_source, buf, 1024)) > 0) {
    printf("writing\n");
    write (fd_dest, buf, n);
  }
  close(fd_source);
  close(fd_dest);
  
}

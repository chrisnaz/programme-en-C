#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int fd, n;
  char buf[1024];
  
  for (int i = 1; i< argc; i++) {
    fd = open(argv[i], O_RDONLY);
    while ((n = read(fd, buf, 1024)) > 0) {
      write (1, buf, n);
    }
    close(fd);
  }
  
}

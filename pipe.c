#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define READ 0
#define WRITE 1

int main() {
  int fds[2];
  pipe(fds);

  char line[256];
  pid_t p = fork();
  if (p == 0) {
    //printf("Child: %d\n", getpid());
    close(fds[WRITE]);
    read(fds[READ], line, sizeof(line));
    printf("Child (%d) read: %s", getpid(), line);
  }
  else {
    //printf("Parent: %d\n", getpid());
    printf("Please print a line:\n");
    fgets(line, 256, stdin);
    close(fds[READ]);
    write(fds[WRITE], line, strlen(line));
    printf("Parent (%d) wrote: %s", getpid(), line);
  }

  return 0;
}

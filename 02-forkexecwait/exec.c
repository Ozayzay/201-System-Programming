#include <stdio.h>
#include <unistd.h>

int main() {
  int ret_val = fork();

  if (ret_val == 0) {
    // child process
    printf(" child process \n");

    execlp("ls", "ls", "-a", "-l", "-h", NULL);
  } else {
    // wait for the child process finished
    sleep(1);
    printf(" Parent Process \n");
    execlp("ls", "ls", "-a", NULL);
  }
}

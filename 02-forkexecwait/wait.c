#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t ret_val = fork();

  if (ret_val == 0) {
    // child process
    printf(" child process \n");
    execlp("ls", "ls", "-a", "-l", NULL);

  } else {
    // wait for the child process finished
    int wstatus = 0;
    // returns -1 if failed i.e invalid PID or no child to wait for
    if (waitpid(ret_val, &wstatus, 0) == -1) {
      // since wait pid is a sys call if something goes wrong i.e return -1 it
      // sets errno and we use perror to print it
      perror("waitpid");
      return 1;
    }

    // Use W IF EXITED MACRO to check if program exited normally
    if (WIFEXITED(wstatus)) {
      printf("Child exited with status %d\n", WEXITSTATUS(wstatus));
    } else {
      printf(" Child didn't exit normally \n");
    }

    printf(" Parent Process \n");
  }

  return 0;
}

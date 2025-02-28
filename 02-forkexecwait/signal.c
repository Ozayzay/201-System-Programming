#define _POSIX_C_SOURCE 199309L // Enable full POSIX.1b features
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int sig) { write(STDOUT_FILENO, "Received SIGINT\n", 16); }

int main() {

  pid_t pid = fork();

  if (pid == 0) {
    while (1) {
      sleep(2);
      printf(" Child sending SIGINT to Parent");
      kill(getppid(), SIGINT);
    }
  }

  else {

    // create / instantiate the Struct
    struct sigaction sa;

    // intialize the sig action struct
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    // Register the handler
    if (sigaction(SIGINT, &sa, NULL) == -1) {
      perror("sigaction failed");
      return 1;
    }

    // Infinite loop to keep the program running
    printf("Program running... Press CTRL+C to test the signal handler.\n");
    while (1) {
      sleep(1); // Sleep for 1 second
    }
  }
  return 0;
}

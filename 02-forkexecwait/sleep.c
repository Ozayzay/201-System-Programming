#include <stdio.h>
#include <unistd.h>

int main() {
  int ret_val = fork();
  for (int i = 0; i < 20; i++) {
    if (ret_val == 0) {
      printf("Child %d ", getpid());
    } else {
      printf("Parent %d ", getpid());
    }
    printf("Sleeping%d\n", ret_val);
    sleep(1);
  }
  printf("DONE\n");
  return 0;
}

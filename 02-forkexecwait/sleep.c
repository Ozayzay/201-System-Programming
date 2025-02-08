#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("Hello, Now we wait 5 seconds\n");
  sleep(5);
  printf("Hello again\n");
  printf("lets wait again this time 10 seconds\n");
  sleep(10);
}

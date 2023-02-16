#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void signal_handler(int signum) {
  printf("in signal handler %d\n", signum);
  restore();
}

int main(void) {
  signal(SIGINT, signal_handler);

  int p = fork();
  if(p == 0){
    for(int i = 0; i < 100; i++) {
      printf("hello\n");
      sleep(1);
    }    
  } else {
    // send a signal to child (from system call)
    sleep(5);
    sendSignal(p);
    int status;
    wait(&status);

    // printf("handler address %p\n", handler);
  }
  return 0;
}

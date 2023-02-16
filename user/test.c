#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void signal_handler(int signum) {
  printf("in signal handler %d\n", signum);
  exit(0);
}

int main(void) {
  //uint64 ptr = (uint64)signal_handler;
  //void (*fnptr)(int) = (void (*)(int))ptr;
  //(*fnptr)(SIGINT);
  //test(ptr);
  //uint64 handler = (uint64)signal_handler;
  //printf("calling signal %p\n", handler);
  signal(SIGINT, signal_handler);
  //sendSignal(getpid());

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

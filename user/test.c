#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
// #include "user/signal.h"

void signal_handler(int signum) {
  printf("in signal handler %d\n", signum);
  //exit(0);
}

void test(uint64 pfn) {
  uint32 lo = pfn & 0xFFFFFFFF;
  uint32 hi = (pfn >> 32) & 0xFFFFFFFF;
  printf("test %x%x\n", hi, lo);
}

int main(void) {
  uint64 ptr = (uint64)signal_handler;
  void (*fnptr)(int) = (void (*)(int))ptr;
  //(*fnptr)(SIGINT);
  test(ptr);
  //uint64 handler = (uint64)signal_handler;
  //printf("calling signal %p\n", handler);
  signal(SIGINT, (void*)fnptr);
  //sendSignal(getpid());

  int p = fork();
  if(p == 0){
    for(int i = 0; i < 100; i++) {
      printf("hello\n");
      sleep(1);
    }    
  } else {
    // send a signal to child (from system call)

    //sendSignal(p);
    int status;
    wait(&status);

    // printf("handler address %p\n", handler);
  }
  return 0;
}

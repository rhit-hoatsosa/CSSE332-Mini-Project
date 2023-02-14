#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
// #include "user/signal.h"



void handler(int signum) {
  printf("in signal handler\n");
  // exit(0);

}


int main(void) { 
  // signal(SIGINT, handler);

  int p = fork();
  if(p == 0){
    for (int i = 0; i < 10000; i++) {
      printf("hello\n");
    }    
  }else{
    // send a signal to child (from system call)
    sendSignal(p);
    int status;
    wait(&status);

    // printf("handler address %p\n", handler);
  }

  
  return 0;
}

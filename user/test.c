#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/defs.h"
#include "user/signal.h"
#include "user/user.h"


void print(const char* s)
{
  write(1, s, strlen(s));
}

// void handler(int signum) {
//   print("in signal handler\n");
//   exit(0);
// }


int main(void) { 
  // signal(SIGINT, handler);

  // for (int i = 0; i < 10000; i++) {
  //     print("hello\n");
  //     sleep(1);
  // }

  int p = fork();
  if(p == 0){
    for (int i = 0; i < 10000; i++) {
      print("hello\n");
    }    
  }else{
    // send a signal to child (from system call)
    sendSignal(p, 0);
  }
  return 0;
}

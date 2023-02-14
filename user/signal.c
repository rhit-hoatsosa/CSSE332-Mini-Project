#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"
#include "user/signal.h"



void signal(int signum, void (*func)(int)) {
  // handlers[signum] = func; //updating the handler for signal
  write(1, "signal called\n", strlen("signal called\n"));
}


#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"
#include "user/signal.h"



void signal(int signum, void (*func)(int)) {
  write(1, "signal called\n", strlen("signal called\n"));
}


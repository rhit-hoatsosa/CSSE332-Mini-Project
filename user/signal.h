#define SIGINT  4

void signal(int sig, void (*func)(int));

//stores different signal handlers given user input from signal.c 
void (*handlers)(int)[32]; //arbitrary number

//creating struct for context stack
struct context_stack{
    void* ra,sp,gp,tp;
    int t[7];
    int s[12];
    int a[8];
}
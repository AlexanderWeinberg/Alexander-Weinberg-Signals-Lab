/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int global = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
//   exit(1); //exit after printing
  
  global = 1;
  alarm(1);
}

int main(int argc, char * argv[])
{
   
  signal(SIGALRM,handler); //register handler to handle SIGALRM
   alarm(1); //Schedule a SIGALRM for 1 second
   while(1){ //busy wait for signal to be delivered
      while(global == 0);
      
         printf("Turing was right!\n");
        global = 0;
      
//      sleep(1);
  
   }
  return 0; //never reached
}
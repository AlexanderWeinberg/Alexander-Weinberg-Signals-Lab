/* hello_timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int global_timer = 0;

void startRun(int signum){
      global_timer ++;
      
    printf("%d Seconds\n",global_timer );
    alarm(1);
}

void endRun(int signum){
  printf("   Timer Program ran for %d seconds     \n    ",global_timer);
  exit(0);

}

int main(int argc, char * argv[])
{
  signal(SIGALRM, startRun);
  signal(SIGINT, endRun);
  alarm(1);
  while(1);
  return(0);
}

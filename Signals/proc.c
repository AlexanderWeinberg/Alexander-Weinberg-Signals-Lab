#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAX 5

void SIGINT_handler(int sig){
  printf("In CHild %d - Caught SIGINT",getpid());
}

  void main(int argc, char *arg[]){
    int pid[MAX];
//     int pid;
    int status;
    int count;
    int i;
    sigset_t cmask, origmask;
    
    for(i=0;i<MAX; i++){  //NEVER use while(1)  (while true) => infinite loop
      
      pid[i] = fork();  //creates a child 
  
      srandom(getpid());
  switch(pid[i]){
    case 0:     //child
      
      sigaddset (&cmask, SIGTERM);
      sigaddset (&cmask, SIGINT);
      sigaddset (&cmask, SIGHUB);
      sigaddset (&cmask, SIGUSR1);
      
      if(sigprocmask(SIG_BlOCK, &cmask, &origmask)<0){
        printf("error\n");
      }
     
     
      
      signal(SIGINT, SIGINT_handler);
      printf("In child, pid =%d, parent pid = %d...\n",getpid(), getppid());
      sleep(random() % 3);//sleeps random number betweeen 0 and 3
      
     
      printf("Child Terminates\"ls -l\"..\n"); //displays command specified without executing it
      
      if(sigprocmask(SIG_SETMASK, &origmask, 0)<0){
        printf("error\n");
      }
      
      execl("/bin/ls","-l",(char*)0);
//       exit(0);
      count++;
      break;
      
    case -1:    //error
      break;
      
      
  
    default:  //parent, PID is childpid
    
//      printf("Parent waiting on CHild\n");
//      wait(&status); //parent waits for child to terminate before it reeps child
       
//       wait(NULL); //parent waits for child to terminate before it reeps child
        
      
//       printf("In Parent...\n");
//       exit(0);
      
      
      
      break;
    }
  }
    
    for(i=0;i<MAX; i++){
      kill(getpid(), SIGINT);
     printf("Parent waiting on CHild\n");
     wait(&status); //parent waits for child to terminate before it reeps child
    }
    
    printf("Parent Terminating,   Child Status= %d\n",status);
    printf("amount of forks: %d \n",count);
  
  }
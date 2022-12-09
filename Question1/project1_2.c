#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <math.h>

int main(int argc, char * argv[]){
    int result=atoi(argv[1]);
    printf("Result:%d\n", result);
    pid_t pid;
    int count=0;
    
    
    while(count<result){
        pid=fork();
        if(pid==-1)
            printf("Child process creation was unsuccessful\n");
        else if(pid>0){
            wait(NULL);
            exit(0);
        }        
        else if(pid==0 && count==result-1){
            printf("Last child %d PID: %d from parent ID: %d has terminated\n", count+1, getpid(), getppid());
            exit(0);
        }

        else{
            printf("Hello from child %d PID: %d from parent ID: %d\n", count+1, getpid(), getppid());
        }
        count++;
    }
    
    return 0;
}
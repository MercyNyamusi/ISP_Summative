#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
    int result=atoi(argv[1]);
    printf("Number of child processes:%d\n", result);
    pid_t pid;
    int count=0;
    
    
    while(count<result){
        pid=fork();
        if(pid==-1)
            printf("Child process creation was unsuccessful\n");//converts command line argument to integer
                
        else if(pid==0 && count==result-1){//checks for the last child process
            printf("Last child       %d PID: %d from parent ID: %d has terminated\n", (count+1), getpid(), getppid());
            exit(0);
        }
        else if(pid>0){//parent process
            wait(NULL);//waits for child process

            exit(0);//exits to prevent the parent process from creating its own child process
        }

        else{//other child processes
            printf("Hello from child %d PID: %d from parent ID: %d\n", count+1, getpid(), getppid());
    
        }

        count++;
    }

    return 0;
}
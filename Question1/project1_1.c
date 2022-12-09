#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
    int stat;
    pid_t pid;
    int count =0;
    int result=atoi(argv[1]);//converts command line argument to integer
    printf("Number of child processes:%d\n", result);

    for(int i=0; i<result;i++){
        
        pid=fork();

        if(pid==-1)        //checks whether process has been created successfully
            printf("Child process creation was unsuccessful");
        else{
            count++;
            
            if(pid==0){//child process
                printf("Hello from child %d PID: %d from parent ID: %d\n", count, getpid(), getppid());
                exit(0); //exits to prevent the child process from creating its own child process
            } 
            else{
                wait(NULL);//parent process waiting for child process
            }
        }
        
    }
    printf("Count %d\n",count);

    return 0;
}
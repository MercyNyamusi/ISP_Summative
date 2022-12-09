#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <math.h>

int main(int argc, char * argv[]){
    int stat;
    pid_t pid;
    int count =0;
    int result=atoi(argv[1]);
    for(int i=0; i<result;i++){
        pid=fork();
        if(pid==-1)
            printf("Child process creation was unsuccessful");
        else{
            count++;
            
            if(pid==0){
                printf("Hello from child %d PID: %d from parent ID: %d\n", count, getpid(), getppid());
                exit(0);
            } 
            else{
                wait(NULL);
            }
        }
    }
    printf("Count %d\n",count);

    return 0;
}
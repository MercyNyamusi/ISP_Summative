#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <math.h>

int main(int argc, char * argv[]){
    int result=(int) log2(atoi(argv[1]));
    int number=atoi(argv[1]);
    printf("Result:%d\n", result);
    pid_t pid;
    int count=0;
    for(int i=0;i<result;i++){
       
            pid=fork();
                if(pid==-1){
                    printf("Child process creation was unsuccessful\n");
                }
                else if(pid==0){
                    printf("I am a child process with ID %d from parent %d\n", getpid(), getppid());
                    count++;
                    
                }
                else{
                    wait(NULL);
                }
        

        
    }
    
    return 0;
}
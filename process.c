#include "sys/types.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/wait.h"


int  main(int arc, char *argv[])
{
    pid_t pid_s;

    printf("%d\n",getpid());
    pid_s = fork();
    if (pid_s == 0){
        execv("./printfmain",argv);
    }else if (pid_s > 0){
        waitpid(pid_s, NULL, 0);
    }else {
        printf("error\n");
    }
    
}
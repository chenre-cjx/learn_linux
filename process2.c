#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	/*
	父子孙三代进程实验
	*/
	int pid_f, pid_s, pid_g;        //父子孙进程
	int state_val;
	pid_f = getpid();
	printf("pid_f = %d, ppid = %d\n",getpid(),getppid()); //打印父进程的id

    pid_s = fork();     //创建子进程
    if (pid_s < 0){
        printf("create pid_s error\n");
    }else if (pid_s == 0){      //子进程
        sleep(1);
        printf("I'm pid_s, id is %d, fpid is %d\n",getpid(),getppid());     //打印子进程信息
        pid_g = fork();         //在子进程内创建子进程，即为孙进程
        if (pid_g < 0){
            printf("create pid_g error\n");
        }else if (pid_g == 0){
            sleep(1);
            printf("I'm pid_g, id is %d, fpid is %d\n",getpid(),getppid()); //打印孙进程信息
        } else {
            wait(&state_val);   //子进程等待回收孙进程
        }
    } else {
        wait(&state_val);       //父进程等待回收子进程
    }


	return 0;
}

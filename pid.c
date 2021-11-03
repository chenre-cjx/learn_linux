#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	/*
	三兄弟进程实验
	*/
	int fpid,pid_1,pid_2,pid_3;
	int state_val;
	fpid = getpid();
	printf("fpid = %d, ppid = %d\n",getpid(),getppid());
	pid_1 = fork();

	if (pid_1< 0){						//创建一号兄弟进程
		printf("create pid_1 error\n");
	} else if(pid_1 == 0){
		sleep(1);
		printf("I'm child_1, id is %d, fpid is %d\n",getpid(),getppid());
		
	} else {
		pid_2 = fork();					//创建二号兄弟进程
		if (pid_2 < 0){
			printf("create pid_2 error\n");
		}else if (pid_2 == 0){
			printf("I'm child_2, id is %d, fpid is %d\n",getpid(),getppid());
		}else{
			pid_3 = fork();				//创建三号兄弟进程
			if (pid_3 < 0){
				printf("create pid_2 error\n");
			}else if (pid_3 == 0){
				printf("I'm child_3, id is %d, fpid is %d\n",getpid(),getppid());
			}else{
				printf("fpid is %d, ppid is %d\n",getpid(),getppid());
			}
		}
	}

	if (getpid() == fpid){
		wait(&state_val);
		wait(&state_val);
		wait(&state_val);
	}

	return 0;
}

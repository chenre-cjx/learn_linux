#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int pid;
	printf("fpid = %d, ppid = %d\n",getpid(),getppid());
	pid = fork();

	if (pid < 0){printf("error\n");}
	else if(pid == 0){printf("I'm child, id is %d, fpid is %d\n",getpid(),getppid());}
	else {printf("I'm parent, id is %d, fpid is %d\n",getpid(),getppid());sleep(1);}

	return 0;
}

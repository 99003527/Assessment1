/* Write a program to build multifile program using fork & exec as follows
   * There are multiple source files holding some functions
   * Create multiple child processes to compile each source file (execl/execlp)
   * On successful completion, launch another child process for linking
   * On successful linking, launch another child process for executing
*/

#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int ret,i,status;
	printf("welcome..pid=%d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		printf("child--welcome,pid=%d,ppid=%d\n", getpid(),getppid());
		int k;
                k=execl("/usr/bin/gcc","gcc","sample2.c",NULL);
		if(k<0)
		{
			perror("execl");
			exit(1);
		}
		exit(5);
	}
	else	
	{
		printf("parent--hello,pid=%d,ppid=%d\n", getpid(),getppid());
		waitpid(-1,&status,0); 
		printf("parent--child exit status=%d\n", WEXITSTATUS(status));
	}
	return 0;
}

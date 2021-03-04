/* Design a mini shell(5 - 10 commands) of your own as follows
   * take command name as input from user (string format)
   * launch the command in the child process using execl/execlp
   * parent will wait for completion of child and print exit status
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
		//printf("child--welcome,pid=%d,ppid=%d\n",
			//getpid(),getppid());
        int k;
        char str[20];
        scanf("%s",str);
        k=execl("/usr/bin/pwd",str,NULL);
        //char* argv[]={"ls","-a",NULL};
		//k=execl("/usr/bin/cal", "cal", "10", "2021", NULL);
		if(k<0)
		{
			perror("execl");
			exit(1);
		
        }
        exit(5);
	}
	else	
	{
		printf("parent--hello,pid=%d,ppid=%d\n",
			getpid(),getppid());
		waitpid(-1,&status,0); 
		printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
	}
	return 0;
}
#include<stdio.h>
#include<unistd.h>
int main()
{
  int ret = fork();
  //printf("Hello World\n Ret = %d",ret);
  if(ret == 0)
  {
      execlp("./b.out",NULL);
      printf("\nFrom Child\t PID = %d\n",getpid());
  }
  else
  printf("\nFrom Parent\t PID = %d\n",getppid());
  return 0;
}
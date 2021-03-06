#include<unistd.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
int main()
{
	int File=4096;
	int fd,off=0; //file description & offset
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(fd, File);
	void *pbase;
	pbase=mmap(0,File, PROT_READ, MAP_SHARED,fd,off);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"Mapping was Failed\n");
		exit(1);
	}
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	char buffer[64];
	sem_wait(qs);
	sem_wait(ps);
        strncpy(buffer,pbase,10);
	printf("buffer=%s\n",buffer);
	strcpy(buffer,pbase+10);
	printf("buffer=%s\n",buffer);
	 sem_post(ps);
	sem_unlink("s1");
	sem_unlink("s2");
	munmap(pbase,File);
	return 0;
}
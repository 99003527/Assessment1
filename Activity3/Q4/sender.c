#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret;
	mqd_t msqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=20;
	msqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);
	if(msqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Message queue Here";
	int ln=strlen(str);
	ret=mq_send(msqid,str,ln+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=20;
	mqd_t msqid2;
	msqid2=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&attr2);
	if(msqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlength=256,prio;
	int nbytes=mq_receive(msqid2,buf,maxlength,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("Message from Receiver :%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
	mq_close(msqid);
	mq_close(msqid2);
	return 0;
}
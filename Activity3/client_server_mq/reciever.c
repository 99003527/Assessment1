#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret,msgbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=20;
	mqd_t msqid;
	msqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(msqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int maxlength=256,prio;
	msgbytes=mq_receive(msqid,buffer,maxlength,&prio);
	if(msgbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[msgbytes]='\0';
	printf("Received Message from Sender:%s,nbytes=%d,prio=%d\n",buffer,msgbytes,prio);
	mqd_t msqid2;
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=20;
	msqid2=mq_open("/mque2",O_WRONLY|O_CREAT,0666,&attr2);
	for(int counter=0;buffer[counter]!=NULL;counter++)
    {
        if(buffer[counter]>='A' && buffer[counter]<='Z')
            buffer[counter]=buffer[counter]+32;
        else if(buffer[counter]>='a' && buffer[counter]<='z')
            buffer[counter]=buffer[counter]-32;
    }
	ret=mq_send(msqid2,buffer,msgbytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(msqid);
	mq_close(msqid2);
	return 0;
}
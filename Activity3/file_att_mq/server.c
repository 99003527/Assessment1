#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  int ret, nbytes;
  mqd_t msqid;
  struct mq_attr attr;
  struct stat sb;
  attr.mq_msgsize = 256;
  attr.mq_maxmsg = 10;
  msqid = mq_open("/mque", O_CREAT | O_RDWR, 0666, &attr);
  if (msqid < 0) {
    perror("mq_open");
    exit(1);
  }

  char str[20] = "sample.c";
  ret = mq_send(msqid, str, 20, 5);
  if (ret < 0) {
    perror("mq_send");
    exit(2);
  }

  int maxlen = 256, prio;
  nbytes = mq_receive(msqid, (char *)&sb, 1024, &prio);
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }

  printf("File Attributes\n");
  printf("ID of device is %ld\n", (long)sb.st_dev);
  printf("Inode number is %ld\n", (long)sb.st_ino);
  printf("type of the file");
  switch (sb.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("unknown?\n");
    break;
  }
  printf("Mode is %lo (octal)\n", (unsigned long)sb.st_mode);
  printf("Link count is %ld\n", (long)sb.st_nlink);
  printf("User ID is %ld\n" , (long)sb.st_uid);
  printf("Group ID is %ld\n", (long)sb.st_gid);
  printf("Blocksize for file system I/O is %ld bytes\n", (long)sb.st_blksize);
  printf("size of the file is %lld bytes\n", (long long)sb.st_size);
  printf("Number of 512B Blocks allocated are %lld\n", (long long)sb.st_blocks);
  printf("Last status change was %s", ctime(&sb.st_ctime));
  printf("Last file access is %s", ctime(&sb.st_atime));
  printf("Last file modification was %s", ctime(&sb.st_mtime));
  mq_close(msqid);

  return 0;
}
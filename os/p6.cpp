#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#define BF_SZ 40
#define RD_END 0
#define WR_END 1

int main()
{
 char wm[100];
 printf("Enter the message:");
 gets(wm);
 char write_msg[BF_SZ];
 for(int i=0;i<strlen(wm);i++)
 write_msg[i]=wm[i];
 char read_msg[BF_SZ];
 int fd[2];
 pid_t pid;
 if(pipe(fd)==-1)
 {
   fprintf(stderr,"Pipe Failed");
   return 1;
 }
 pid =fork();
 if(pid<0)
 {
   fprintf(stderr,"Fork Failed");
   return 1;
 }
 if(pid>0)
 {
   close(fd[RD_END]);
   write(fd[WR_END],write_msg,strlen(write_msg)+1);
   close(fd[WR_END]);
 }
 else
 {
   close(fd[WR_END]);
   read(fd[RD_END],read_msg,BF_SZ);
   printf("message is: %s",read_msg);
   close(fd[RD_END]);
 }
 return 0;
}

// Interprocess Communication 
// 1. Program to send msg from parent process to child process.

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int fd[2];
	char buffer[100];
	pipe(fd);
	
	pid_t p;
	p=fork();
	if(p>0)
	{
		close(fd[0]);
		printf("\n Passing Value to child\n");
		int a=write(fd[1],"hello\n",6);
		wait();
	}
	else
	{
		sleep(3);
		close(fd[1]);
		int n=read(fd[0],buffer,100);
		//printf("%d %s",n,buffer);
		write(1,buffer,n);
		
	}
}


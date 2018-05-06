// file copy, fork

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h> 
#include<unistd.h>

void p1()
{
	// write a program to read from console(stdinput) and write to stdoutput(console) using read and write command
	
	char buff[100];
	int n=read(0,buff,20); // 0 is for standard input..
	int z=write(1,buff,n); // 1 is for standard output..
}

void p2()
{
	// write a program to read from console and write to a file name file.txt
	
	char buff[50];
	int n=read(0,buff,50);
	int fd=open("file.txt",O_CREAT | O_RDWR,0777);
	printf("%d",fd); // if fd is negative => file does not made..
	int w=write(fd,buff,n);
	
}

void p3()
{
	char buff[50];
	// copy contents of one file  to another..
	int f1=open("file.txt",O_CREAT | O_RDWR,0777);
	int f2=open("c.txt",O_CREAT | O_RDWR,0777);
	int n=read(f1,buff,50);
	int z=write(f2,buff,n);

}
void p4()
{
	// Try Fork..
	pid_t p;
	p=fork();
	
	if(p==0){
	printf("\n\nchild process with id = %d and parent id =%d ",getpid(),getppid());
	}
	else
	{
	printf("\n\nparent  process with id=%d and parent id= %d ",getpid(),getppid());
	sleep(1);
	}
	
	
}

void p5()
{
	// Test ..why both are printed 4 times ? 
	pid_t p;
	p=fork();
	printf("a\n\n");
	sleep(1);
	p=fork();
	printf("b\n\n");

	fork();

	printf("c\n\n");
	sleep(1);
}

void p6()
{
	// wap to use lseek..
	char buff[100];
	int r=read(0,buff,10);
	int fd=open("test_file_6.txt",O_RDWR | O_CREAT ,0777);
	int ls=lseek(fd,4,SEEK_SET);
	int w=write(fd,buff,r);
	
}

void p7()
{
	// wap to append at begining .. i.e write some content to a file at begining.
	char buff[100];
	int n=read(0,buff,100);	
	int w=write(1,buff,n);
	
	
	int fd=open("test_file_7.txt", O_RDWR |O_CREAT ,0777);
	char file_content[100];
	int y=read(fd,file_content,100);
	
	int s=lseek(fd,0,SEEK_SET);
	
	int x=write(fd,buff,n);
	int s2=lseek(fd,x-1,SEEK_SET);
	
	printf("%d %d %d %d ",fd,n,w ,s2);
	
	int q=write(fd,file_content,y);
	
	

}
void p8()
{
	// wap to create orphan processes..
}

void p9()
{
	// wap to create zombie processes..
}

int main()
{
	
	p4();
 return 0;
}

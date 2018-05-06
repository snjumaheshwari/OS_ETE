#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>


// programs of file ,read,write,open ,lseek ..

void p1()
{
	// write to stdoutput
	int a=write(1,"hello",5);
}

void p2()
{
	// read from screen and write to stdoutput
	char buff[100];
	int r=read(0,buff,100);
	
	int w= write(1,buff,r);
	
}
void p3()
{
	// create file and write contents by taking input from user..
	int fd=open("test_p3.txt",O_CREAT| O_RDWR,0777);
	if(fd<0){
		printf("ERROR In Creating File\n\n");
	}
	else
	{
		char buff[100];
		int r=read(0,buff,100);
		int w=write(fd,buff,r);
		if(w>0)
			printf("SUCCESSFULL");
		
	
	}		
}

void p4()
{
	 // wap to copy content of one file into another..
	 char buff[100];
	 int fd=open("test_p3.txt",O_CREAT |O_RDWR,0777);
	 int r=read(fd,buff,100);
	 int fd2=open("test_p4.txt",O_CREAT |O_RDWR,0777);
	 int w=write(fd2,buff,r);	 
}
void p5()
{
	// wap to copy character by character from one file to another..
	char buff[1];
	int fd=open("test_p3.txt",O_CREAT | O_RDWR,0777);
	int r=read(fd,buff,1);
	
	int fd2=open("test_p5.txt",O_CREAT | O_RDWR,0777);
	
	while(r !=0)	
	{
		int w=write(fd2,buff,1);
		r=read(fd,buff,1);
	}

}

void p6()
{
	 // wap to print first n characters from a file..
	 char buff[100];
	 int fd=open("test_p3.txt",O_CREAT | O_RDWR,0777);
	
	 int n;
	 scanf("%d",&n);
	 
	 int r=read(fd,buff,n);
	 write(1,buff,r);
	 
}

void p7()
{
	// wap to print last n characters form a file..
	 char buff[100];
	 int fd=open("test_p3.txt",O_CREAT | O_RDWR,0777);
	
	 int n;
	 scanf("%d",&n);
	 
	 int l=lseek(fd,-n,SEEK_END);
	// printf("%d\n",l);
		
	 int s=lseek(fd,l-1,SEEK_SET);
		
	int r=read(fd,buff,n);
	 write(1,buff,r);
	
}

s



int main()
{
	p7();	
		
}

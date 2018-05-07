// named pipe..fifo
// This will Requiree 3 different Program To Work..

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


void p1()
{
	// creating fifo / named pipe (1.c)
	int o=mkfifo("Test_6_3_1",0777);
	printf("named pipe created\n");	
}

void p2()
{
	// writing to a file/ named pipe (2.c)
	int o=open("Test_6_3_1",O_WRONLY);
	int w=write(o,"written",7);
	printf("Process %d finished\n",getpid());
	
}

void p3()
{
	// raeding from a named pipe
	char buffer[100];
	int o=open("Test_6_3_1",O_RDONLY);
	int n=read(o,buffer,100);
	
	printf(" Total Bytes Read :%d\n %s was passed to me \n Process %d finished \n",n,buffer,getpid());
}
int main()
{
	//p1(); // compile each program seperatly => gcc -o 1 ete_6_3.c
	//p2(); // gcc -o 2 ete_6_3.c
	p3(); // gcc -o 3 ete_6_3.c
	
}

// run as ./2 & ./3 

// fork system call
#include<unistd.h>
#include<stdio.h>

void p1()
{

	// wap that creates child process of a process i.e process P having child P1
	printf("\n\nMAIN PROCESS WITH PID =%d and ppid=%d\n\n",getpid(),getppid());
	pid_t f=fork();
	if(f==0)
	{
		// child process..
		
			printf("\n\nCHILD PROCESS WITH PID =%d and ppid=%d\n\n",getpid(),getppid());
	}
	else
	{
		// parent process
		printf("\n\nPARENT PROCESS WITH PID =%d and ppid=%d\n\n",getpid(),getppid());
		sleep(1);
	}
	

}

void p2()
{
	// wap to create a child process . The paernt process prints 20 to 29 .
	// and child process print 0-9.
	//Both prints common message..
	
	pid_t f;
	f=fork();
	if(f==0)
	{	// executing child process..
		printf("Child executing\n");
		for(int i=0;i<=9;i++)
			printf("%d\n",i);
	
	}
	else
	{
		// parent process
		printf("parent executing\n");
		for (int i=20;i<=29;i++)
			printf("%d\n",i);
			
			sleep(1);
			
	}
	
	printf("common msg");
	
}


int main()
{
	p2();
	
}

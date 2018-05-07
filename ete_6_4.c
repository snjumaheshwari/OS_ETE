// shared pipe..


#include<unistd.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>

void p1()
{
	// this program creates  a shared memory segment, attaches itself to it 
	//and writes some content into the shared memory segment.
	void *shared_memory;
	char buffer[100];
	int shmid=shmget((key_t)2345,10000,0666 || IPC_CREAT); 
	// creates shared memory segment..
	
	shared_memory=shmat(shmid,NULL,0);	
	// process attached to shared memory segment
	
	
	printf(" Key to shared memory %d\n",shmid);
	printf("Process attached t %X\n",(int)shared_memory);
	
	printf("Enter some data to write into shared memory\n");
	int r=read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf(" You wrote :%s\n",shared_memory);
	
}
void p2()
{
	// this program attaches itself to the shared memory segment created in program1
	//  and then reads whatever was written in the shared memory via program 1
	
	void *shared_memory;
	char buffer[100];
	int shmid=shmget((key_t)2345,10000,0666); 
	// creates shared memory segment..
	
	shared_memory=shmat(shmid,NULL,0);
		// process attached to shared memory segment
	
	
	printf(" Key to shared memory %d\n",shmid);
	printf("Process attached t %X\n",(int)shared_memory);
	
	printf("\n Data read From Shared Memory is :%s\n",shared_memory);
}
int main()
{
	//p1();
	// p2();
}

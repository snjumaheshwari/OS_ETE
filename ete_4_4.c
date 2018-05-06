// Reader Writer Problem..

// process synchronization using semaphore..

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int readcount=0;
sem_t s,wrt;

void *writer(void *args)
{
	sem_wait(&wrt);
	printf("\nWriter is writing");
	sleep(2);
	sem_post(&wrt);
}

void *reader(void *args)
{
	sem_wait(&s);
		readcount++;
		if(readcount==1)
			sem_wait(&wrt);
	sem_post(&s);
	
	printf("\nReader is reading");
	sleep(1);
	
	sem_wait(&s);
		readcount--;
		if(readcount==0)
			sem_post(&wrt);
	sem_post(&s);
}

int main()
{
	pthread_t t1,t2;

	sem_init(&s,0,1);
	sem_init(&wrt,0,1);
	
	pthread_create(&t1,NULL,reader,NULL);
	pthread_create(&t2,NULL,writer,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
		
}

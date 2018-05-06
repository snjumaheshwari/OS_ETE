// producer consumer problem
// process synchronization using semaphore..

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s,e,f;

void *producer(void *args)
{	while(1){
	sem_wait(&e);
	sem_wait(&s);
	printf("\n produer is producing ");
	sleep(2);
	sem_post(&s);
	sem_post(&f);
	}
}


void *consumer(void *args2)
{
	while(1)
	{
	sem_wait(&f);
	sem_wait(&s);
	printf("\n consumer is consuming");
	sleep(2);
	sem_post(&s);
	sem_post(&e);
	}
}

int main()
{
	pthread_t t1,t2;
	int n=10; // buffer size..
	
	sem_init(&s,0,1);
	sem_init(&e,0,n);
	sem_init(&f,0,0);
	
	pthread_create(&t1,NULL,producer,NULL);
	pthread_create(&t2,NULL,consumer,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}

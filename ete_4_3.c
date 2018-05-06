// process synchronization using semaphore..

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a=10;
//pthread_mutex_t lock;
sem_t s;

void *fun(void *args)
{
	//pthread_mutex_lock(&lock);
	sem_wait(&s);
	int x=a;
	sleep(5);
	x=x+1;
	
	a=x;
	//pthread_mutex_unlock(&lock);
	sem_post(&s);
}

void *fun2(void *args2)
{
	//pthread_mutex_lock(&lock);
	sem_wait(&s);
	int y=a;
	sleep(3);
	y=y-1;
	a=y;
	//pthread_mutex_unlock(&lock);
	sem_post(&s);
}

int main()
{
	pthread_t t1,t2;
	
	//pthread_mutex_init(&lock,NULL);
	sem_init(&s,0,1);
	pthread_create(&t1,NULL,fun,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",a);
	
}

// process synchronization using mutex..

#include<stdio.h>
#include<pthread.h>

int a=10;
pthread_mutex_t lock;

void *fun(void *args)
{
	pthread_mutex_lock(&lock);
	int x=a;
	sleep(5);
	x=x+1;
	
	a=x;
	pthread_mutex_unlock(&lock);
}

void *fun2(void *args2)
{
	pthread_mutex_lock(&lock);
	int y=a;
	sleep(3);
	y=y-1;
	a=y;
	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t1,t2;
	
	pthread_mutex_init(&lock,NULL);
	
	pthread_create(&t1,NULL,fun,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",a);
	
}

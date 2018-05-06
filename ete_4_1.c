// process synchronization

// wap to implement race condition

#include<stdio.h>
#include<pthread.h>

int a=10;

void *fun(void *args)
{
	
	int x=a;
	sleep(5);
	x=x+1;
	
	a=x;

}

void *fun2(void *args2)
{
	int y=a;
	//sleep(5);
	y=y-1;
	a=y;
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",a);
	
}

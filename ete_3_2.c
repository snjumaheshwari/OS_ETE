// wap to create a thraed.. thread should print 0 to n .. where value of n is passed by main process.. The main process should wait for thread exec and then prints 20-24..

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>


void* fun(void *args)
{
	int n=*(int *)(args);
	for(int i=0;i<=n;i++)
		printf("%d\n",i);
}

int main()
{
	pthread_t t;
	
	int n;
	scanf("%d",&n);
	
	pthread_create(&t,NULL,fun,&n);
	
	pthread_join(t,NULL);
	
	for (int i=20;i<=24;i++)
		printf("%d\n",i);
	
	

}

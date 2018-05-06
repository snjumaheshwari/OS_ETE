#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

void *fun(void *args)
{
	
	printf("hello thread,%s",(char*)(args));
}

void *fun2(void *args)
{
	/*
	int *ptr=(int*) (args);
	int n= *ptr;
	*/
	int n= *(int*)(args) ;
	for(int i=0;i<n;i++)
	{
		printf("\n%d",i);
	}
	
}

int main()
{
	char *msg="hello";
	pthread_t t1;
	pthread_create(&t1,NULL,fun,msg);
	pthread_join(t1,NULL);
	

	int n;
	scanf("%d",&n);

	pthread_t t2;
	pthread_create(&t2,NULL,fun2,&n);
	pthread_join(t2,NULL);

	return 0;
}





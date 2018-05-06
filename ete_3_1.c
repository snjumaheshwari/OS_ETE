// Thread Concepts..
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void *fun(void *args)
{
	printf("Hello\n");
}

void *fun2(void *args)
{
	printf("world\n");
}

int main(){
		
		pthread_t t1,t2;
		pthread_create(&t1,NULL,fun,NULL);
		pthread_create(&t2,NULL,fun2,NULL);
		
		
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
		
}

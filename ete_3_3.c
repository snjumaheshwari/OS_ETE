// wap to create a thraed.. the thraed is passed more than one input from the main process

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

struct student{
	int a;
	int b;
	char name[100]; // don't use char* => segmentation fault
	float cgpa;
};

void *fun(void* args)
{
	struct student *ptr=args;
	printf("%d %d %s %f",ptr->a,ptr->b,ptr->name,ptr->cgpa);
	
}

int main()
{	
	pthread_t t;
	struct student s1;
	printf(" ENTER DETAILS\n");
	scanf("%d %d %s %f",&s1.a,&s1.b,s1.name,&s1.cgpa);
	pthread_create(&t,NULL,fun,&s1);
	pthread_join(t,NULL);
	return 0;
}


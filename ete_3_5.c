#include<stdio.h>
#include<pthread.h>

struct arg_struct{
	int a;
	int b;
};

void *fun(void *args)
{
	struct arg_struct *ptr=args;
	printf("%d\n",ptr->a);
	printf("%d\n",ptr->b);
}

int main()
{
	pthread_t t;
	struct arg_struct s1;
	s1.a=5;
	s1.b=7;
	pthread_create(&t,NULL,fun,&s1);
	pthread_join(t,NULL);
}

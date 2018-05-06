
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

struct student{
	int rollnum;
	char *name;
	
};
struct student s1;
void *fun(void *args)
{
	struct student *s2=(student*)(args);
	printf("%d",s2->rollnum);
	printf("%s",s2->name);
	 	
}

int main()
{
	pthread_t t1;
	printf("Enter name and roll number\n\n");
	scanf("%d",s1.rollnum);
	scanf("%s",s1.name);			
	pthread_create(&t1,NULL,fun,&s1);
	pthread_join(t1,NULL);
	return 0;
}

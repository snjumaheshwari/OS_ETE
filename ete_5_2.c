// 2. LINKED FILE ALLOCATION ..

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int file[100]={0};
	int x,b;
	printf("\n Enter No Of Blocks That Are Already Allocated");
	scanf("%d",&b);
	
	printf("\n Enter the Block No that are already allocated");
	int a;	
	for(int i=0;i<b;i++)
	{
		scanf("%d",&a);
		file[a]=1;
	}
	
	
	do{
		printf("\n Enter the starting index and length of File to be allocated");
		int s,l;
		scanf("%d %d",&s,&l);
		for(int i=s;i<s+l;i++)
		{
			if(file[i]==0)
			{
				file[i]=1;
				printf("\n %d-> %d",i,file[i]);
			}
			else
			{
				printf("\n %d-> file is already alocated",i);
				l++;
			}
		}
		
		printf("\nPress 1 for more");
		scanf("%d",&x);
		
	}while(x==1);
}

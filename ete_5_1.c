// File Allocation Methods.
	//1. sequential file allocation

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x;
	int file[100]={0};
	do{
		printf("Enter Starting Block and Length Of File\n");
		int s,l;
		scanf("%d %d",&s,&l);
		int flag=0;
		for(int j=s;j<s+l;j++)
		{
			if(file[j]!=0)
				{
				flag=1;
				printf(" Index %d is not vaccent\n",j);
				break;
				}
		}
		
		if(flag==1)
		{
			printf("\nBlock already alocated\n");
		}
		else
		{
			for(int j=s;j<s+l;j++)
			{
				file[j]=1;
				printf("\n%d-> %d",j,file[j]);
			}	
			printf("\nFile alocated Successfully\n");
		}
		printf("Press 1 for more\n");
		scanf("%d",&x);
	}while(x==1);	
}

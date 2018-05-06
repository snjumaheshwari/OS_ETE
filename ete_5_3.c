// Indexed File Allocation ..

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int file[50]={0};
	int index[50]={0};
	
	int x,n;
	do{
		printf("\n Enter index block");
		int b;
		scanf("%d",&b);
		if(file[p]==0)
		{
			file[p]=1;
			printf("\n Enter no of files on Index");
			scanf("%d",&n);
			for(int i=0;i<n;i++)
				scanf("%d",&index[i]);
				
			for(int i=0;i<n;i++)
			{
				if(file[index[i]]==1)
				{
					printf("\n Block Already allocated");
					flag=0;
					break;
				}		
			}
			if(flag!=0)
			{
				for(int i=0;i<n;i++)
					file[index[i]]=1;
					
				printf("\n Allocated");
				printf("\n File Indexed ");
				for(int i=0;i<n;i++)
					printf("\n %d -> %d : %d ",p,index[p],file[index[p]]);
				
			}
		}
		else
		{
			printf("\n Block already allocated");
		}
		
		printf("\n Press 1 for more");
		scanf("%d",&x);
	}while(x==1);
} 


// Program for ipc using popen and pclose


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void p1()
{
	// wap to write into a pipe..
	
	FILE *rd;
	char buffer[100];
	
	int a=sprintf(buffer,"name First");
	
	rd=popen("wc -c","w");
	// wc-c is the process which counts the number of characters passed 
	// 2nd paramater "w" => pipe is opened in write mode..
	
	
	fwrite(buffer,sizeof(char),a,rd);
	// to write data into the pipe..
	
	//printf("%d",a);
	pclose(rd);
	
}
void p2()
{
	// wap to read from a pipe..
	FILE *rd;
	char buffer[100];
	rd=popen("ls","r");
	fread(buffer,1,100,rd);
	printf("%s\n",buffer);
	pclose(rd);
	
}

int main()
{
	p2();
}


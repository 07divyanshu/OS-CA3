#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int fd[2],n,i;
	char buff[100];
	pid_t p;
	pipe(fd);
	p=fork();
	
	if(p>0)
	{
		close(fd[0]);
		printf("\nPassing Hi There to child \n");
		write(fd[1],"Hi There",9);
		wait(NULL);
	}
	else
	{
		close(fd[1]);
		n=read(fd[0],buff,100);
		printf("\n Output is : ");
		for(i=0;i<n;i++)
		{
    			if(buff[i] >= 'A' && buff[i] <= 'Z')
    			{
				buff[i]=buff[i]+32;
        			printf("%c",buff[i]);
    			}
    			else if(buff[i] >= 'a' && buff[i] <= 'z')
    			{
				buff[i]=buff[i]-32;
        			printf("%c",buff[i]);
    			}
			else
			{	
				printf("%c",buff[i]);	
			}
		}
	}
	printf("\n");
}

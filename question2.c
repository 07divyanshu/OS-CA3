#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2],n;
	char buff[100];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0)
	{
		close(fd[0]);
		printf("passing value to child");
		write(fd[1],"hello\n",6);
		wait();
	}
	else
	{
		close(fd[1]);
		n=read(fd[0]),buff,100);
		write(1,buff,n);
	}
}

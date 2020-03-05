#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main (){
	pid_t forkstatus;
	forkstatus = fork();
	if(forkstatus==0){
		printf("I am child\n");
		sleep(5);
		printf("Child quit\n");
	}else{
		printf("I am parent\n");
		wait(NULL);
		printf("Parent quit\n");
	}
	return 0;
}

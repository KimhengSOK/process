#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main (){
	pid_t forkstatus;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	forkstatus=fork();
	if(forkstatus==0){
		for(int i=0;i<5;i++){
			printf("Child Done %d\n",a[i]);
			sleep(1);

		}
	}else{
		for(int j=5;j<10;j++){
			printf("Parent Done %d\n",a[j]);
			sleep(2);
		}
	}
	return 0;
}

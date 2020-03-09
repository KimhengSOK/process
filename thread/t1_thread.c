#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int g = 0;

void *thread(){
	static int s = 0;
	++s;
	++g;
	printf("TID: %ld Static:%d Global:%d\n",pthread_self(),s,g);
}

int main(void){
	int i;
	pthread_t tid;
	for (i=0; i<5; i++){
		pthread_create(&tid, NULL, thread, NULL);
	}
	pthread_exit(NULL);
	return 0;
}


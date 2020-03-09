#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg){
	int val;
	sem_getvalue(&mutex,&val);
	if(val == 1){
		printf("%ld I am entering 5 seconds ....\n",pthread_self());
	}else{
	 	printf("%ld I am waiting ....\n",pthread_self());	
	}
	sem_wait(&mutex);
	printf("%ld I am inside\n",pthread_self());
	sleep(5);
	printf("%ld I am Quit\n",pthread_self());
	sem_post(&mutex);
	
}

int main(void){
	sem_init(&mutex,0,1);
	pthread_t t1,t2,t3,t4;
	pthread_create(&t1,NULL,thread,NULL);
	sleep(2);
	pthread_create(&t2,NULL,thread,NULL);
	sleep(2);
	pthread_create(&t3,NULL,thread,NULL);
	sleep(16);
	pthread_create(&t4,NULL,thread,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	sem_destroy(&mutex);
	return 0;
}

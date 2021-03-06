#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

static int *global_var;

int main(void){
	global_var = mmap(NULL, sizeof *global_var, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*global_var =1;
	printf ("Global variable is 1.\n");

	if(fork()==0){
		*global_var = 5;
		printf("Child process modify share variable to 5\n");
		exit(EXIT_SUCCESS);
	}else{
		wait(NULL);
		printf("Parent process received %d from child\n",*global_var);
		munmap(global_var, sizeof *global_var);
	}
	return 0;
}

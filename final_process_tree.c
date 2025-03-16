	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/wait.h>
	
	#define NUM_CHILDREN 3  // Number of child processes
	
	void print_memory_map(pid_t pid) {
	    char cmd[50];
	    sprintf(cmd, "cat /proc/%d/maps", pid);
     printf("\nMemory map of PID %d:\n", pid);
	    system(cmd);
	}
	
	int main() {
	    pid_t pid;
	    for (int i = 0; i < NUM_CHILDREN; i++) {
	        pid = fork();
	        if (pid == 0) {  // Child process
	            printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
	            print_memory_map(getpid());  // Print memory map of child
	            sleep(2);
	            exit(0);
	        }
	    }
	
	    // Parent waits for all children to terminate
	    for (int i = 0; i < NUM_CHILDREN; i++) {
	        wait(NULL);
	    }
	
	    printf("Parent Process (PID = %d) finished.\n", getpid());
	
	    // Display process tree
	    printf("\nProcess Tree:\n");
	    system("pstree -p");
	
	    return 0;
	}

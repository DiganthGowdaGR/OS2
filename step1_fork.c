	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	
	void print_memory_map(pid_t pid) {
	    char cmd[50];
	    sprintf(cmd, "cat /proc/%d/maps", pid);  // Prepare the command
	    printf("\nMemory map of PID %d:\n", pid);
	    system(cmd);  // Execute the command
	}
	
	int main() {
	    pid_t pid = getpid();
	    printf("Process ID: %d\n", pid);
	    
	    // Print memory segments of the current process
	    print_memory_map(pid);
	
	    return 0;
	}

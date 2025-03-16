#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void print_memory_map(pid_t pid) {
    char cmd[50];
    sprintf(cmd, "cat /proc/%d/maps", pid);  // Prepare the command
    printf("\nMemory map of PID %d:\n", pid);
    system(cmd);  // Execute the command
}

int main() {
    pid_t pid = getpid();
    printf("Parent Process ID: %d\n", pid);

    // Print memory map of the parent process
    print_memory_map(pid);

    // Create child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (child_pid == 0) {  
        // This code runs in the child process
        printf("\nChild Process ID: %d\n", getpid());
        print_memory_map(getpid());
    } else {  
        // This code runs in the parent process
        sleep(1); // Give child some time to execute
        printf("\nParent process (PID: %d) created Child process (PID: %d)\n", getpid(), child_pid);
    }

    return 0;
}

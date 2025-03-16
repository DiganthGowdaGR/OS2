	#include <stdio.h>
	#include <stdlib.h>
	
	int main() {
	    printf("\nProcess Tree:\n");
	    system("pstree -p");  // Print process tree with PIDs
	    return 0;
	}
	

#include "main.h"
#include <unistd.h>
#include <signal.h>

/**
 * exit_application - function to kill all processes  
 */
void exit_application(pid_t child_pid, pid_t parent_pid)
{
	/** terminate parrent */
	kill(parent_pid, SIGTERM);
	/** terminate child */
	kill(child_pid, SIGTERM);
}

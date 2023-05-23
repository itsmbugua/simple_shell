#include "main.h"
#include <unistd.h>
#include <signal.h>

/**
 * exit_application - function to kill all processes  
 */
void exit_application()
{
	pid_t pid;

	pid = getpid();
	kill(pid, SIGTERM);
	sleep(1);
	kill(pid, SIGKILL);
}

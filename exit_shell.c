#include "main.h"
#include <unistd.h>
#include <signal.h>

/**
 * exit_application - function to kill all processes
 *
 * @child_pid: child process id.
 * @parent_pid: parent process id.
 */

void exit_application(pid_t child_pid, pid_t parent_pid)
{
	/** terminate parrent */
	kill(parent_pid, SIGKILL);
	/** terminate child */
	kill(child_pid, SIGKILL);
}

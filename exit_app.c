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
    /* Terminate parent*/
    kill(parent_pid, SIGTERM);

    /* Terminate child*/
    kill(child_pid, SIGTERM);
}

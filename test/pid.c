#include <stdio.h>
#include <unistd.h>
/**
 * main - the main function
 * Return : process id
*/

int main(void)
{
pid_t pid, ppid, c_pid;

/* get the current process id */
pid = getpid();
ppid = getppid();

printf("Process ID is: %d\n", pid);
printf("Parent Procees ID is: %d\n", ppid);

/* starts a child process */
c_pid = fork();

if (c_pid == 0)
{
printf("This is a child process\n");
printf("Parent Process ID (PPID): %d\n", getppid());
printf("Current Process ID (PID): %d\n", getpid());
}
else if (c_pid > 0)
{
printf("This is a Parent Process:\n");
printf("Child Process ID (PID): %d\n", c_pid);
}
else
{
printf("FAILED");
return (1);
}

return (0);
}

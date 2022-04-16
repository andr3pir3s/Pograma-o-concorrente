#include <stdio.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{   
    pid_t pid_to_kill;
    int kill_return;

    printf("Enter the PID you want to finish: ");
    scanf("%d",&pid_to_kill);

    kill_return = kill(pid_to_kill, SIGHUP);

    if (!kill_return)
    {   
        printf("PID %d was successfuly killed\n", pid_to_kill);
    }
    else
    {
        printf("Operation failed! process with PID %d was not killed\n",
                pid_to_kill);
    }
    return 0;
}

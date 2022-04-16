#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>

int main()
{
    /* int kill(pid_t, int signal) o retorno mostra
    se a chamada da função foi bem sucessida, sucessful = 0*/

    pid_t fork_return;

    printf("[PARENT] i'm the process parent and my PID is %d\n", getpid());

    fork_return = fork();

    // por pura preguiça eu não testo se o fork deu falha.
    if (fork_return == 0)
    {   //child
        printf("[CHILD] i'm the child process and my PID is %d\n", getpid());
        printf("[CHILD] sleeping for 30s...\n");
        sleep(30);
    }
    else
    {   // Parent
        int kill_return;
        char c;
        printf("[PARENT] i'm going to finish the child process\n");
        printf("[PARENT] child process PID is %d\n",fork_return);
        printf("[PARENT] Press <ENTER> to finish child process:");
        scanf("%c", &c);
        kill_return = kill(fork_return, SIGHUP);
        if (!kill_return)
            printf("[PARENT] kill sucessfuly done! PID %d\n", fork_return);
        printf("[PARENT] sleeping for 10s...\n");
        sleep(10);
    }
    return 0;
}

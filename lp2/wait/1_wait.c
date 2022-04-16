#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t fork_return;
    int user_value;
    int child_return;

    printf("ORIGINAL: original process, PID: %d\n", getpid());
    printf("ORIGINAL: before fork()...\n\n");

    fork_return = fork();

    if (fork_return >= 0)
    {
        //fork sucessful
        if (fork_return == 0)
        {
            // clone process
            printf("CLONADO: i'm the child process!\n");
            printf("CLONADO: PID %d\n", getpid());
            printf("CLONADO: My dad's PID %d\n", getppid());
            printf("CLONADO: sleeping for 5s...\n");
            sleep(5);
            printf("CLONADO: type an integer (0 to 255): ");
            scanf("%d", &user_value);
            printf("CLONADO: gotta go sending the user's value: %d\n", user_value);
            exit(user_value); // finaliza o processo e manda para o S.O o valor dá 
        }
        else
        {
            // Original process
            printf("ORIGINAL: i'm father process\n");
            printf("ORIGINAL: my PID %d\n", getpid());
            printf("ORIGINAL: waiting child process be gone...\n\n");
            wait(&child_return);
            printf("\nORIGINAL: child process returned: %d\n", WEXITSTATUS(child_return));
            printf("ORIGINAL: need to go, bye!\n");
            exit(0);
        }
    }
    else
    {
        printf("Damn bro fork has failed!\n");
        exit(-1);
    }
    return 0;
}

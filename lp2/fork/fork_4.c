#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fork_return;
    int qnt;

    printf("Digite  a quantidade de processos que deseja criar: ");
    scanf("%d",&qnt);
    
    fork_return = fork();

    if (fork_return > 0)
    {
        for (int i = 0; i < (qnt - 1); i++)
        {
            if (fork_return > 0)
                fork_return = fork();
        }
    }
    printf("Mensagem depois do Fork()\n");
    sleep(5);
    printf("processo finalizando... meu PID era: %d\n", getpid());

    return 0;
}

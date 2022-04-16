#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define QUANTIDADE_LISTA 5
#define TAM_STR 8
#define STR_TESTE "AAAAAAA"

int main(void)
{   
    int i;
    pid_t fork_return;
    char* lista[QUANTIDADE_LISTA+1];
    char* tmp[] = {"ABC", "DEF", "XYZ", NULL};

    for ( i = 0; i < QUANTIDADE_LISTA; i++)
    {
        lista[i] = (char*) malloc(sizeof(char)*TAM_STR);
        strcpy(lista[i], STR_TESTE);
    }

    lista[i] = NULL; // para saber que chegou no fim da lista

    fork_return = fork();

    if (fork_return == 0)
    {
        // processo filho 1
        printf("[Exec] primeira execucao\n");
        sleep(15);
        execl("mostra", "ABC", "XYZ", NULL);
    }
    else
    {
        // processo pai
        fork_return = fork();

        if (fork_return == 0)
        {
            // processo filho 2
            printf("[Exec] Segunda execucao\n");
            sleep(15);
            execv("mostra", lista);
        }
        else
        {
            // processo pai
            fork_return = fork();

            if (fork_return == 0)
            {
                // processo filkho 3
            printf("[Exec] Terceira execucao\n");
            sleep(15);
            execve("mostra", tmp, NULL);
            }
        }
    }
    sleep(15);
    return 0;
}

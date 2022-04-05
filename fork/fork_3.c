#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
    Exemplo de uso da função fork()
    - invocações sucessivas da função fork()
    - processos dormem por 15s
    - só o processo pai se clona, controlando o número
      de processos gerados.
*/

int main(int argc, char const *argv[])
{
    int fork_return;
    char c;
    printf("Mensagem antes da invocacao do fork!\n");
    printf("Meu PID: %d\n", getpid());
    printf("Pressione <<Enter>> para clonar este processo: ");
    scanf("%c", &c);

    fork_return = fork();

    if (fork_return > 0)
    { // processo pai
        fork();
    }
    printf("Mensagem depois do Fork()\n");
    sleep(15);
    printf("Processo finalizando...\n");
    return 0;
}

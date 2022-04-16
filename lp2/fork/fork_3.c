#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

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
    int qnt;
    printf("Mensagem antes da invocacao do fork!\n");
    printf("Meu PID: %d\n", getpid());
    printf("insira a quantidade de processos que deseja criar: ");
    scanf("%d", &qnt);

    if (qnt > 1)
    {
        for (int i = 2; i < qnt; i++)
        {
            if ((fork_return = fork()) > 0)
            { // processo pai
                fork();
            } 
        }       
    }
    printf("Mensagem depois do Fork()\n");
    sleep(5);
    printf("Processo finalizando...\n");
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
    Exemplo de uso da função fork()
    clona o processo e testa o valor de retorno
    da função fork, executando instrções diferentes
    no processo pai e no processo filho.
*/

int main(int argc, char const *argv[])
{
    int fork_return;
    char c;

    printf("Sou o processo original\n");
    printf("Mensagem antes da invocacao do fork!\n");
    printf("Meu PID: %d\n", getpid());
    printf("Pressione <<Enter>> para clonar este processo: ");
    scanf("%c", &c);

    fork_return = fork();
    /*
    fork_return > 0   (execução do processo pai)
    fork_return == 0  (execução do processo filho)
    fork_return == -1 (erro, não houve clonagem)
    */

    if (fork_return > -1)
    {
        if (fork_return == 0)
        { // só será executado pelo processo clonado
            printf("\nSou o processo clonado!\nretorno do fork: %d\n",
            fork_return);
            sleep(20);
            printf("Sou o processo clonado e vou terminar, meu PID era: %d\n", getpid());
        }
        else
        {   // só será executado pelo processo original
            printf("\nSou o processo original!\nretorno do fork: %d\n",
            fork_return);
            sleep(20);
            printf("Sou o processo original e vou terminar, meu PID era: %d\n", getpid());
        } 
    }
    return 0;
}

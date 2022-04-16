#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
O processo que usa da função wait() espera um processo filho finalizar
para então proseguir seu andamento. a função wait retorna o PID do processo
filho que finalizou.
*/

int main(int argc, char const *argv[])
{
    char c;
    pid_t fork_return;
    pid_t fork_return2;

    printf("[P] Mensagem antes do Fork()\n");
    printf("[P] Aperte <ENTER> para criar 2 processos: ");
    scanf("%c", &c);

    fork_return = fork();

    if (fork_return > 0)
    {   
        // processo Pai
        fork_return2 = fork();

        if (fork_return2 > 0)
        {   
            // processo Pai
            int exit_value, wait_value;
            wait_value = wait(&exit_value);

            printf("[P] Valor de saida do processo clonado: %d\n",
                    WEXITSTATUS(exit_value));
            printf("[P] PID do processo que finalizou primeiro: %d\n",
                    wait_value);
        }
        else
        {
            // segundo processo clonado
            time_t t;
            printf("[2F] Sou o processo 2F PID %d\n", getpid());
            srand((unsigned)time(&t)+getpid());
            int dormir = rand()%20; 
            dormir++;
            printf("[2F] Vou dormir %ds e sair...\n", dormir);
            sleep(dormir);
            exit(2);
        }
    }
    else
    {
        // primeiro processo clonado
        time_t t;
        printf("[1F] sou o processo 1F PID %d\n", getpid());
        srand((unsigned)time(&t)+getpid());
        int dormir = rand()%20; 
        dormir++;// dormir tem um valor random entre 1 e 20
        printf("[1F] vou dormir %ds e sair...\n", dormir);
        sleep(dormir);
        exit(1);
    }
    printf("Processo Pai finalizando... meu PID era: %d\n",getpid());
    return 0;
}

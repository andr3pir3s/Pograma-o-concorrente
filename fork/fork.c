#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    char c;
    printf("Programa que se colnara'\n");
    printf("Aperte qualquer tecla para clonar essa execucao: ");
    scanf("%c", &c); /* bloqueia até usuário inserir valor*/
    fork(); /* clona processo em execução*/
    /*mensagens abaixo aparecerão clonadas*/
    printf("Mensagem apos o fork(clonagem)!\n");
    printf("Dormirei por 15s\n");
    sleep(15);// verificar (ps/top/ gerenciador de tarefas)
             //  a existencia do processo clonado.
    printf("Finalizando as duas instancias!\n");

    return 0;
}

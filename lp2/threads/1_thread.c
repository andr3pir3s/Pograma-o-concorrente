#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS_NUM 2

int varGlobal;

void* fun_thread(void* param)
{
    printf("Dentro da fun_thread. VarGlobal = %d\n", varGlobal);
    sleep(10);
    varGlobal++;
    printf("Saindo da func_thread. VarGlobal = %d\n", varGlobal);
}

int main(int argc, char const *argv[])
{
    varGlobal = 10;
    pthread_t threads[2];

    printf("Dentro da funcao Main()\n");
    printf("Vou criar duas threads!\n");

    for (int i = 0; i < THREADS_NUM; i++)
        pthread_create(&threads[i], NULL, fun_thread, NULL);
    sleep(15);
    
    printf("Saindo da Main(). VarGlobal = %d\n", varGlobal);
    return 0;
}

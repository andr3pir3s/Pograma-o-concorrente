#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define QTD_THREADS 5

long var_global;

void* func_thread (void* param)
{
    long id = (long)param; // o parametro passado é o índice da thread+1
    printf("[#%ld] Thread %ld criada!\n", id, id);
    sleep(5);
    var_global++;
    printf("[#%ld] var_global = %ld\n", id, var_global);
    pthread_exit((void*) var_global + id);
}

int main(int argc, char const *argv[])
{
    pthread_t threads[QTD_THREADS]; // Array das Threads
    int thread_return[QTD_THREADS]; // Array para armazenar o retorno da func_thread
    var_global = 0;

    printf("[Main] Iniciando Thread principal...\n");
    printf("[Main] criando %d threads...\n", QTD_THREADS);

    for (long i = 0; i < QTD_THREADS; i++)
    {   // Criando as Threads
        pthread_create(&threads[i], NULL, func_thread,(void*) (i+1));
    }
    
    for (int i = 0; i < QTD_THREADS; i++)
    {   // faz join para todas as threads
        printf("[Main] Aguardando termino da thread %d\n", (i+1));
        pthread_join(threads[i],(void*) &thread_return[i]);
        printf("[Main] Thread %d retornou %d\n", (i + 1), thread_return[i]);
    }
    
    printf("[Main] finalizando Thread main...!\n");
    return 0;
}

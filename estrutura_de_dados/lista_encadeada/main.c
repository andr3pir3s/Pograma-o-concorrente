#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
Implementação de um TAD de lista encadeada
*/

int main()
{
    Lista *lista;
    lista = lst_cria();
    /*lst_insere_inicio(&lista, 1);
    lst_insere_inicio(&lista, 2);
    lst_insere_inicio(&lista, 3);
    lst_imprime(lista);*/
    lst_insere_fim(&lista,1);
    lst_insere_fim(&lista,2);
    lst_insere_fim(&lista,3);
    lst_imprime(lista);
    lst_retira(&lista, 2);
    lst_retira(&lista, 1);
    lst_imprime(lista);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista{
    int info;
    struct lista* prox;
};

/* função de criação: retorna uma lista vazia*/
Lista* lst_cria(void)
{
    return NULL;
}

/*inserção ni ínicio: retorna a lista atualizada*/
void lst_insere_inicio (Lista **l, int i)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = *l; /* aponta para o que estava no inicio*/
    *l = novo;
}

void lst_imprime(Lista *l)
{
    Lista *p; /* ponteiro auxiliar para percorrer a lista*/
    for (p = l; p != NULL; p= p->prox)
        printf("%d ", p->info);
    printf("\n");
}

/* se vazia retorna 1 senão 0*/
int lst_vazia(Lista* l)
{
    return (l == NULL);
}

/* busca um elemento na lista*/
Lista* lst_busca(Lista* l, int v)
{
    Lista *p;
    for (p = l; p != NULL; p=p->prox)
    {
        if (p->info == v)
        return p;
    }
    return NULL; /* não achou o elemento*/
}

void lst_retira(Lista** l, int v)
{
    Lista* back = NULL;
    Lista* front = *l;

    /* procura o elemento na lista, guardando anterior*/
    while (front->info != v && front != NULL)
    {
        back = front;
        front = front->prox;
    }
    
    /* se o numermo for o primeiro da lista*/
    if (back == NULL)
    {
        *l = front->prox;
    }
    else
    {
        back->prox = front->prox;
    }
    free(front);
}

void lst_libera (Lista** l)
{
    Lista* back = *l;
    Lista* front;
    while ( back != NULL)
    {
        front = back->prox;
        free(back);
        back = front;
    }
    *l = NULL; // após todos os frees o ponteiro de lista apontará para null
}

void lst_insere_fim(Lista** l, int i)
{
    Lista* p = *l;
    if (*l == NULL)
    {
        p = (Lista*) malloc(sizeof(Lista*));
        p->info = i;
        p->prox = NULL;
        *l = p;
    }
    else
    {   
        while(p->prox != NULL)
        {
            p = p->prox;
        }
        Lista* novo = (Lista*) malloc(sizeof(Lista*));
        novo->info = i;
        novo->prox = NULL;
        p->prox = novo;
    }
}

void lst_insere(Lista** l, int i, int ant)
{
    Lista* p = *l;
    {   
        while(p->info != ant)
        {
            p = p->prox;
        }
        Lista* novo = (Lista*) malloc(sizeof(Lista*));
        novo->info = i;
        novo->prox = p->prox;
        p->prox = novo;
    }
}
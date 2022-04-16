#ifndef LISTA
#define LISTA

typedef struct lista Lista;

Lista* lst_cria (void);
void lst_insere_inicio (Lista **l, int i);
void lst_insere_fim(Lista** l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
void lst_retira(Lista** l, int v);
void lst_libera (Lista** l);
void lst_insere(Lista** l, int i, int ant);

#endif
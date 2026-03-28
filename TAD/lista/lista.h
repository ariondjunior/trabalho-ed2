#ifndef LISTA_H_
#define LISTA_H_

#include "../no.h"

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

void inicializar_l(Lista *l);
void inserir_fim(Lista *l, int valor);
int remover(Lista *l, int valor);
No* buscar(Lista *l, int valor);
void imprimir_l(Lista *l);
void liberar_l(Lista *l);

#endif /* LISTA_H_ */
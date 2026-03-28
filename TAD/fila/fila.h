#ifndef FILA_H_
#define FILA_H_

#include "../no.h"

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializar_f(Fila *f);
void enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
void imprimir_f(Fila *f);
void liberar_f(Fila *f);


#endif /* FILA_H_ */
#ifndef FILA_H_
#define FILA_H_

#include "../no.h"

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

Fila* inicializar_f();
void enfileirar(Fila *f, Cliente valor);
int desenfileirar(Fila *f, Cliente *c);
void imprimir_f(Fila *f);
void liberar_f(Fila *f);


#endif /* FILA_H_ */

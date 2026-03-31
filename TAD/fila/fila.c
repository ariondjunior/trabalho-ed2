#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "../no.h"
#include "../cliente.h"


Fila* inicializar_f() 
{
    Fila* f = (Fila *) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return f;
}

void enfileirar(Fila *f, Cliente valor) 
{
    if (!f) return;

    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->info = valor;
        novo->prox = NULL;

        if (f->inicio == NULL) {
            f->inicio = novo;
        } else {
            f->fim->prox = novo;
        }
        
        f->fim = novo;
        f->tamanho++;
    }
}

int desenfileirar(Fila *f, Cliente* c) {
    if (f == NULL || f->inicio == NULL) {
        return 0;
    }

    No *aux = f->inicio;
    *c = aux->info;

    f->inicio = aux->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(aux);
    f->tamanho--;

    return 1;
}

void imprimir_f(Fila *f) {
    No *aux;

    if (!f) {
        printf("Fila inexistente.\n");
        return;
    }

    aux = f->inicio;
    printf("Inicio -> ");
    while (aux != NULL) {
        printf("[%s] ", aux->info.nome);
        aux = aux->prox;
    }
    printf("<- Fim\n");
}

void liberar_f(Fila *f) {
    Cliente descartado;

    if (!f) return;

    while (f->inicio != NULL) {
        desenfileirar(f, &descartado);
    }

    free(f);
}

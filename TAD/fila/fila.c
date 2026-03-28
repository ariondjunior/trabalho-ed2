#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "../no.h"


void inicializar_f(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void enfileirar(Fila *f, int valor) {
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

int desenfileirar(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    No *aux = f->inicio;
    int valor = aux->info;

    f->inicio = aux->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(aux);
    f->tamanho--;
    return valor;
}

void imprimir_f(Fila *f) {
    No *aux = f->inicio;
    printf("Inicio -> ");
    while (aux != NULL) {
        printf("[%d] ", aux->info);
        aux = aux->prox;
    }
    printf("<- Fim\n");
}

void liberar_f(Fila *f) {
    while (f->inicio != NULL) {
        desenfileirar(f);
    }
}
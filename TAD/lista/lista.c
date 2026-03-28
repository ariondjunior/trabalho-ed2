#include <stdio.h>
#include <stdlib.h>
#include "../no.h"
#include "lista.h"

void inicializar_l(Lista *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

void inserir_inicio(Lista *l, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->info = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tamanho++;
    }
}

void inserir_fim(Lista *l, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return;
    
    novo->info = valor;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->tamanho++;
}

int remover(Lista *l, int valor) {
    No *aux = l->inicio;
    No *anterior = NULL;

    while (aux != NULL && aux->info != valor) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) return 0;

    if (anterior == NULL) {
        l->inicio = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
    l->tamanho--;
    return 1;
}

No* buscar(Lista *l, int valor) {
    No *aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void imprimir_l(Lista *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        printf("[%d] -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberar_l(Lista *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        No *proximo = aux->prox;
        free(aux);
        aux = proximo;
    }
    l->inicio = NULL;
    l->tamanho = 0;
}
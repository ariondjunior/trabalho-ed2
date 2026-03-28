#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "../no.h"

void inicializar_p(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

void push(Pilha *p, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->info = valor;
        novo->prox = p->topo;
        p->topo = novo;
        p->tamanho++;
    }
}

int pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    
    No *aux = p->topo;
    int valor = aux->info;
    
    p->topo = aux->prox;
    free(aux);
    p->tamanho--;
    
    return valor;
}

int topo(Pilha *p) {
    if (p->topo != NULL) {
        return p->topo->info;
    }
    return -1;
}

int vazia(Pilha *p) {
    return (p->topo == NULL);
}

void imprimir_p(Pilha *p) {
    No *aux = p->topo;
    printf("Topo -> ");
    while (aux != NULL) {
        printf("[%d]\n        ", aux->info);
        aux = aux->prox;
    }
    printf("Base (NULL)\n");
}

void liberar_p(Pilha *p) {
    while (!vazia(p)) {
        pop(p);
    }
}

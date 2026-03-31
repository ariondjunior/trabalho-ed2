#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadc.h"
ListaDc* criarListaDc()
{
    ListaDc* l = (ListaDc *) malloc(sizeof(ListaDc));
    l->inicio = NULL;
    l->fim = NULL;
    l->atual = NULL;
    l->tamanho = 0;
    return l;
}

void inserirFimListaDc(ListaDc *l, Cliente c)
{
    if (!l) return;

    NoDc* novo = (NoDc *) malloc(sizeof(NoDc));
    if (!novo) return;

    novo->info = c;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (l->fim != NULL)
        l->fim->prox = novo;
    else
        l->inicio = novo;

    l->fim = novo;
    l->tamanho++;
}

void liberarListaDc(ListaDc* l)
{
    NoDc* p = l->inicio;
    while (p != NULL)   
    {
        NoDc* temp = p;
        p = p->prox;
        free(temp);
    }

    free(l);
}

int removerInicioListaDc(ListaDc* l, Cliente* c) {
    if (!l || !l->inicio) return 0;

    NoDc* temp = l->inicio;
    *c = temp->info;

    l->inicio = temp->prox;

    if (l->inicio)
        l->inicio->ant = NULL;
    else
        l->fim = NULL;

    if (l->atual == temp)
        l->atual = l->inicio;

    free(temp);
    l->tamanho--;

    return 1;
}

int removerAtualListaDc(ListaDc* l, Cliente* c) {
    NoDc* temp;

    if (!l || !l->atual) return 0;

    temp = l->atual;
    *c = temp->info;

    if (temp->ant)
        temp->ant->prox = temp->prox;
    else
        l->inicio = temp->prox;

    if (temp->prox)
        temp->prox->ant = temp->ant;
    else
        l->fim = temp->ant;

    if (temp->prox)
        l->atual = temp->prox;
    else
        l->atual = temp->ant;

    free(temp);
    l->tamanho--;

    return 1;
}

int iniciarNavegacao(ListaDc* l)
{
    if (!l || !l->inicio) return 0;

    l->atual = l->inicio;
    return 1;
}

int proximoListaDc(ListaDc* l, Cliente* c)
{
    if (!l || !l->atual) return 0;

    if (l->atual->prox)
        l->atual = l->atual->prox;
    
    *c = l->atual->info;
    return 1;
}

int anteriorListaDc(ListaDc* l, Cliente* c) {
    if (!l || !l->atual) return 0;

    if (l->atual->ant)
        l->atual = l->atual->ant;

    *c = l->atual->info;
    return 1;
}

int obterAtualListaDc(ListaDc* l, Cliente* c) {
    if (!l || !l->atual) return 0;

    *c = l->atual->info;
    return 1;
}

int buscarListaDc(ListaDc* l, const char* nome, Cliente* c) {
    if (!l) return 0;

    NoDc* p = l->inicio;

    while (p) {
        if (strcmp(p->info.nome, nome) == 0) {
            l->atual = p;
            *c = p->info;
            return 1;
        }
        p = p->prox;
    }

    return 0;
}

int tamanhoListaListaDc(ListaDc* l) {
    if (!l) return 0;
    return l->tamanho;
}

int listaVaziaListaDc(ListaDc* l) {
    return (l == NULL || l->tamanho == 0);
}

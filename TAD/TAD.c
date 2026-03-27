#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;


// --- LISTAS ---

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

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


// --- PILHAS ---

typedef struct {
    No *topo;
    int tamanho;
} Pilha;

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


// --- FILAS ---

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

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
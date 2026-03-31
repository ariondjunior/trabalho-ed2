#ifndef PILHA_H_
#define PILHA_H_

typedef struct no 
{
    int info;
    struct no* prox;
} No;

typedef struct {
    No *topo;
    int tamanho;
} Pilha;

void inicializar_p(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int topo(Pilha *p);
int vazia(Pilha *p);
void imprimir_p(Pilha *p);
void liberar_p(Pilha *p);

#endif /* PILHA_H_ */
#ifndef LISTADC_H_
#define LISTADC_H_

#include "../cliente.h"

/**
 * Nó especial usado apenas aqui para a lista duplamente encadeada
 * 
 */
typedef struct noDc
{
    Cliente info;
    struct noDc* ant;
    struct noDc* prox;
} NoDc;

typedef struct
{
    NoDc* inicio;
    NoDc* fim;
    NoDc* atual;
    int tamanho;
} ListaDc;

ListaDc* criarListaDc();
void liberarListaDc(ListaDc* l);
void inserirFimListaDc(ListaDc* l, Cliente c);
int removerInicioListaDc(ListaDc* l, Cliente* c);
int removerAtualListaDc(ListaDc* l, Cliente* c);
int iniciarNavegacao(ListaDc* l);
int proximoListaDc(ListaDc* l, Cliente* c);
int anteriorListaDc(ListaDc* l, Cliente* c);
int obterAtualListaDc(ListaDc* l, Cliente* c);
int buscarListaDc(ListaDc* l, const char* nome, Cliente* c);
int tamanhoListaListaDc(ListaDc* l);
int listaVaziaListaDc(ListaDc* l);

#endif /* LISTA_DC_H_ */

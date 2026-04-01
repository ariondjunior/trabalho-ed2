#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "../TAD/listadc/listadc.h"
#include "../TAD/cliente.h"

int lerInteiro(int* valor);
void preencherDadosCompra(Cliente* c);
void exibirCliente(Cliente* c);
void exibirClientesEmEspera(ListaDc* aguardando);
int calcularDiasEspera(char *dataCaptacao);


#endif /* UTILITIES_H_ */
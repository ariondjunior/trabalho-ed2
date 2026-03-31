#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "../TAD/cliente.h"
#include "../TAD/listadc/listadc.h"

void cadastrar(ListaDc* lista) 
{
    Cliente c;

    memset(&c, 0, sizeof(Cliente));
    system("clear");

    printf("Nome: ");
    scanf(" %99[^\n]", c.nome);

    printf("Telefone: ");
    scanf(" %19s", c.telefone);

    printf("Email: ");
    scanf(" %99s", c.email);

    printf("Data Captação (dd/mm/yyyy): ");
    scanf(" %10s", c.dataCaptacao);

    inserirFimListaDc(lista, c);

    system("clear");
    printf("\nCliente cadastrado com sucesso!\n");
}

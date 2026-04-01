#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TAD/listadc/listadc.h"
#include "../utilities/utilities.h"

void relatorios(ListaDc* aguardando) {
    int op = -1;

    do {
        printf("\n===== MENU RELATORIO =====\n");
        printf("[1] Numero de clientes aguardando contato\n");
        printf("[2] Lista de clientes aguardando contato\n");
        printf("[0] Voltar\n");

        printf("Opcao: ");
        if (lerInteiro(&op) == 0) {
            break;
        }

        if (op == -1) {
            printf("Opcao invalida!\n");
            continue;
        }

        system("clear");
        if (op == 1) {
            printf("===== RELATORIO =====\n");
            printf("Clientes aguardando contato: %d\n", aguardando->tamanho);
        } else if (op == 2) {
            exibirClientesEmEspera(aguardando);
        } else if (op != 0) {
            printf("Opcao invalida!\n");
        }

    } while (op != 0);

    system("clear");
}

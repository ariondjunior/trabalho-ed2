#include <stdio.h>
#include <stdlib.h>
#include "../TAD/listadc/listadc.h"

void relatorios(ListaDc* aguardando) {

    int op;

    do {
        system("clear");
        printf("----- Relatório -----\n");
        printf("Clientes aguardando contato: %d\n", aguardando->tamanho);
        printf("\n");
        NoDc* aux;
        for (aux = aguardando->inicio; aux != NULL; aux = aux->prox) {

            printf("Nome: %s | Dias de espera: %s\n", aux->info.nome, aux->info.dataCaptacao);
        }

        printf("\n[1] Voltar ao início\n");
        scanf("%d", &op);

        if (op == 1) {
            system("clear");
            return;
        }

    } while (op != 1);
}
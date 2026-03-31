#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TAD/listadc/listadc.h"

int calcularDiasEspera(const char *dataCaptacao) {
    int dia, mes, ano;
    struct tm dataCap = {0};
    time_t tempoCaptacao, tempoAtual;
    double diferencaSegundos;

    sscanf(dataCaptacao, "%d/%d/%d", &dia, &mes, &ano);

    dataCap.tm_mday = dia;
    dataCap.tm_mon = mes - 1;
    dataCap.tm_year = ano - 1900;
    dataCap.tm_hour = 0;
    dataCap.tm_min = 0;
    dataCap.tm_sec = 0;

    tempoCaptacao = mktime(&dataCap);
    time(&tempoAtual);

    diferencaSegundos = difftime(tempoAtual, tempoCaptacao);

    return (int)(diferencaSegundos / (60 * 60 * 24));
}

void relatorios(ListaDc* aguardando) {

    int op;

    do {
        system("clear");
        printf("===== RELATORIO =====\n");
        printf("Clientes aguardando contato: %d\n", aguardando->tamanho);
        printf("\n");
        NoDc* aux;
        for (aux = aguardando->inicio; aux != NULL; aux = aux->prox) {

            printf("Nome: %s | Dias de espera: %d\n", aux->info.nome, calcularDiasEspera(aux->info.dataCaptacao));
        }

        printf("\n[1] Voltar ao início\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            system("clear");
            return;
        }

    } while (op != 1);
}
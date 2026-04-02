#include <stdio.h>
#include <time.h>
#include "../TAD/listadc/listadc.h"
#include "../TAD/cliente.h"


//Utilitários para auxílio de eficiência/organização do código

int lerInteiro(int* valor) {
    int inteiro;

    inteiro = scanf("%d", valor);

    if (inteiro == 1) {
        return 1;
    }

    if (inteiro == EOF) {
        return 0;
    }

    scanf("%*[^\n]");
    scanf("%*c");
    return -1;
}

int calcularDiasEspera(char *dataCaptacao) {
    int dia, mes, ano;
    struct tm dataCap = {0};
    time_t tempoCaptacao, tempoAtual;
    double diferencaSegundos;

    sscanf(dataCaptacao, "%d/%d/%d", &dia, &mes, &ano);

    dataCap.tm_mday = dia;
    /** Professor esses tm_mon e tm_year sao subtraidos por esses valores, pois sao uma convencao do mktime*/
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

void exibirClientesEmEspera(ListaDc* aguardando) {

    printf("===== RELATORIO =====\n");
    if (aguardando->inicio == NULL)
        printf("Nenhum cliente aguardando contato.\n");
    else {
        NoDc* aux;
        for (aux = aguardando->inicio; aux != NULL; aux = aux->prox)
            printf("Nome: %s | Dias de espera: %d\n", aux->info.nome, calcularDiasEspera(aux->info.dataCaptacao));
    }
}

void preencherDadosCompra(Cliente* c) {
    printf("Data de nascimento (dd/mm/yyyy): ");
    scanf(" %10s", c->dataNascimento);

    printf("Rua: ");
    scanf(" %99[^\n]", c->rua);

    printf("Numero: ");
    scanf(" %19s", c->numero);

    printf("Bairro: ");
    scanf(" %59[^\n]", c->bairro);

    printf("Cidade: ");
    scanf(" %59[^\n]", c->cidade);

    printf("Estado (UF): ");
    scanf(" %2s", c->estado);

    printf("CEP: ");
    scanf(" %9s", c->cep);

    printf("CPF: ");
    scanf(" %14s", c->cpf);
}

void exibirCliente(Cliente* c) {
    printf("\nCliente atual:\n");
    printf("Nome: %s\n", c->nome);
    printf("Telefone: %s\n", c->telefone);
    printf("Email: %s\n", c->email);
    printf("Data de captacao: %s\n", c->dataCaptacao);
}




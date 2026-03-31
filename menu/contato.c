#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "../TAD/cliente.h"
#include "../TAD/listadc/listadc.h"
#include "../TAD/fila/fila.h"

void exibirCliente(const Cliente* c) {
    printf("\nCliente atual:\n");
    printf("Nome: %s\n", c->nome);
    printf("Telefone: %s\n", c->telefone);
    printf("Email: %s\n", c->email);
    printf("Data de captacao: %s\n", c->dataCaptacao);
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

void realizarContato(ListaDc* lista, Fila* compradores, ListaDc* arquivados) {
    Cliente c;

    if (!iniciarNavegacao(lista)) {
        system("clear");
        printf("Nenhum cliente.\n");
        return;
    }

    int op;

    do {
        system("clear");
        obterAtualListaDc(lista, &c);
        exibirCliente(&c);

        printf("\n[1] Proximo\n[2] Anterior\n[3] Buscar\n[4] Voltar ao início\n[5] Finalizar\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
            proximoListaDc(lista, &c);

        else if (op == 2)
            anteriorListaDc(lista, &c);

        else if (op == 3) {
            char nome[100];
            printf("Nome para busca exata: ");
            scanf(" %99[^\n]", nome);

            if (!buscarListaDc(lista, nome, &c))
                printf("Cliente nao encontrado. Permanecendo no cliente atual.\n");
        }
        else if (op == 4) {
            system("clear");
            return;
        }

    } while (op != 5);

    Cliente atendido;

    if (removerAtualListaDc(lista, &atendido)) {
        int comprou;
        system("clear");
        printf("Comprou? (1/0): ");
        scanf("%d", &comprou);

        if (comprou) {
            preencherDadosCompra(&atendido);
            enfileirar(compradores, atendido);
            system("clear");
            printf("Cliente movido para a fila de compradores.\n");
        } else {
            int arquivar;
            system("clear");
            printf("Arquivar? (1/0): ");
            scanf("%d", &arquivar);

            if (arquivar) {
                inserirFimListaDc(arquivados, atendido);
                system("clear");
                printf("Cliente arquivado para contato futuro.\n");
            } else {
                system("clear");
                printf("Cliente removido definitivamente do sistema.\n");
            }
        }
    }
}

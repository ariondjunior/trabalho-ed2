#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "../TAD/cliente.h"
#include "../TAD/listadc/listadc.h"
#include "../TAD/fila/fila.h"
#include "../utilities/utilities.h"

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

        /* Aqui adicionamos a quinta opcao para melhorar o fluxo do sistema, mesmo o pdf não solicitando essa funcionalidade */
        op = -1;
        printf("\n[1] Proximo\n[2] Anterior\n[3] Buscar\n[4] Finalizar atendimento\n[5] Voltar ao inicio\n");

        printf("Opcao: ");
        if (lerInteiro(&op) == 0) {
            return;
        }

        if (op == -1) {
            printf("Opcao invalida.\n");
            continue;
        }

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
        else if (op == 5) {
            system("clear");
            return;
        }

    } while (op != 4);

    Cliente atendido;

    if (removerAtualListaDc(lista, &atendido)) {
        int comprou;
        system("clear");

        printf("Comprou?\n[1] Sim / [0] Nao: ");
        if (lerInteiro(&comprou) == 0) {
            return;
        }

        if (comprou) {
            preencherDadosCompra(&atendido);
            enfileirar(compradores, atendido);
            system("clear");
            printf("Cliente movido para a fila de compradores.\n");
        } else {
            int arquivar;
            system("clear");

            printf("Arquivar?\n[1] Sim / [0] Nao: ");
            if (lerInteiro(&arquivar) == 0) {
                return;
            }

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

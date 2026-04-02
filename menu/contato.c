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

    // --- Validação de Conteúdo ---
    // Verifica se há clientes disponíveis e reseta o ponteiro de navegação para o início.
    if (!iniciarNavegacao(lista)) {
        system("clear");
        printf("Nenhum cliente.\n");
        return;
    }

    int op;

    // --- Ciclo de Navegação e Interação ---
    do {
        system("clear");
        // Obtém os dados do cliente no cursor atual da lista para exibição
        obterAtualListaDc(lista, &c);
        exibirCliente(&c);

        printf("\n[1] Proximo\n[2] Anterior\n[3] Buscar\n[4] Finalizar atendimento\n[5] Voltar ao inicio\n");
        printf("Opcao: ");
        
        // Proteção contra entradas inválidas (leitura de inteiro segura)
        if (lerInteiro(&op) == 0) {
            return;
        }

        switch (op) {
            case 1:
                // Move o cursor para o próximo elemento da lista circular
                proximoListaDc(lista, &c);
                break;

            case 2:
                // Move o cursor para o elemento anterior
                anteriorListaDc(lista, &c);
                break;

            case 3:
                // Realiza busca exata. Se encontrar, o cursor da lista é atualizado.
                {
                    char nome[100];
                    printf("Nome para busca exata: ");
                    scanf(" %99[^\n]", nome);

                    if (!buscarListaDc(lista, nome, &c))
                        printf("Cliente nao encontrado. Permanecendo no cliente atual.\n");
                }
                break;

            case 5:
                // Encerra a função sem realizar alterações no status do cliente
                system("clear");
                return;

            default:
                if (op != 4) printf("Opcao invalida.\n");
                break;
        }

    } while (op != 4);
    
    // --- Processamento do Desfecho do Atendimento ---
    Cliente atendido;

    // Remove o cliente que estava sendo visualizado para decidir seu destino
    if (removerAtualListaDc(lista, &atendido)) {
        int comprou;
        system("clear");

        printf("Comprou?\n[1] Sim / [0] Nao: ");
        if (lerInteiro(&comprou) == 0) return;

        if (comprou) {
            // Caso de Sucesso: Preenche dados adicionais e move para a Fila de Compradores
            preencherDadosCompra(&atendido);
            enfileirar(compradores, atendido);
            system("clear");
            printf("Cliente movido para a fila de compradores.\n");
        } 
        else {
            // Caso de Não Compra: Opção de arquivamento para o futuro
            int arquivar;
            system("clear");

            printf("Arquivar?\n[1] Sim / [0] Nao: ");
            if (lerInteiro(&arquivar) == 0) return;

            if (arquivar) {
                // Move para a Lista de Arquivados
                inserirFimListaDc(arquivados, atendido);
                system("clear");
                printf("Cliente arquivado para contato futuro.\n");
            } else {
                // Remoção permanente (liberação implícita ao não reinserir em outra estrutura)
                system("clear");
                printf("Cliente removido definitivamente do sistema.\n");
            }
        }
    }
}
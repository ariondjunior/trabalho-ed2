#include <stdio.h>
#include <stdlib.h>
#include "TAD/fila/fila.h"
#include "TAD/listadc/listadc.h"
#include "menu/cadastro.h"
#include "menu/contato.h"
#include "menu/relatorios.h"
#include "utilities/utilities.h"


int main() {
    int menu = -1;

    // --- Inicialização de Estruturas ---
    // Cria as listas duplamente encadeadas circulares e a fila de processamento
    ListaDc* aguardando = criarListaDc();
    Fila* compradores = inicializar_f();
    ListaDc* arquivados = criarListaDc();  

    do {
        printf("\n===== MENU =====\n");
        printf("[1] Cadastrar cliente\n");
        printf("[2] Realizar contato\n");
        printf("[3] Relatórios\n");
        printf("[4] Sair\n");

        printf("Opcao: ");
        
        // Proteção contra entradas não numéricas via função utilitária
        if (lerInteiro(&menu) == 0) {
            break;
        }

        printf("\n");

        // Validação de estado inicial do menu
        if (menu == -1) {
            printf("Opcao invalida!\n");
            continue;
        }

        // --- Direcionamento de Funcionalidades ---
        switch(menu) {
            case 1:
                // Encaminha para o fluxo de cadastro de novos clientes
                cadastrar(aguardando);
                break;

            case 2:
                // Fluxo de navegação e contato com clientes já cadastrados
                realizarContato(aguardando, compradores, arquivados);
                break;

            case 3:
                // Geração de estatísticas e listagens
                relatorios(aguardando);
                break;

            case 4:
                // Mensagem de encerramento e preparação para saída
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (menu != 4);

    // --- Limpeza e Desalocação ---
    liberarListaDc(aguardando);
    liberarListaDc(arquivados);
    liberar_f(compradores);

    return 0;
}
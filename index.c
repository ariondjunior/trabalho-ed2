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


    //Inicialização das listas e fila utilizadas no decorrer do progama
    ListaDc* aguardando = criarListaDc();
    Fila* compradores = inicializar_f();
    ListaDc* arquivados = criarListaDc();  


    //Inicialização do progama principal com do while para o progama rodar em loop até que seja solicitado a saida
    do {
        printf("\n===== MENU =====\n");
        printf("[1] Cadastrar cliente\n");
        printf("[2] Realizar contato\n");
        printf("[3] Relatórios\n");
        printf("[4] Sair\n");

        printf("Opcao: ");
        if (lerInteiro(&menu) == 0) {
            break;
        }

        printf("\n");

        if (menu == -1) {
            printf("Opcao invalida!\n");
            continue;
        }

        switch(menu) {
            case 1:
                cadastrar(aguardando);
                break;

            case 2:
                realizarContato(aguardando, compradores, arquivados);
                break;

            case 3:
                relatorios(aguardando);
                break;

            case 4:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (menu != 0);

    //Liberação de memória das variáveis de listas e filas inicializadas no inicio do progama
    liberarListaDc(aguardando);
    liberarListaDc(arquivados);
    liberar_f(compradores);

    return 0;
}

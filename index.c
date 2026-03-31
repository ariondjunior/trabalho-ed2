#include <stdio.h>
#include <stdlib.h>
#include "TAD/fila/fila.h"
#include "TAD/listadc/listadc.h"
#include "menu/cadastro.h"
#include "menu/contato.h"

int main() {
    int menu;

    ListaDc* aguardando = criarListaDc();
    Fila* compradores = inicializar_f();
    ListaDc* arquivados = criarListaDc();  

    do {
        printf("\n===== MENU =====\n");
        printf("[1] Cadastrar cliente\n");
        printf("[2] Realizar contato\n");
        printf("[3] Relatórios\n");
        printf("[0] Sair\n");
        printf("Opcao: ");
        scanf("%d", &menu);

        printf("\n");

        switch(menu) {
            case 1:
                printf("Cadastrando...\n");
                cadastrar(aguardando);
                break;

            case 2:
                printf("Realizando contato...\n");
                realizarContato(aguardando, compradores, arquivados);
                break;

            case 3:
                printf("Relatorios...\n");
                // relatorios(aguardando);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (menu != 0);

    liberarListaDc(aguardando);
    liberarListaDc(arquivados);
    liberar_f(compradores);

    return 0;
}

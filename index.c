#include <stdio.h>
#include <stdlib.h>
#include "TAD.c" 
#include "Cadastro.c"

int main() {
    while(1){
    printf("[1] Cadastrar cliente\n");
    printf("[2] Realizar contato\n");
    printf("[3] Relatórios\n");
    printf("[0] Sair\n");
    int menu = 0;
    scanf("%d", &menu);
    
    printf("\n");


    
    switch(menu){
        case 1: printf("Cadatrando...");
                printf("\n");
                cadastrar();
            break;
        case 2: printf("Contatando...");
            break;
        case 3: printf("Relatando...");
            break;
        case 4: printf("Saindo...");
            system("pause");
}
    
    

    return 0;
}
}
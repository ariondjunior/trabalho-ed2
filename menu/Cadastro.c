#include <stdio.h>
#include <stdlib.h>

typedef struct cliente{
    char nome[50];
    int numero;
    char email[60];
    char data[11];

}Cliente; 

void cadastrar() {
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    
    if (novo != NULL) {
        printf("Insira o nome do cliente: \n");
        
        scanf(" %[^\n]", novo->nome); 

        printf("Insira o numero: \n");
        scanf("%d", &novo->numero); 

        printf("Insira o email: \n");
        scanf("%s", novo->email);

        printf("Insira a data (DD/MM/AAAA): \n");
        scanf("%s", novo->data);

 
        printf("\nCliente %s cadastrado com sucesso!\n", novo->nome);
        
     
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}
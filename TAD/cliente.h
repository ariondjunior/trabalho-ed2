#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct cliente {
    char nome[100];
    char telefone[20];
    char email[100];
    char dataCaptacao[11]; // dd/mm/yyyy
    char dataNascimento[11]; // dd/mm/yyyy
    char rua[100];
    char numero[20];
    char bairro[60];
    char cidade[60];
    char estado[3];
    char cep[10];
    char cpf[15];
} Cliente;

#endif /* CLIENTE_H_ */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdio.h>

typedef struct Cliente
{
    char nome[10];
    char cpf[11];
    char telefone[10];
} TCliente;
void imprimirCliente(TCliente cliente){
    printf("== Dados do cliente ==\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Telefone: %s\n", cliente.telefone);
};
#endif

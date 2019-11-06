#ifndef CLIENTE_H
#define CLIENTE_H
typedef struct Cliente
{
    char nome[10];
    char cpf[11];
    char telefone[10];
} TCliente;
void imprimirCliente(TCliente cliente);
#endif

#include "cliente.h"
#include <stdio.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} TData;
typedef struct Conta
{
    int numero;
    TCliente cliente;
    TData dataAbertura;
    float saldo;
    int ativa;
} TConta;

TConta depositar(TConta conta, float valor)
{
    conta.saldo += valor;
    return conta;
};

TConta debitar(TConta conta, float quantia)
{
    conta.saldo -= quantia;
    return conta;
};

int transferir(TConta origem, TConta destino,float quantia)
{
    if(origem.saldo > quantia)
    {
        destino.saldo += quantia;
        origem.saldo -= quantia;
        return 1;
    }
    else
    {
        return 0;
    }
};

void imprimirConta(TConta conta){
    printf("Numero da conta: %i\n", conta.numero);
    printf("Cliente: %i\n", conta.cliente.nome);
    printf("Data de abertura: %i/%i/%i\n", conta.dataAbertura.dia, conta.dataAbertura.mes, conta.dataAbertura.ano);
    printf("Saldo: %.2f\n", conta.saldo);
    printf("Status da conta: %s \n", conta.ativa == 1 ? "Ativa" : "Fechada");
    
};
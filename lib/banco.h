#include "conta.h"
#define QTD_USUARIOS 2

TConta contas[QTD_USUARIOS];
int numeroConta = 0;

void adicionarConta(TConta conta){
    if(contas[numeroConta].numero == numeroConta);
        contas[numeroConta] = conta;
//    printf("Conta #%i\n", numeroConta);
//    printf("Saldo: %.2f\n",  contas[numeroConta].saldo);
//    printf("Nome do Cliente: %s \n", contas[numeroConta].cliente.nome);
    numeroConta++;
};
//Essa funcao é apenas para debug
//a certa é que contem *
void listarConta(){
    for (int i = 0; i < QTD_USUARIOS; i++)
    {
        printf("Conta #%i\n", i);
        printf("Saldo: %.2f\n", contas[i].saldo);
        printf("Nome do Cliente: %s \n", contas[i].cliente.nome);
    }
    
};

char* listarContas();

char* pesquisarConta(int numero);

TConta getConta(int numero)
{   
    
    for (int i = 0; i < QTD_USUARIOS; i++)
    {
        if(contas[i].numero == numero)
        {
            return contas[i];
        }
    }
};
int removerConta(int numero)
{
    for (int i = 0; i < QTD_USUARIOS; i++)
    {
        if(contas[i].numero == numero)
        {
            contas[i].ativa = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

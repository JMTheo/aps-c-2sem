#include "conta.h"
#define QTD_USUARIOS 2

TConta contas[QTD_USUARIOS];
int numeroConta = 0;

void adicionarConta(TConta conta){
    if(contas[numeroConta].numero == numeroConta);
        contas[numeroConta] = conta;
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

int atualizaConta(TConta contaNova)
{
    int status = 0;
    for (int i = 0; i < QTD_USUARIOS; i++)
    {
        if (contas[i].numero == contaNova.numero)
        {
            contas[i].saldo = contaNova.saldo;
            status = 1;
            printf("Status: %i\n", status);
        }
    }
    printf("Status 2: %i\n", status);

    return status;
}

int functionFactory(int operacao, int numeroContaMod, int numeroContaDest, float vlr, float vlr2)
{
    TConta contaOrig = getConta(numeroContaMod);
    TConta contaAtualizada;
    switch (operacao)
    {
    case 5:
        //Depositar
        contaAtualizada = depositar(contaOrig, vlr);
        atualizaConta(contaAtualizada);
        break;
    case 6:
        if(contaOrig.saldo + 1000 > vlr)
        {
            contaAtualizada = debitar(contaOrig, vlr);
            atualizaConta(contaAtualizada);
        }
        return 0;
      break;
    default:
        break;
    }
};
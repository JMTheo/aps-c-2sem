#include "cliente.h"
#include <stdio.h>
#define  QTD_CONTAS 2
TCliente clientes[QTD_CONTAS];
int totalClientes = 0;

void adicionarCliente(TCliente cliente[QTD_CONTAS])
{
    int i =0;
    for(i; i < QTD_CONTAS; i++)
    {
       clientes[i] = cliente[i];
    }
    
    
};
int existeCPF(TCliente cliente)
{
    for(int i = 0; i < QTD_CONTAS; i++)
    {
        if(clientes[i].cpf == cliente.cpf)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
};
char* listarClientes(){
    /* char *lista = (char *)malloc(sizeof(char) * (QTD_CONTAS * 3));
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        lista[i] = clientes[i].nome;
        lista[i] = clientes[i].cpf;
        lista[i] = clientes[i].telefone;
        lista[i] = '\0';
    } */
    //linha | coluna
    char * lista[2][11];
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            lista[i][j] = clientes[i].nome;
            lista[i][j] = clientes[i].cpf;
            lista[i][j] = clientes[i].telefone;
        }
        
    }
    
   //return lista;
};

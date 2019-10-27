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
   // char* listaClientes = clientes;
    //return listaClientes;
};

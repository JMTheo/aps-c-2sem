#include <stdio.h>
#include <stdlib.h>

#include "lib/banco.h"
#include "lib/gerenciaClientes.h"
#include "lib/cliente.h"

#define QTD_CONTAS 2

void listarConta()
{
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        if(contas[i].ativa)
        {
            imprimirConta(contas[i]);
        }
        else
        {
            printf("Conta #%i estah desativada ! \n", i);
        }
        
    }
};

int main()
{
    TCliente cliente;
    TConta conta;
    TData sData;
    int opcao, numOrig, numDestino, controleCad = 1, controle = 1;
    char opcaoCad;
    float vlr = 0;
    char* lista = listarClientes();

    while (controle)
    {
        printf("======== Menu do Banco ======== \n");
        printf("1 - Cadastrar Cliente \n");
        printf("2 - Cadastrar Conta \n");
        printf("3 - Listar Conta \n");
        printf("4 - Pesquisar Conta \n");
        printf("5 - Depositar \n");
        printf("6 - Debitar (Sacar) \n");
        printf("7 - Transferir \n");
        printf("8 - Remover Conta \n");
        printf("9 - Sair \n\n");

        printf("Digite uma das opcoes para prosseguir \n");
        scanf("%i", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            while (controleCad)
            {
                printf("Digite o nome do cliente: \n");
                gets(cliente.nome);

                printf("Digite o cpf do cliente: \n");
                gets(cliente.cpf);

                printf("Digite o telefone do cliente: \n");
                gets(cliente.telefone);
                fflush(stdin);

                adicionarCliente(cliente);

                if (totalClientes == QTD_CLIENTES)
                {
                    controleCad = 0;
                    printf("Numero maximo de clientes cadastrados ! \n");
                    lista = listarClientes();
                    for (int i = 0; i < QTD_CLIENTES; i++)
                    {
                        /* code */
                        printf("Opa: \n %s\n", lista+i);
                    }
                    
                }
                else
                {
                    printf("Deseja continuar cadastrando mais clientes ? (s/n) \n");
                    scanf(" %c", &opcaoCad);
                    fflush(stdin);

                    if (opcaoCad == 'n')
                        controleCad = 0;
                }

                
            }
            break;
        case 2:
            printf("Para qual usuario voce quer cadastrar uma conta ?\n");
            //implementar o listaClientes do GerenciaClientes.h
            //char listaDeClientes[QTD_CONTAS][11] = listarClientes();
            scanf("%i", &numeroConta);
            fflush(stdin);

            printf("Digite o DIA da criacao da conta \n");
            scanf("%i", &sData.dia);
            fflush(stdin);

            printf("Digite o MES da criacao da conta \n");
            scanf("%i", &sData.mes);
            fflush(stdin);

            printf("Digite o ANO da criacao da conta \n");
            scanf("%i", &sData.ano);
            fflush(stdin);


            conta.numero = numeroConta;
            conta.dataAbertura = sData;
            conta.cliente = clientes[conta.numero];
            conta.saldo = 1000.0;
            conta.ativa = 1;

            adicionarConta(conta);
            printf("TotalClientes");

            break;
        case 3: 
            //Listar conta
            listarConta();
            
            break;
        case 4: 
            //Pesquisar conta
            break;
        case 5:
            //Depositar

            printf("Digite o numero da conta que vc deseja depositar \n");
            scanf("%i", &numeroConta);

            printf("Digite o valor a ser depositado \n");
            scanf("%f", &vlr);

            depositar(getConta(numeroConta), vlr);
            break;
        case 6:
            //Debitar(sacar)
            printf("Digite o numero da conta que vc deseja sacar \n");
            scanf("%i", &numeroConta);

            printf("Digite o valor a ser sacado\n");
            scanf("%f", &vlr);

            if (debitar(getConta(numeroConta), vlr))
            {
                printf("Transacao realizada com sucesso !");
                printf("Novo Saldo: %.2f\n", getConta(numeroConta).saldo);
            }
            else
            {
                printf("Saldo insuficiente \n");
                printf("Saldo: %.2f \n", getConta(numeroConta).saldo);
                printf("Valor a ser sacado: %.2f \n", vlr);
            }

            break;
        case 7:
            //Transferir dinheiro
            printf("Digite o numero da conta que recebera a transferencia \n");
            scanf("%i", &numDestino);
            fflush(stdin);

            printf("Digite o numero da conta que ira transferir o dinheiro \n");
            scanf("%i", &numOrig);
            fflush(stdin);

            printf("Digite o valor a ser transferido \n");
            scanf("%f", &vlr);
            fflush(stdin);

            if(transferir(getConta(numOrig), getConta(numDestino), vlr))
            {
                printf("Saldo transferido com sucesso !\n");
                printf("Saldo da conta origem: %.2f\n", getConta(numOrig).saldo);
                printf("Saldo da conta destino: %.2f\n", getConta(numeroConta).saldo);
            }
            else
            {
                printf("Saldo insuficiente para a transferencia\n");
                printf("Saldo da conta origem: %.2f\n", getConta(numOrig).saldo);
                printf("Valor a ser transferido> %.2f \n", vlr);
            }
            break;
        case 8: 
            //Remover conta
            printf("Digite o numero da conta que vc deseja excluir \n ");
            scanf("%i", &numeroConta);
            fflush(stdin);

            if(removerConta(numeroConta))
                printf("Conta excluida com sucesso !\n");
            else
                printf("Conta inexistente \n");

            printf("Retornando ao menu...\n");
            break;
        case 9: 
            //Encerrrar o programa
            return 0;
            break;
        default:
            printf("Digite um numero valido (1 a 9)\n");
            fflush(stdin);

            break;
        }
        fflush(stdin);
    }
}

void adicionarCliente(TCliente cliente)
{
    int i = totalClientes;
    clientes[i] = cliente;
    totalClientes++;
}

int existeCPF(TCliente cliente)
{
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        if (clientes[i].cpf == cliente.cpf)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void adicionarConta(TConta conta)
{
    contas[numeroConta] = conta;
    contas[numeroConta].numero = numeroConta;
}

TConta getConta(int numero)
{
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        if (contas[i].numero == numero)
        {
            return contas[i];
        }
    }
}

int removerConta(int numero)
{
    for (int i = 0; i < QTD_CONTAS; i++)
    {
        if (contas[i].numero == numero)
        {
            contas[i].ativa = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void depositar(TConta conta, float valor)
{
    contas[conta.numero].saldo += valor;
}

int debitar(TConta conta, float quantia)
{
    int status = 0;
    if (conta.saldo + 1000 > quantia)
    {
        contas[conta.numero].saldo -= quantia;
        status = 1;
    }
    
    return status;
}

int transferir(TConta origem, TConta destino, float quantia)
{
    int status = 0;
    if (origem.saldo > quantia)
    {
        contas[destino.numero].saldo += quantia;
        contas[origem.numero].saldo -= quantia;
        status = 1;
    }

    return status;
};

void imprimirConta(TConta conta)
{
    printf("Numero da conta: %i\n", conta.numero);
    printf("Cliente: %s\n", conta.cliente.nome);
    printf("Data de abertura: %i/%i/%i\n", conta.dataAbertura.dia, conta.dataAbertura.mes, conta.dataAbertura.ano);
    printf("Saldo: %.2f\n", conta.saldo);
    printf("Status da conta: %s \n", conta.ativa == 1 ? "Ativa" : "Fechada");
}

char* listarClientes()
{
    //char *lista = malloc(QTD_CLIENTES * sizeof(char));
    // const char *lista[2] = {clientes[0].nome, clientes[1].nome};
    // return lista;
}
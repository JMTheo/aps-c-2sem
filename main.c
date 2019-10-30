#include <stdio.h>
#include <stdlib.h>

#include "lib/banco.h"
#include "lib/gerenciaClientes.h"
#include "lib/cliente.h"

int main()
{
    TCliente cliente[QTD_CONTAS];
    TConta conta;
    TData sData;
    int opcao, numOrig, controle = 1;
    float vlr = 0;
    char *lista[300];

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
            for (int i = 0; i < QTD_CONTAS; i++)
            {
                printf("Digite o nome do cliente %i#: \n", i+1);
                gets(cliente[i].nome);

                printf("Digite o cpf do cliente %i#: \n", i+1);
                gets(cliente[i].cpf);

                printf("Digite o telefone do cliente %i#: \n", i+1);
                gets(cliente[i].telefone);
                fflush(stdin);

            }
            adicionarCliente(cliente);
                        
            break;
        case 2:
            printf("Para qual usuario voce quer cadastrar uma conta ?\n");
            //implementar o listaClientes do GerenciaClientes.h
            //char listaDeClientes[QTD_CONTAS][11] = listarClientes();
            scanf("%i", &numeroConta);
            fflush(stdin);

            printf("Digite o dia da criacao da conta \n");
            scanf("%i", &sData.dia);
            fflush(stdin);

            printf("Digite o mes da criacao da conta \n");
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

            break;
        case 3: 
            //Listar conta
            //listarConta();
            *lista = listarClientes();
            for (int i = 0; i < QTD_CONTAS; i++)
            {
                printf("Nome: %s\n", lista[i]);
            }
            
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

            functionFactory(opcao,numeroConta, 0, vlr, 0);
            break;
        case 6:
            //Debitar(sacar)
            printf("Digite o numero da conta que vc deseja sacar \n");
            scanf("%i", &numeroConta);

            printf("Digite o valor a ser sacado\n");
            scanf("%f", &vlr);

            functionFactory(opcao,numeroConta,0,vlr,0);
            break;
        case 7:
            //Transferir dinheiro
            printf("Digite o numero da conta que recebera a transferencia \n");
            scanf("%i", &numeroConta);
            fflush(stdin);

            printf("Digite o numero da conta que ira transferir o dinheiro \n");
            scanf("%i", &numOrig);
            fflush(stdin);

            printf("Digite o valor a ser transferido \n");
            scanf("%f", &vlr);
            fflush(stdin);

            if(transferir(getConta(numeroConta), getConta(numOrig), vlr))
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
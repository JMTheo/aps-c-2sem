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
    int opcao, controle =1;
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
            scanf("%i", &conta.numero);
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

            conta.dataAbertura = sData;
            conta.cliente = clientes[conta.numero];
            conta.saldo = 1000.0;
            conta.ativa = 1;

            adicionarConta(conta);

            break;
        case 9:
            return 0;
            break;
        default:
            printf("Digite um numero valido \n ");
            fflush(stdin);

            break;
        }
        fflush(stdin);
    }
}
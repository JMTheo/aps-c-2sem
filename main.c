#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banco.h"
#include "gerenciaClientes.h"
#include "cliente.h"

int main()
{
    TCliente cliente;
    TConta conta;
    int opcao, i, numOrig, numDestino, controleCad = 1, controle = 1;
    char opcaoCad;
    float vlr = 0;

    system("cls");
    while (controle)
    {
        printf("======== Menu do Banco ======== \n");
        printf("1 - Cadastrar Cliente \n");
        printf("2 - Cadastrar Conta \n");
        printf("3 - Listar Contas \n");
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
            system("cls");
            while (controleCad)
            {
                printf("Digite o nome do cliente: \n");
                gets(cliente.nome);

                do
                {
                    printf("Digite o cpf do cliente: \n");
                    gets(cliente.cpf);
                    if (existeCPF(cliente))
                        printf("Voce deve digitar um cpf valido (unico) \n");

                } while (existeCPF(cliente));

                printf("Digite o telefone do cliente: \n");
                gets(cliente.telefone);
                fflush(stdin);

                adicionarCliente(cliente);
                statusClienteCad = 1;

                if (totalClientes == QTD_CLIENTES)
                {
                    controleCad = 0;
                    system("cls");

                    printf("Numero maximo de clientes cadastrados ! \n");

                }
                else
                {
                    system("cls");
                    printf("Deseja continuar cadastrando mais clientes ? (s/n) \n");
                    scanf(" %c", &opcaoCad);
                    fflush(stdin);

                    if (opcaoCad == 'n')
                        controleCad = 0;
                }


            }
            break;
        case 2:
            system("cls");

            if(checarCadCliente())
            {
                listarClientes();

                printf("Para qual usuario voce quer cadastrar uma conta ?\n");
                scanf("%i", &numeroConta);
                fflush(stdin);

                printf("Digite o DIA da criacao da conta \n");
                scanf("%i", &conta.dataAbertura.dia);
                fflush(stdin);

                printf("Digite o MES da criacao da conta \n");
                scanf("%i", &conta.dataAbertura.mes);
                fflush(stdin);

                printf("Digite o ANO da criacao da conta \n");
                scanf("%i", &conta.dataAbertura.ano);
                fflush(stdin);

                printf("Digite o saldo inicial da conta \n");
                scanf("%f", &conta.saldo);

                statusCad = 1;
                conta.numero = numeroConta;
                conta.cliente = clientes[conta.numero];
                conta.ativa = 1;

                adicionarConta(conta);
                system("cls");
            }

            break;
        case 3:
            //Listar contas
            system("cls");
            if(checarCad())
                listarContas();

            break;
        case 4:
            //Pesquisar conta
            system("cls");
            if (checarCad())
            {
                printf("Digite o numero da conta para pesquisa \n");
                scanf("%i", &numeroConta);

                pesquisarConta(numeroConta);
            }
            break;
        case 5:
            //Depositar
            system("cls");
            if (checarCad())
            {
                listarContas();
                printf("Digite o numero da conta que vc deseja depositar \n");
                scanf("%i", &numeroConta);

                printf("Digite o valor a ser depositado \n");
                scanf("%f", &vlr);

                depositar(getConta(numeroConta), vlr);
            }

            break;
        case 6:
            //Debitar(sacar)

            system("cls");
            if (checarCad())
            {
                listarContas();
                printf("Digite o numero da conta que vc deseja sacar \n");
                scanf("%i", &numeroConta);

                printf("Digite o valor a ser sacado\n");
                scanf("%f", &vlr);

                if (debitar(getConta(numeroConta), vlr))
                {
                    printf("Transacao realizada com sucesso !\n");
                    printf("Novo Saldo: %.2f\n", getConta(numeroConta).saldo);
                }
                else
                {
                    printf("Saldo insuficiente \n");
                    printf("Saldo: %.2f \n", getConta(numeroConta).saldo);
                    printf("Valor a ser sacado: %.2f \n", vlr);
                }
            }
            break;
        case 7:
            //Transferir dinheiro
            system("cls");
            if (checarCad())
            {
                listarContas();

                printf("Digite o numero da conta que recebera a transferencia \n");
                scanf("%i", &numDestino);
                fflush(stdin);

                printf("Digite o numero da conta que ira transferir o dinheiro \n");
                scanf("%i", &numOrig);
                fflush(stdin);

                printf("Digite o valor a ser transferido \n");
                scanf("%f", &vlr);
                fflush(stdin);

                if (transferir(getConta(numOrig), getConta(numDestino), vlr))
                {
                    printf("Saldo transferido com sucesso !\n");
                    printf("Saldo da conta origem: %.2f\n", getConta(numOrig).saldo);
                    printf("Saldo da conta destino: %.2f\n", getConta(numDestino).saldo);
                }
                else
                {
                    printf("Saldo insuficiente para a transferencia\n");
                    printf("Saldo da conta origem: %.2f\n", getConta(numOrig).saldo);
                    printf("Valor a ser transferido> %.2f \n", vlr);
                }
            }
            break;
        case 8:
            system("cls");
            if (checarCad())
            {
                //Remover conta
                printf("Digite o numero da conta que vc deseja excluir \n");
                scanf("%i", &numeroConta);
                fflush(stdin);

                if (removerConta(numeroConta))
                    printf("Conta excluida com sucesso !\n");
                else
                    printf("Conta inexistente \n");

                printf("Retornando ao menu...\n");
            }

            break;
        case 9:
            //Encerrrar o programa
            system("cls");
            printf("Desligando ...\n");
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
int checarCadCliente()
{
    int status = 0;
    if (statusClienteCad)
        status = 1;
    else
        printf("Voce deve cadastrar um cliente primeiro !\n");

    return status;
}
int checarCad()
{
    int status = 0;
    if (statusCad)
        status = 1;
    else
        printf("Voce deve cadastrar uma conta primeiro !\n");

    return status;
}

void adicionarCliente(TCliente cliente)
{
    int i = totalClientes;
    clientes[i] = cliente;
    totalClientes++;
}

int existeCPF(TCliente cliente)
{
    int status = 0;
    int comparacao;
    int i;
    for (i = 0; i < QTD_CONTAS; i++)
    {
        //strcmp ==0 (iguais)
        comparacao = strcmp(cliente.cpf, clientes[i].cpf);
        if(comparacao == 0)
        {
           status = 1;
        }
    }

    return status;
}

void adicionarConta(TConta conta)
{
    contas[numeroConta] = conta;
    contas[numeroConta].numero = numeroConta;
}

TConta getConta(int numero)
{
    int i;
    for (i = 0; i < QTD_CONTAS; i++)
    {
        if (contas[i].numero == numero)
        {
            return contas[i];
        }
    }
}

int removerConta(int numero)
{
    int i;
    for (i = 0; i < QTD_CONTAS; i++)
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
    if (origem.saldo + 1000 > quantia)
    {
        contas[destino.numero].saldo += quantia;
        contas[origem.numero].saldo -= quantia;
        status = 1;
    }

    return status;
};

void imprimirConta(TConta conta)
{
    printf("=== Numero da conta: %i ===\n", conta.numero);
    printf("Cliente: %s\n", conta.cliente.nome);
    printf("Data de abertura: %i/%i/%i\n", conta.dataAbertura.dia, conta.dataAbertura.mes, conta.dataAbertura.ano);
    printf("Saldo: %.2f\n\n", conta.saldo);
}

// As tres funcoes modificadas
void listarContas()
{
    int i;
    for (i = 0; i < QTD_CONTAS; i++)
    {
        if (contas[i].ativa)
        {
            imprimirConta(contas[i]);
        }
        else
        {
            printf("Conta #%i estah desativada ! \n\n", i);
        }
    }
};

void pesquisarConta(int numero)
{
    TConta c = getConta(numero);

    if(c.ativa)
        imprimirConta(c);
    else
        printf("Conta #%i estah desativada ! \n", c.ativa);
}

void listarClientes()
{
    int i;
    for (i = 0; i < QTD_CLIENTES; i++)
    {
        if(strcmp(clientes[i].nome, ""))
        {
            printf("=== Lista de Clientes === \n");
            printf("Cliente: #%i\n", i);
            printf("Nome: %s\n\n", clientes[i].nome);
        }
    }

}

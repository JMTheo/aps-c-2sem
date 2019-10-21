#include <stdio.h>
#include <stdlib.h>
#include "lib/banco.h"

int main()
{
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
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case 1:
            /* code */
            break;
        
        default:
            printf("Digite um numero valido \n ");
            break;
        }

}
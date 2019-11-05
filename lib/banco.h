#include "conta.h"
TConta contas[10];
int numeroConta = 0;
void adicionarConta(TConta conta);
void listarContas(); //alterado
void pesquisarConta(int numero);//alterado
TConta getConta(int numero);
int removerConta(int numero);

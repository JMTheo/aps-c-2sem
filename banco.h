#include "conta.h"

#define QTD_CONTAS 5
TConta contas[QTD_CONTAS];
int numeroConta = 0, statusCad = 0;
void adicionarConta(TConta conta);
void listarContas();             //alterado
void pesquisarConta(int numero); //alterado
TConta getConta(int numero);
int removerConta(int numero);
int checarCad();

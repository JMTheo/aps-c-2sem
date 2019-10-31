#include "cliente.h"
#define QTD_CLIENTES 2
TCliente clientes[QTD_CLIENTES];
int totalClientes = 0;
void adicionarCliente(TCliente cliente);
int existeCPF(TCliente cliente);
char *listarClientes();
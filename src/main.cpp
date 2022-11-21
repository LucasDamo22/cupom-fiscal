#include <iostream>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"
#include "Descontos.h"
#include "Produtos.h"
#include "Compras.h"
#include "Application.h"

int main() {
    Application *app = new Application();
    app->init();
    std::cout<<"main"<<std::endl;
    cout<<app->criaListaCompras();
}
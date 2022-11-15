#include <string>
#include <iostream>
#include <sstream>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"
#include "Compras.h"
#include "Produtos.h"

#include "Application.h"

Application::Application()
{
    this->empresaController = new EmpresaController(new EmpresaService());
}

Application::~Application()
{

}

void Application::init() {
    this->empresa = this->empresaController->readEmpresa();
    this->prods = new Produtos("./data/produtos.csv");
    this->compras = new Compras("./data/compras.csv");
    //cout << this->empresa->toString() << endl;
    cout << this->prods->toString();
    //cout << this->compras->toString();
}

std::string Application::criaCupom(){
    std::stringstream ss;
    float valorFinal;
    float valorDescontos;


    return ss.str();
}
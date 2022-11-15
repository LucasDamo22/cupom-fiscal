#include <string>
#include <iostream>
#include <sstream>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"
#include "Compras.h"
#include "Produtos.h"
#include "Descontos.h"

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
    this->produtos = new Produtos("./data/produtos.csv");
    this->compras = new Compras("./data/compras.csv");
    this->descontos = new Descontos("./data/desconto.csv");
    //cout << this->empresa->toString() << endl;
    //cout << this->produtos->toString();
    //cout << this->compras->toString();
    //cout << this->descontos->toString();
}

std::string Application::criaCupom(){
    std::stringstream ss;
    float valorFinal;
    float valorDescontos;


    return ss.str();
}
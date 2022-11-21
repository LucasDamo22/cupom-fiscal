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

void Application::init()
{
    this->empresa = this->empresaController->readEmpresa();
    this->produtos = new Produtos("./data/produtos.csv");
    this->compras = new Compras("./data/compras.csv");
    this->descontos = new Descontos("./data/desconto.csv");

    // cout << this->empresa->toString() << endl;
    // cout << this->produtos->toString()<<endl;;

    // cout << this->descontos->toString();
    criaCabecalho();
    // cout << this->compras->toString();
}

std::string Application::criaCabecalho()
{
    std::stringstream ss;
    float valorFinal;
    float valorDescontos;
    std::string separador = "--------------------------------------------------------------------------------";
    cout << separador << endl;
    cout << empresa->getNome() << " - Telefone: " << empresa->getTelefone() << endl;
    cout << empresa->getEndereco() << endl;
    cout << "CNPJ: " << empresa->getCnpj() << " - IE: " << empresa->getIe() << endl;
    cout << separador << endl;
    cout << "DOCUMENTO AUXILIAR DA NOTA FISCAL DE CONSUMIDOR ELETRÔNICA" << endl;
    cout << separador << endl;
    cout << "I. CÓDIGO        DESCRIÇÃO                          R$ UN  QTD  DESCONTO VAL(R$)" << endl;
    cout << separador << endl;

    return ss.str();
}

std::string Application::criaListaCompras()
{
    std::stringstream ss;
    //int indextemp;
    // aux = this->compras->getIdCompra(0);
    // aux = this->compras->getQtdCompra(0);
    for (int j = 0; j < produtos->getSize(); j++)
    {
        int qtdItems = 0;
        for (int i = 0; i < compras->getSize(); i++)
        {

            if (compras->getIdCompra(i) == produtos->getCodBarras(j))
            {
                qtdItems++;
            }
        }
        ss << produtos->getDescricao(j) << "   " << produtos->getPreco(j)<< "   ";
        ss << qtdItems<<std::endl;
    }

    return ss.str();
}
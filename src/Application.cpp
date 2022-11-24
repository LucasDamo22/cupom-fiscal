#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

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
    //cout << descontos->getCodbarras(0);
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
    // int indextemp;
    //  aux = this->compras->getIdCompra(0);
    //  aux = this->compras->getQtdCompra(0);
    //std::string aux = descontos->getCodbarras(0);
    //std::cout<<aux<<std::endl;
        float qtdItems;
        float valorItems;
        
        float valorTotal;
        std::string tipoDeVenda;
        std::string desconto = "  n tem desc";
        int desc;
    
    for (int j = 0; j < produtos->getSize(); j++)
    {
        float valorDesc=0;
        qtdItems=0;
        if (produtos->getTipodeVenda(j) == "unidade")
            tipoDeVenda = "UN";
        if (produtos->getTipodeVenda(j) == "granel")
            tipoDeVenda = "KG";
        for (int i = 0; i < compras->getSize(); i++)
        {
            if (compras->getIdCompra(i) == produtos->getCodBarras(j))
            {
                qtdItems += compras->getQtdCompra(i);
            }
        }
        //desconto = descontos->verificaDesconto(produtos->getCodBarras(j));
        desc = descontos->verificaQualDesc(produtos->getCodBarras(j));

        if(desc == 1){
            valorDesc = produtos->getPreco(j) * descontos->getDescItemA(produtos->getCodBarras(j)) * qtdItems;
            
        }
        if(desc == 2){ 
            int aux=0;
            double intpart=0, floatpart=0;
            for(int i = 0;i<compras->getSize();i++){
                if (compras->getIdCompra(i) == produtos->getCodBarras(j))
                {
                    aux++;
                }
            }
            aux = aux/4;
            floatpart = modf(aux,&intpart);//função para separar parte inteira, da parte decimal
            valorDesc = (produtos->getPreco(j)*intpart);
        }
        if(desc == 3){
            
        }
        valorItems = (produtos->getPreco(j)*qtdItems)-valorDesc;
        if (qtdItems > 0)
        {
            ss << produtos->getDescricao(j) << "   " << produtos->getPreco(j) << "   ";
            ss << qtdItems << "   " << tipoDeVenda << "   "<<valorDesc<< "   "<< valorItems <<"   "<<desc<<std::endl;
        }
        
    }
    return ss.str();
}
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"
#include "Compras.h"
#include "Produtos.h"
#include "Descontos.h"

#include "Application.h"

#define tamanho 80

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
    cout<<criaCabecalho();
    // cout << descontos->getCodbarras(0);
    //  cout << this->compras->toString();
}
std::string Application::getNumFiscal()
{

    std::string filename = "./data/numcupom.csv";
    std::string line, word;
    vector<std::string> fields;
    vector<vector<std::string>> cupom;
    int num;
    int serie;

    std::ifstream filein;
    filein.open(filename);

    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        cupom.push_back(fields);
    }
    filein.close();

    num = stoi(cupom[0][0]);
    serie = stoi(cupom[0][1]);
    if (num < 999)
    {
        num++;
    }
    else
    {
        num = 1;
        serie++;
    }

    time_t time_ptr;
    time_ptr = time(NULL);
    tm *tm_local = localtime(&time_ptr);
    std::string dia;
    if (tm_local->tm_mday >= 10)
    {
        dia = to_string(tm_local->tm_mday);
    }
    else
    {
        dia = '0' + to_string(tm_local->tm_mday);
    }
    std::string mes;
    if (tm_local->tm_mon >= 10)
    {
        mes = to_string(tm_local->tm_mon + 1);
    }
    else
    {
        mes = '0' + to_string(tm_local->tm_mon + 1);
    }
    std::string hora;
    if (tm_local->tm_hour >= 10)
    {
        hora = to_string(tm_local->tm_hour);
    }
    else
    {
        hora = '0' + to_string(tm_local->tm_hour);
    }
    std::string min;
    if (tm_local->tm_min >= 10)
    {
        min = to_string(tm_local->tm_min);
    }
    else
    {
        min = '0' + to_string(tm_local->tm_min);
    }
    std::string sec;
    if (tm_local->tm_sec >= 10)
    {
        sec = to_string(tm_local->tm_sec);
    }
    else
    {
        sec = '0' + to_string(tm_local->tm_sec);
    }
    std::string ano = to_string(tm_local->tm_year + 1900);

    std::stringstream ss;
    ss << "--------------------------------------------------------------------------------" << endl;
    ss << "NCF-e: " << cupom[0][0] << " - Série: " << cupom[0][1] << "                         ";
    ss << "Data: " << dia << '/' << mes << '/' << ano;
    ss << " - Hora: " << hora << ':' << min << ':' << sec << endl;
    ss << "--------------------------------------------------------------------------------" << endl;

    std::stringstream aa;
    ofstream fileout;
    fileout.open(filename, ios::trunc);
    aa << to_string(num) + ";" + to_string(serie);
    fileout << aa.str();
    fileout.close();

    return ss.str();
}

std::string Application::criaCabecalho()
{

    std::string empresaDados[3];
    std::string descricaoCupom = "DOCUMENTO AUXILIAR DA NOTA FISCAL DE CONSUMIDOR ELETRÔNICA";
    int aux;
    empresaDados[0] = empresa->getNome() + " - Telefone: " + empresa->getTelefone();
    aux = tamanho - empresaDados[0].size();
    for (int i = 0; i < aux / 2; i++)
    {
        empresaDados[0] = " " + empresaDados[0] + " ";
    }

    empresaDados[1] = empresa->getEndereco();
    aux = tamanho - empresaDados[1].size();
    for (int i = 0; i < aux / 2; i++)
    {
        empresaDados[1] = " " + empresaDados[1] + " ";
    }

    empresaDados[2] = "CNPJ: " + empresa->getCnpj() + " - IE: " + empresa->getIe();
    aux = tamanho - empresaDados[2].size();
    for (int i = 0; i < aux / 2; i++)
    {
        empresaDados[2] = " " + empresaDados[2] + " ";
    }

    aux = tamanho - descricaoCupom.size();
    for (int i = 0; i < aux / 2; i++)
    {
        descricaoCupom = " " + descricaoCupom + " ";
    }

    std::stringstream ss;
    float valorFinal;
    float valorDescontos;
    std::string separador = "--------------------------------------------------------------------------------";
    ss << separador << endl;
    for (int i = 0; i < 3; i++)
    {
        ss << empresaDados[i] << endl;
    }
    ss << separador << endl;
    ss << descricaoCupom << endl;
    ss << separador << endl;
    ss << "I. CÓDIGO        DESCRIÇÃO                          R$ UN  QTD  DESCONTO VAL(R$)" << endl;
    ss << separador << endl;
    //ss << this->produtos->toString();

    return ss.str();
}

std::string Application::criaListaCompras()
{
    std::stringstream ss;
    // int indextemp;
    //  aux = this->compras->getIdCompra(0);
    //  aux = this->compras->getQtdCompra(0);
    // std::string aux = descontos->getCodbarras(0);
    // std::cout<<aux<<std::endl;
    std::string separador = "--------------------------------------------------------------------------------";
    float qtdItems;
    float valorItems;
    int pos = 1;
    std::string posi;
    std::string aux;

    float valorTotal=0;
    std::string tipoDeVenda;
    std::string desconto = "  n tem desc";
    int desc;
    vector<string> descontos3;
    vector<string> fields;
    vector<vector<string>> comprasVet;

    for (int j = 0; j < produtos->getSize(); j++)
    {
        for (int i = 0; i < descontos->getSize(); i++)
        {
            // if(produtos->getCodBarras(j)==descontos->getCodbarrasA(produtos->getCodBarras(j))){
            //     descontos3.push_back(descontos->getCodBarrasB(produtos->getCodBarras(j)));
            // }
            if (produtos->getCodBarras(j) == descontos->getCodbarrasA(i) && descontos->getCodbarrasB(i) != "")
            {
                descontos3.push_back(descontos->getCodbarrasB(i));
            }
        }
    }
    for (int i = 0; i < descontos3.size(); i++)
    {
        cout << descontos3[i] << endl;
    }

    for (int j = 0; j < produtos->getSize(); j++)
    {
        float valorDesc = 0;
        qtdItems = 0;
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

        desc = descontos->verificaQualDesc(produtos->getCodBarras(j));

        if (desc == 1)
        {
            valorDesc = produtos->getPreco(j) * descontos->getDescItemA(produtos->getCodBarras(j)) * qtdItems;
        }
        if (desc == 2)
        {
            int aux = 0;
            double intpart = 0, floatpart = 0;
            for (int i = 0; i < compras->getSize(); i++)
            {
                if (compras->getIdCompra(i) == produtos->getCodBarras(j))
                {
                    aux++;
                }
            }
            aux = aux / 4;
            floatpart = modf(aux, &intpart); // funÃ§Ã£o para separar parte inteira, da parte decimal
            valorDesc = (produtos->getPreco(j) * intpart);
        }
        if (desc == 3)
        {
        }
        valorItems = (produtos->getPreco(j) * qtdItems) - valorDesc;
        valorTotal +=valorItems;
        if (qtdItems > 0)
        {
            if (pos >= 10)
            {
                posi = to_string(pos);
            }
            else
            {
                posi = '0' + to_string(pos);
            }
            fields.push_back(to_string(j));              // 0
            fields.push_back(produtos->getDescricao(j)); // 1
            fields.push_back("   ");
            fields.push_back(to_string(produtos->getPreco(j))); // 3
            fields.push_back("   ");
            fields.push_back(to_string(qtdItems)); // 5
            fields.push_back("   ");
            fields.push_back(tipoDeVenda); // 7
            fields.push_back("   ");
            fields.push_back(to_string(valorDesc)); // 9
            fields.push_back("   ");
            fields.push_back(to_string(valorItems)); // 11
            fields.push_back("   ");
            fields.push_back(to_string(desc)); // 13
            ss.precision(4);
            aux = posi + " " + produtos->getCodBarras(j) + " " + produtos->getDescricao(j);
            ss << posi << " " << produtos->getCodBarras(j) << " " << produtos->getDescricao(j);
            if (aux.size() >= 50)
            {

                ss << endl
                   << " ";

                for (int i = to_string(produtos->getPreco(j)).size(); i < 57; i++)
                {
                    ss << " ";
                }
                if (valorDesc == 0)
                {
                    ss << produtos->getPreco(j) << " " << tipoDeVenda << "   " << qtdItems <<"            "<<valorItems<< endl;
                }
                else
                {
                    ss << produtos->getPreco(j) << " " << tipoDeVenda << "   " << qtdItems << " -" << (valorDesc) <<"            "<<valorItems<< endl;
                }
            }
            else
            {
                for (int i = aux.size(); i < (58 - to_string(produtos->getPreco(j)).size()); i++)
                {
                    ss << " ";
                }
                if (valorDesc == 0)
                {
                    ss << produtos->getPreco(j) << " " << tipoDeVenda << "   " << qtdItems <<"            "<<valorItems<< endl;
                }
                else
                {
                    ss << produtos->getPreco(j) << " " << tipoDeVenda << "   " << qtdItems << " -" << (valorDesc) <<"            "<<valorItems<<endl;
                }
            }
            pos++;
        }
    }
    ss<<separador<<endl;
    for (int i = 0; i < 50;  i++)
                {
                    ss << " ";
                }
    ss<<"TOTAL: "<<valorTotal<<endl<<getNumFiscal();
    return ss.str();
}
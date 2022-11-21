#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

class Application
{
public:
    Application();
    ~Application();
    void init();
    std::string criaCabecalho();
    std::string getNCupom();
    std::string criaListaCompras();
private:
    EmpresaController *empresaController;
    Empresa *empresa;
    Produtos *produtos;
    Compras *compras;
    Descontos *descontos;
    std::string cupomFiscal;
};

#endif
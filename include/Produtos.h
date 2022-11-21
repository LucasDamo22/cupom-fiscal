#ifndef PRODUTOS_H
#define PRODUTOS_H

#pragma once
#include <vector>

class Produtos{
    std::vector<std::string> fields;
    std::vector<std::vector<std::string>> produtos;
    public:
    Produtos(std::string filename);
    ~Produtos();
    std::string toString();
    
    std::string getCodBarras(int i);
    std::string getDescricao(int i);
    std::string getTipodeVenda(int i);
    std::string getTipoMedida(int i);
    float getQtdOuMedida(int i);
    float getPreco(int i);
    int getSize();
    
};


#endif
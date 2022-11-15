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
    
};


#endif
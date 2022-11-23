#ifndef DESCONTOS_H
#define DESCONTOS_H



#include <vector>

class Descontos{
    std::vector<std::string> fields;
    std::vector<std::vector<std::string>> descontos;
    public:
    Descontos(std::string filename);
    ~Descontos();
    std::string toString();
    std::string getCodbarras(int i);
    int getSize();
    std::string verificaDesconto(std::string id);
    bool verificaDesc(std::string id);
    
};

#endif
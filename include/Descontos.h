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
    
    int getSize();
    
    int verificaQualDesc(std::string id);


    std::string getCodbarrasA(std::string id);
    float getDescItemA(std::string id);
    int leveX(std::string id);
    float pagueX(std::string id);
    std::string getCodBarrasB(std::string id);
    float getDescItemB(std::string id);
    
};

#endif
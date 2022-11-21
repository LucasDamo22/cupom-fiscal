
#include <string>
#include <sstream>
#include <fstream>
#include "Compras.h"

Compras::Compras(std::string filename){
    std::string line, word;

    std::ifstream filein;
    filein.open(filename);

    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        compras.push_back(fields);
    }
}

std::string Compras::toString(){
    std::stringstream ss;
    for(int i =0;i<compras.size();i++){
    for(int j=0;j<compras[i].size();j++){
        ss<<compras[i][j];
    }
    ss<<std::endl;
    }
    return ss.str();
}
std::string Compras::getIdCompra(int i){
    return compras[i][0];
}
std::string Compras::getQtdCompra(int i){
    return compras[i][1];
}
int Compras::getSize(){
    return compras.size();
}
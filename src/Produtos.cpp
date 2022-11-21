

#include <string>
#include <sstream>
#include <fstream>

#include "Produtos.h"
Produtos::Produtos(std::string filename){
    
    std::string line, word;

    std::ifstream filein;
    filein.open(filename);

    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        produtos.push_back(fields);
    }
}

std::string Produtos::toString(){
    std::stringstream ss;
for(int i =0;i<produtos.size();i++){
    for(int j=0;j<produtos[i].size();j++){
        ss<<produtos[i][j];
    }
    ss<<std::endl;
    }
    return ss.str();
}

std::string Produtos::getCodBarras(int i){
return produtos[i][0];
}
std::string Produtos::getDescricao(int i){
return produtos[i][1];
}
std::string Produtos::getTipodeVenda(int i){
return produtos[i][2];
}
std::string Produtos::getTipoMedida(int i){
return produtos[i][3];   
}
float Produtos::getQtdOuMedida(int i){
return std::stof(produtos[i][4]);
}
float Produtos::getPreco(int i){
return std::stof(produtos[i][5]);
}
int Produtos::getSize(){
    return produtos.size();
}
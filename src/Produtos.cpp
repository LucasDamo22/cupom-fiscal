

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
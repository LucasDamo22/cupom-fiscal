
#include <sstream>
#include <fstream>
#include <iostream>

#include "Descontos.h"
#include <string>
Descontos::Descontos(std::string filename){
    std::string line, word;

    std::ifstream filein;
    filein.open(filename);

    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        descontos.push_back(fields);
    }
}
std::string Descontos::toString(){
    std::stringstream ss;
for(int i =0;i<descontos.size();i++){
    for(int j=0;j<descontos[i].size();j++){
        ss<<descontos[i][j];
    }
    ss<<std::endl;
    }
    return ss.str();

}
int Descontos::verificaDesconto(std::string id){
    
    for(int i = 0;i<descontos.size();i++){
        for( int j = 0;j<6;j++){

        
        if(id==descontos[i][j]){
            
            return 1;
        }
        }
    }
    return 0;
}
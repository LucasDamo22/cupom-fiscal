#include <fstream>   // para usar file streams (ifstream, ofstream)
#include <iostream>  // para usar cin, cout
#include <string>    // para usar string
#include <iomanip>   // para usar manip. (setw, right, ...)
#include <cstdlib>   // para usar srand(), rand() e exit()
#include <ctime>     // para usar time()
#include <vector>

#include "Empresa.h"
#include "EmpresaService.h"

using namespace std;

EmpresaService::EmpresaService()
{

}

EmpresaService::~EmpresaService()
{

}

Empresa* EmpresaService::get(){
    std::string line, word;

    std::vector<std::string> fields;
    std::vector<std::vector<std::string>> enderecoDiv;//lista com os campos do endereço
    std::vector<std::vector<std::string>> empresaDados;
    

    std::ifstream filein;
    filein.open("./data/empresa.csv");

    
    

    
    std::stringstream enderecoAux;//auxiliar para separar os campos do endereço

    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        empresaDados.push_back(fields);
    }
        std::string nome = empresaDados[0][0];
        std::string cnpj = empresaDados[0][1];
        std::string ie =   empresaDados[0][2];
        enderecoAux << empresaDados[0][3];
        std::string telefone = empresaDados[0][4];
        
        std::string aux;
    while (getline(enderecoAux,aux))
    {
        fields.clear();

        std::stringstream str(aux);

        while(getline(str,word,':')){
            fields.push_back(word);}
            enderecoDiv.push_back(fields);
    }
    std::string rua = enderecoDiv[0][0];//campos do endereço
    std::string numero = enderecoDiv[0][1];
    std::string bairro = enderecoDiv[0][2];
    std::string cidade = enderecoDiv[0][3];
    std::string estado = enderecoDiv[0][4];
    std::string cep = enderecoDiv[0][5];

    std::string endereco = rua + ", " + numero + " - " + bairro + " - " + cidade + "-" + estado + " CEP " + cep;
   
    

    

    Empresa *empresa = new Empresa(nome, cnpj, ie, telefone, new Endereco(endereco));
    return empresa;
}
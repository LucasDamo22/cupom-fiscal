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
    std::vector<std::vector<std::string>> content;
    

    std::ifstream filein;
    filein.open("./data/empresa.csv");

    std::string nome;
    std::string cnpj;
    std::string ie;
    std::string telefone;
    std::string endereco;
    while (getline(filein, line))
    {
        fields.clear();

        std::stringstream str(line);

        while (getline(str, word, ';'))
            fields.push_back(word);
        content.push_back(fields);
    }
        nome = content[0][0];
        cnpj = content[0][1];
        ie =   content[0][2];
        endereco = content[0][3];
        telefone = content[0][4];

    

    Empresa *empresa = new Empresa(nome, cnpj, ie, telefone, new Endereco(endereco));
    return empresa;
}
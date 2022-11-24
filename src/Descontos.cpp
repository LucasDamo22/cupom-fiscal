
#include <sstream>
#include <fstream>
#include <iostream>

#include "Descontos.h"
#include <string>
Descontos::Descontos(std::string filename)
{
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
std::string Descontos::toString()
{
    std::stringstream ss;
    for (int i = 0; i < descontos.size(); i++)
    {
        for (int j = 0; j < descontos[i].size(); j++)
        {
            ss << descontos[i][j];
        }
        ss << std::endl;
    }
    return ss.str();
}

int Descontos::getSize()
{
    return descontos.size();
}

std::string Descontos::getCodbarrasA(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return descontos[i][0];
        }
    }
    return 0;
}
std::string Descontos::getCodbarrasA(int i)
{
    return descontos[i][0];
}
float Descontos::getDescItemA(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return stof(descontos[i][1]);
        }
    }
    return 0;
}
int Descontos::leveX(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return stoi(descontos[i][2]);
        }
    }
    return 0;
}
float Descontos::pagueX(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return stof(descontos[i][3]);
        }
    }
    return 0;
}
std::string Descontos::getCodBarrasB(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return descontos[i][4];
        }
    }
    return 0;
}
std::string Descontos::getCodbarrasB(int i)
{
    return descontos[i][4];
}

float Descontos::getDescItemB(std::string id)
{
    for (int i = 0; i < descontos.size(); i++)
    {
        if (id == descontos[i][0])
        {
            return stof(descontos[i][5]);
        }
    }
    return 0;
}

int Descontos::verificaQualDesc(std::string id)
{
    int a = 0;
    for (int i = 0; i < descontos.size(); i++)
    {
        if ((id == descontos[i][0]) && (i<1))//desconto de preço unitário
        {
            a = 1;
        }
        else if(id==descontos[i][0] && descontos[i][1]=="" && descontos[i][4]==""){
            a = 2;
        }
        else if(id==descontos[i][0] && descontos[i][1]=="" && descontos[i][4]!=""){
            a = 3;
        }
    }
    return a;
}
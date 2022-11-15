#ifndef DESCONTOS_H
#define DESCONTOS_H

#pragma once
#include <vector>
class Descontos
{
    std::vector<std::string> fields;
    std::vector<std::vector<std::string>> descontos;
    public:
    Descontos(std::string filename);
};

#endif
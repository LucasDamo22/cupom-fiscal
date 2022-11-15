#ifndef COMPRAS_H
#define COMPRAS_H

#pragma once

#include <vector>

class Compras
{
private:
    std::vector<std::string> fields;
    std::vector<std::vector<std::string>> compras;
public:
    Compras(std::string filename);
    ~Compras();
    std::string toString();
    





};





#endif
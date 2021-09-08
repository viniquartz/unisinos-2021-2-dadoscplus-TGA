#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include <fstream>

#include "REGISTRO.h"

class Sistema
{
private:
    std::vector<Registro> dados;
public:
    Sistema();
    Sistema(std::string arqLog);
    Registro getRegistros();
    void PrintRegistros(Registro registro);
    void cabecalho();
    void menu();
};

#endif // SISTEMA_H
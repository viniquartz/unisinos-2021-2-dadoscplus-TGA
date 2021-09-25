#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include <fstream>

#include "REGISTRO.h"

class Sistema
{
private:
    std::vector<Registro*> dados;
public:
    Sistema();
    Sistema(std::string arqLog);
    void cabecalho();
    void menu();

    void localizarCVE_ID();
};

#endif // SISTEMA_H
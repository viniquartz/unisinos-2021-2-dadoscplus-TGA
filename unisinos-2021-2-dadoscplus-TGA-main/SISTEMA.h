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
    //AUX
    void cabecalho();
    void menu();
    //TEMP
    void temp_verificarRegidtros();
    //ID CVE
    void cabecalho_localizarCVE_ID();
    void localizarCVE_ID();
    //DESCRIPTION
    void cabecalho_localizarDescription();
    void localizarDescription();
    //EXPORT DATA
    void cabecalho_exportData();
    void exportData();
};

#endif // SISTEMA_H
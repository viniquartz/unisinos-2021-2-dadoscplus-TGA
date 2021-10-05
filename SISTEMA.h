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
    //Construtor
    Sistema();
    Sistema(std::string arqLog);
    //Destrutor
    //~Sistema();
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
    //HISTOGRAMA
    void cabecalho_histograma();
    void histograma_grafico(int grupo);
    void histograma();
    //EXPORT DATA
    void cabecalho_exportData();
    void exportData();
};

#endif // SISTEMA_H
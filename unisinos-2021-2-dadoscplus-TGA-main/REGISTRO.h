#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <sstream>
#include "DATE.h"

class Registro
{
private:
    std::string idCVE;
    int idCWE;
    std::string vulnerabilityTypes;
    DATE* publishDate;
    DATE* updateDate;
    float scoreCVSS;
    std::string gainedAccessLevel;
    std::string access;
    std::string complexity;
    std::string authentication;
    std::string confidentialy;
    std::string integrity;
    std::string availability;
    std::string description;
public:
    Registro();
    Registro(std::string linha);
    ~Registro();
    // Quantidade de dias que a vulnerabilidade ficou em aberto
    int openedDays(); 
    // Métodos getter
    //type getters();
    std::string get_idCVE();
    int get_idCWE();
    std::string get_vulnerabilityTypes();
    float get_scoreCVSS();
    std::string get_gainedAccessLevel();
    std::string get_access();
    std::string get_complexity();
    std::string get_authenticationP();
    std::string get_confidentialy();
    std::string get_integrity();
    std::string get_availability();
    std::string get_description();
    std::string get_DAY();
    // Métodos adicionais
    //void printRegistros();

    //SERIALIZAR
    std::string toExport();

    //ID CVE
    void print_localizarCVE_ID();
    //DESCRIPTION
    void print_localizarDescription();
};

#endif //REGISTRO_H
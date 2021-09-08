#include <iostream>
#include "REGISTRO.h"

using namespace std;

Registro::Registro(){
    idCVE = 0;
    idCWE = 0;
    scoreCVSS = 0;
}

int Registro::openedDays(){
    return 0;
}
Registro::~Registro(){}

Registro::Registro(string linha){
    stringstream RegStream(linha);
    //Ignorar 9 caracteres da string
    RegStream.seekg(9);

    RegStream >> idCVE;
    RegStream >> idCWE;

    //Tratar wuando tiver Vulnerability
    //RegStream >> vulnerabilityTypes;

    //Date
    string aux_publishDate, aux_updateDate;
    RegStream >> aux_publishDate;
    RegStream >> aux_updateDate;

    RegStream >> scoreCVSS;

    getline(RegStream, gainedAccessLevel, '\t');
    getline(RegStream, access, '\t');
    getline(RegStream, complexity, '\t');
    getline(RegStream, authentication, '\t');
    getline(RegStream, confidentialy, '\t');
    getline(RegStream, integrity, '\t');
    getline(RegStream, availability, '\t');
    getline(RegStream, description, '\t');
}

//~REGISTRO();
//GETS
int Registro::get_idCVE(){
    return this->idCVE;
}
int Registro::get_idCWE(){
    return this->idCWE;
}
string Registro::get_vulnerabilityTypes(){
    return this->vulnerabilityTypes;
}
float Registro::get_scoreCVSS(){
    return this->scoreCVSS;
}
string Registro::get_gainedAccessLevel(){
    return this->gainedAccessLevel;
}
string Registro::get_access(){
    return this->access;
}
string Registro::get_complexity(){
    return this->complexity;
}
string Registro::get_authenticationP(){
    return this->authentication;
}
string Registro::get_confidentialy(){
    return this->confidentialy;
}
string Registro::get_integrity(){
    return this->integrity;
}
string Registro::get_availability(){
    return this->availability;
}
string Registro::get_description(){
    return this->description;
}
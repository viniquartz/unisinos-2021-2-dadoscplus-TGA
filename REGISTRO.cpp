#include <iostream>
#include "REGISTRO.h"

using namespace std;

Registro::Registro(){
    idCWE = 0;
    scoreCVSS = 0;
}

int Registro::openedDays(){
    return 0;
}
Registro::~Registro(){}

Registro::Registro(string linha){
    stringstream RegStream(linha);
    //ID
    //getline(RegStream, idCVE, '\t');
    RegStream >> idCVE;

    //Tratar Quando tiver CWE
    RegStream.ignore(1);
    if(RegStream.peek()=='\t'){
        RegStream.ignore(1);
        this->idCWE = 0;
    }
    else{
        RegStream >> this->idCWE;
    }

    //Tratar Quando tiver Vulnerability
    RegStream.ignore(1);
    if(RegStream.peek()=='\t'){
        RegStream.ignore(1);
        this->vulnerabilityTypes = "null";
    }
    else{
        getline(RegStream, this->vulnerabilityTypes, '\t');
    }

    //Date
    string aux_publishDate, aux_updateDate;
    getline(RegStream, aux_publishDate, '\t');
    getline(RegStream, aux_updateDate, '\t');

    RegStream >> scoreCVSS;
    RegStream.ignore(1);

    getline(RegStream, gainedAccessLevel, '\t');
    getline(RegStream, access, '\t');
    getline(RegStream, complexity, '\t');
    getline(RegStream, authentication, '\t');
    getline(RegStream, confidentialy, '\t');
    getline(RegStream, integrity, '\t');
    getline(RegStream, availability, '\t');
    getline(RegStream, description);
}

//~REGISTRO();
//GETS
string Registro::get_idCVE(){
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

//PRINT
// void Registro::printRegistros(){
//     vector<Registro*>::iterator it;
//     for(it =  ; it != Registro->end() ; ++it)
//     {
//         cout << (*it)->get_idCVE() << endl;
//     }
// }
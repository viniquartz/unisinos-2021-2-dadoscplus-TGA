#include <iostream>
#include "REGISTRO.h"

using namespace std;

Registro::Registro(){
    idCWE = 0;
    scoreCVSS = 0;
}

int Registro::openedDays(){
    double open;
    open = difftime(mktime(updateDate->getStructTM()),mktime(publishDate->getStructTM()));
    return open;
}

//Registro::~Registro(){}

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
    publishDate = new DATE(aux_publishDate);
    
    getline(RegStream, aux_updateDate, '\t');
    updateDate = new DATE(aux_updateDate);

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

//SERIALIZAR
string Registro::toExport(){
    stringstream ss_toExport;
    ss_toExport << get_idCVE() << '\t'
                << get_idCWE() << '\t'
                << get_vulnerabilityTypes() << '\t'
                //<< publishDate->getStructDAY() << "-" << publishDate->getStructMONTH() << "-" << publishDate->getStructYEAR() << endl;
                //<< updateDate->getStructDAY() << "-" << updateDate->getStructMONTH() << "-" << updateDate->getStructYEAR() << endl;
                //<< this->publishDate << '\t'
                //<< this->updateDate << '\t'
                << get_scoreCVSS() << '\t'
                << get_gainedAccessLevel() << '\t'
                << get_access() << '\t'
                << get_complexity() << '\t'
                << get_authenticationP() << '\t'
                << get_confidentialy() << '\t'
                << get_integrity() << '\t'
                << get_availability() << '\t'
                << get_description();
    return ss_toExport.str();
}
/*
friend ostream& operator<<(ostream& os, const Registro& dados) {
    os << dados.idCVE << '\t';
    os << dados.idCWE << '\t';
    os << dados.vulnerabilityTypes << '\t';
    os << dados.scoreCVSS << '\t';
    os << dados.gainedAccessLevel << '\t';
    os << dados.access << '\t';
    os << dados.complexity << '\t';
    os << dados.authentication << '\t';
    os << dados.confidentialy << '\t';
    os << dados.integrity << '\t';
    os << dados.availability << '\t';
    os << dados.description << '\t'<< endl;
    return os;
}*/


//ID CVE
void Registro::print_localizarCVE_ID(){
    cout << "ID CWE: " << get_idCWE() << endl;
    cout << "scoreCVSS: " << get_scoreCVSS() << endl;
    cout << "Open Days: " << openedDays() << endl;
    cout << endl << "\t\t=====//=====//=====//=====//=====" << endl;
    cout << endl;
}
//DESCRIPTION
void Registro::print_localizarDescription(){
    cout << "ID CVE: " << get_idCVE() << endl;
    cout << "VulnerabilityTypes: " << get_vulnerabilityTypes() << endl;
    cout << "ScoreCVSS: " << get_scoreCVSS() << endl;
    cout << "PublishDate: " << publishDate->getStructDAY() << "/" << publishDate->getStructMONTH() << "/" << publishDate->getStructYEAR() << endl;
    cout << "UpdateDate: " << updateDate->getStructDAY() << "/" << updateDate->getStructMONTH() << "/" << updateDate->getStructYEAR() << endl;
    cout << "Open Days: " << openedDays() << endl;
    cout << endl << "\t\t=====//=====//=====//=====//=====" << endl
         << endl;
}

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
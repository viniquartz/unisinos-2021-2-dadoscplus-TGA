#include <iostream>
#include <time.h>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#define _USE_32BIT_TIME_T 1

#include "DATE.h"
using namespace std;


DATE::DATE(std::string data)
{
         string linha;
         linha = data;
         istringstream iss(linha);
         iss >> datahora.tm_year;
         datahora.tm_year -= 1900;
         iss.ignore(1);
         iss >> datahora.tm_mon;
         iss.ignore(1);
         iss >> datahora.tm_mday;
}

struct tm* DATE::getStructTM(){return &this->datahora;}

int DATE::getStructDAY(){
    int day = 0;
    day = this->datahora.tm_mday; 
    return day;
}

int DATE::getStructMONTH(){
    int month = 0;
    month = this->datahora.tm_mon;
    return month;
}

int DATE::getStructYEAR(){
    int year;
    year = this->datahora.tm_year+1900;
    return year;
}



bool DATE::operator<= (const DATE &param) {
        struct tm end_publishdate = this->datahora;
        struct tm begin_publishdate = param.datahora;
        return difftime(mktime(&end_publishdate),mktime(&begin_publishdate)) <= 0;
    }
bool DATE::operator>= (const DATE &param) {
        struct tm end_publishdate = this->datahora;
        struct tm begin_publishdate = param.datahora;
        return difftime(mktime(&end_publishdate),mktime(&begin_publishdate)) <= 0;
    }
bool DATE::operator< (const DATE &param) {
        struct tm end_publishdate = this->datahora;
        struct tm begin_publishdate = param.datahora;
        return difftime(mktime(&end_publishdate),mktime(&begin_publishdate)) <= 0;
    }
bool DATE::operator> (const DATE &param) {
        struct tm end_publishdate = this->datahora;
        struct tm begin_publishdate = param.datahora;
        return difftime(mktime(&end_publishdate),mktime(&begin_publishdate)) <= 0;
    }
bool DATE::operator== (const DATE &param) {
        struct tm end_publishdate = this->datahora;
        struct tm begin_publishdate = param.datahora;
        return difftime(mktime(&end_publishdate),mktime(&begin_publishdate)) <= 0;
    }
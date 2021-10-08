#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <time.h>

class DATE
{
private:
    struct tm datahora;
public:
    DATE(std:: string data);
    struct tm* getStructTM();
    int getStructDAY();
    int getStructMONTH();
    int getStructYEAR();

  
    bool operator<=(const DATE &param);
    bool operator>=(const DATE &param);
    bool operator>(const DATE &param);
    bool operator<(const DATE &param);
    bool operator==(const DATE &param);
    
    
};
#endif
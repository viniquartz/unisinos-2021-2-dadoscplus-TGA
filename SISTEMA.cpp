#include <iostream>
#include <ctype.h>
#include "SISTEMA.h"

using namespace std;

Sistema::Sistema(){};

Sistema::Sistema(string arqLog)
{
    string linha;
    ifstream myfile(arqLog);
    //ABRE O ARQUIVO
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, linha);
            //SALVA NO CONSTRUTOR
            //Registro R(linha);
            //SALVA NO VECTOR
            //PONTEIRO
            dados.push_back(new Registro(linha));
        }
    }
    else
    {
        cout << "Arquivo nao carregado!" << endl;
        system("pause");
    }
    cout << "Arquivo carregado com " << dados.size() << " linhas" << endl;
    system("pause");
    myfile.close();
}

void Sistema::localizarCVE_ID(){
    vector<Registro*>::iterator it;
    for(it = dados.begin() ; it != dados.end() ; ++it){
        cout << "ID CVE: "<< (*it)->get_idCVE() << endl;
        cout << "ID CWE: "<< (*it)->get_idCWE() << endl;
        cout << "vulnerabilityTypes: "<< (*it)->get_vulnerabilityTypes() << endl;
        cout << "scoreCVSS: "<< (*it)->get_scoreCVSS() << endl;
        cout << "gainedAccessLevel: "<< (*it)->get_gainedAccessLevel() << endl;
        cout << "access: "<< (*it)->get_access() << endl;
        cout << "complexity: "<< (*it)->get_complexity() << endl;
        cout << "authenticationP: "<< (*it)->get_authenticationP() << endl;
        cout << "confidentialy: "<< (*it)->get_confidentialy() << endl;
        cout << "integrity: "<< (*it)->get_integrity() << endl;
        cout << "availability: "<< (*it)->get_availability() << endl;
        cout << "description: "<< (*it)->get_description() << endl;
        cout << "=====//=====//=====//=====" << endl;
        cout << endl;
    }
}

void Sistema::cabecalho()
{
    system("cls");
    cout << "=========================================================" << endl;
    cout << "\t\tREGISTROS CVE" << endl;
    cout << "=========================================================" << endl
         << endl
         << endl;
}

void Sistema::menu()
{
    //CHAMA CONSTRUTOR COM NOME DO ARQUIVO
    Sistema sistema("cve.txt");
    int op;
    do
    {
        cabecalho();
        cout << "||MENU||" << endl
             << endl;
        cout << "1-LOCALIZAR POR 'CVE ID'" << endl;
        cout << "2-LOCALIZAR POR 'DESCRIPTION'" << endl;
        cout << "3-HISTOGRAMA 'SCORE'" << endl;
        cout << "4-EXPORTAR DADOS" << endl;
        cout << "0-SAIR" << endl
             << endl;
        cout << "Selecione a opcao desejada: ";
        cin >> op;
        if (op == 1)
        {
            cout << "op=1" << endl;
            system("pause");
        }
        else if (op == 2)
        {
            cout << "op=2" << endl;
            system("pause");
        }
        else if (op == 3)
        {
            cout << "op=3" << endl;
            system("pause");
        }
        else if (op == 4)
        {
            cout << "op=4" << endl;
            //CHAMA METODO PRINT
            //sistema.PrintRegistros(sistema.getRegistros());
            sistema.localizarCVE_ID();
            system("pause");
        }
        else
        {
            if (op != 0)
            {
                cout << "OPCAO INVALIDA!! TENTE NOVAMENTE." << endl;
                system("pause");
            }
            if (op == 0)
            {
                cout << "FECHANDO PROGRAMA!!" << endl;
            }
        }
    } while (op != 0);
}

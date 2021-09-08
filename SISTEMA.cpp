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
            Registro R(linha);
            //SALVA NO VECTOR
            dados.push_back(R);
            //Ponteiro logs
            //logs.push_back(new Registro(linha));
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

Registro Sistema::getRegistros()
{
    //!!!!!!!!PRECISO DE REPETICAO!!!!!!!!!!!
    /*for(unsigned i=0; i<logs.size(); i++){
        return logs[i];
    }*/
    //Ponteiro logs
    //vector<Registro>::iterator it;
    return dados.at(0);
}

void Sistema::PrintRegistros(Registro registro)
{
    cabecalho();

    //EXIBIR REGISTROS PARA TODOS OS VECTORS
    //cout << "CODIGO: " << *it->getCodigo() << endl;
    cout << "ID CVE: " << registro.get_idCVE() << endl;
    cout << "ID CWE: " << registro.get_idCWE() << endl;
    cout << "vulnerabilityTypes: " << registro.get_vulnerabilityTypes() << endl;
    cout << "scoreCVSS: " << registro.get_scoreCVSS() << endl;
    cout << "gainedAccessLevel: " << registro.get_gainedAccessLevel() << endl;
    cout << "access: " << registro.get_access() << endl;
    cout << "complexity: " << registro.get_complexity() << endl;
    cout << "authenticationP: " << registro.get_authenticationP() << endl;
    cout << "confidentialy: " << registro.get_confidentialy() << endl;
    cout << "integrity: " << registro.get_integrity() << endl;
    cout << "availability: " << registro.get_availability() << endl;
    cout << "description: " << registro.get_description() << endl;
    cout << "=====//=====//=====//=====" << endl;
    cout << endl;

    //system("pause");
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
            //lfiltro();
            system("pause");
        }
        else if (op == 3)
        {
            cout << "op=3" << endl;
            //vfiltro();
            system("pause");
        }
        else if (op == 4)
        {
            cout << "op=4" << endl;
            //CHAMA METODO PRINT
            sistema.PrintRegistros(sistema.getRegistros());
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

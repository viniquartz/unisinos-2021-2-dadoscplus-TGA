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

void Sistema::temp_verificarRegidtros()
{
    vector<Registro *>::iterator it;
    for (it = dados.begin(); it != dados.end(); ++it)
    {
        cout << "ID CVE: " << (*it)->get_idCVE() << endl;
        cout << "ID CWE: " << (*it)->get_idCWE() << endl;
        cout << "vulnerabilityTypes: " << (*it)->get_vulnerabilityTypes() << endl;
        cout << "scoreCVSS: " << (*it)->get_scoreCVSS() << endl;
        cout << "gainedAccessLevel: " << (*it)->get_gainedAccessLevel() << endl;
        cout << "access: " << (*it)->get_access() << endl;
        cout << "complexity: " << (*it)->get_complexity() << endl;
        cout << "authenticationP: " << (*it)->get_authenticationP() << endl;
        cout << "confidentialy: " << (*it)->get_confidentialy() << endl;
        cout << "integrity: " << (*it)->get_integrity() << endl;
        cout << "availability: " << (*it)->get_availability() << endl;
        cout << "description: " << (*it)->get_description() << endl;
        cout << "=====//=====//=====//=====" << endl;
        cout << endl;
    }
}

void Sistema::cabecalho_localizarCVE_ID()
{
    system("cls");
    cabecalho();
    cout << "\t\t| CONSULTA DE REGISTRO POR ID CVE |" << endl
         << endl;
}

void Sistema::localizarCVE_ID()
{
    string consultaCVE;
    cabecalho_localizarCVE_ID();
    cout << "DIGITE ID CVE: ";
    fflush(stdin);
    cin >> consultaCVE;
    vector<Registro *>::iterator it;
    for (it = dados.begin(); it != dados.end(); ++it)
    {
        if ((*it)->get_idCVE() == consultaCVE)
        {
            cabecalho_localizarCVE_ID();
            cout << "\t\t  " << (*it)->get_idCVE() << " ENCONTRADO!!" << endl;
            cout << endl << "| INFORMACES ABAIXO |" << endl
                 << endl;
            (*it)->print_localizarCVE_ID();
            cout << endl;
            system("pause");
        }
        // CRIAR UM ELSE
        // CRIAR UMA REPETIÇÃO PARA O USUARIO TENTAR NOVAMENTE OU VOLTAR AO MENU
    }
}

void Sistema::cabecalho_localizarDescription()
{
    system("cls");
    cabecalho();
    cout << "\t\t| CONSULTA DE REGISTRO POR DESCRIPTION |" << endl
         << endl;
}

void Sistema::localizarDescription()
{
    //Melhorar
    string consultaDescription;
    cabecalho_localizarDescription();
    cout << "DIGITE DESCRICAO: ";
    fflush(stdin);
    getline(cin, consultaDescription);
    cout << endl << consultaDescription << endl;
    vector<Registro *>::iterator it;
    for (it = dados.begin(); it != dados.end(); ++it)
    {
        if ((*it)->get_description().find(consultaDescription) < sizeof( (*it)->get_description() ))
        {
            cabecalho_localizarDescription();
            cout << "DESCRICAO ENCONTRADA: ";
            cout << "" << (*it)->get_description() << endl;
            cout << endl << "| INFORMACES ABAIXO |" << endl
                 << endl;
            (*it)->print_localizarDescription();
            cout << endl;
            system("pause");
        }
        // CRIAR UM ELSE
        // CRIAR UMA REPETIÇÃO PARA O USUARIO TENTAR NOVAMENTE OU VOLTAR AO MENU
    }
}

void Sistema::cabecalho_exportData()
{
    system("cls");
    cabecalho();
    cout << "\t\t| EXPORTAR REGISTROS |" << endl
         << endl;
}

void Sistema::exportData(){
    float begin_scoreCVSS, end_scoreCVSS;
    cabecalho_exportData();
    cout << "| DIGITE AS INFORMACOES SOLICITADAS PARA EXPORTAR O ARQUIVO |" << endl;
    //PUBLISH DATE
    // cout << "DIGITE VALOR INICIAL DO SCORE CVSS: ";
    // fflush(stdin);
    // cin >> begin_scoreCVSS;
    // cout << "DIGITE VALOR FINAL DO SCORE CVSS: ";
    // fflush(stdin);
    // cin >> end_scoreCVSS;
    //CVSS SCORE
    cout << "DIGITE VALOR INICIAL DO SCORE CVSS: ";
    fflush(stdin);
    cin >> begin_scoreCVSS;
    cout << "DIGITE VALOR FINAL DO SCORE CVSS: ";
    fflush(stdin);
    cin >> end_scoreCVSS;

    cabecalho_exportData();
    cout << endl << "CVSS SCORE - INICIAL: " << begin_scoreCVSS << "FINAL:" << end_scoreCVSS;
    //cout PUBLISH DATE
    if (end_scoreCVSS < begin_scoreCVSS){
        cout << endl << "VALORES ERRADOS" << endl;
    }
    else{
        string nameArchive;
        string nameDirectory = "C:\\tmp";
        cout << endl << "DIGITE NOME DO ARQUIVO(SEM EXTENSAO): ";
        fflush(stdin);
        getline(cin, nameArchive);
        cout << endl << "ARQUIVO " << nameArchive+".txt" << "SERA EXPORTADO PARA A PASTA " << nameDirectory << endl;
        vector<Registro *>::iterator it;
        fstream arch_expo(nameDirectory+nameArchive+".txt", iostream::out | iostream::trunc);
        if(arch_expo.is_open()){
            arch_expo << "CVE ID	CWE ID	Vulnerability Types	Publish Date	Update Date	CVSS Score	Gained Access Level	Access	Complexity	Authentication	Confidentialy	Integrity	Availability	Description";
            for (it = dados.begin(); it != dados.end(); ++it){
                if(begin_scoreCVSS <= (*it)->get_scoreCVSS() && (*it)->get_scoreCVSS() <= end_scoreCVSS){
                    arch_expo << endl << (*it)->toExport();
                }
            }
            arch_expo.close();
        }
    }
}

void Sistema::cabecalho()
{
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "\tREGISTROS CVE (Common Vulnerabilities and Exposures" << endl;
    cout << "=====================================================================" << endl
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
            sistema.localizarCVE_ID();
        }
        else if (op == 2)
        {
            sistema.localizarDescription();
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
            sistema.temp_verificarRegidtros();
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

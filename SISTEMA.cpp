#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <fstream>
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

/*Sistema::~Sistema(){
    vector<Registro *>::iterator it;
    for (it = dados.begin(); it != dados.end(); ++it){
        delete *it;
        this->dados.clear();
    }
}*/

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
        cout << "Open Days: " << (*it)->openedDays() << endl;
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
    string consultaDescription;
    int contador_tem = 0;
    int contador_ntem = 0;

    cabecalho_localizarDescription();
    cout << "DIGITE DESCRICAO: ";
    fflush(stdin);
    getline(cin, consultaDescription);
    
    vector<Registro *>::iterator it;
    for (it = dados.begin(); it != dados.end(); ++it)
    {
        size_t found = (*it)->get_description().find(consultaDescription);
        if (found!=std::string::npos)//https://www.cplusplus.com/reference/string/string/find/
        {
            contador_tem++;
            cabecalho_localizarDescription();
            cout << "PESQUISA DA DESCRICAO: "<< consultaDescription << endl << endl;
            cout << "DESCRICAO ENCONTRADA: ";
            cout << "" << (*it)->get_description() << endl;
            cout << endl << "| INFORMACES ABAIXO |" << endl
                 << endl;
            (*it)->print_localizarDescription();
            cout << endl;
            system("pause");
        }
        else{
            contador_ntem++;
        }
    }
    cout << endl << "-> DESCRICAO ENCONTRADA: " << contador_tem << " VEZES" << endl
             << "-> DESCRICAO NAO ENCONTRADA: " << contador_ntem << " VEZES" << endl;
    system("pause");
}

void Sistema::cabecalho_histograma(){
    system("cls");
    cabecalho();
    cout << "\t\t| HISTOGRAMA DOS REGISTROS |" << endl
         << endl;
}

void Sistema::histograma_grafico(int grupo){
    int porcentagem = 100;
    int escala = grupo * porcentagem / dados.size();
    cout << "\t      " << grupo << "\t\t     " << escala << "%" << " = [";
    for(int i = 0; i <= porcentagem; i++){
        if(i < escala){
            cout << "=";
        }
        else{
            cout << ".";
        }
    }
}

void Sistema::histograma(){
    int grupo0 = 0, grupo1 = 0, grupo2 = 0, grupo3 = 0, grupo4 = 0, grupo5 = 0, grupo6 = 0, grupo7 = 0, grupo8 = 0, grupo9 = 0;
    vector<Registro *>::iterator it;
    for(it = dados.begin(); it != dados.end(); it++){
        if((*it)->get_scoreCVSS() >= 0.0 && (*it)->get_scoreCVSS() <= 0.9){
            grupo0++;
        }
        else if((*it)->get_scoreCVSS() >= 1.0 && (*it)->get_scoreCVSS() <= 1.9){
            grupo1++;
        }
        else if((*it)->get_scoreCVSS() >= 2.0 && (*it)->get_scoreCVSS() <= 2.9){
            grupo2++;
        }
        else if((*it)->get_scoreCVSS() >= 3.0 && (*it)->get_scoreCVSS() <= 3.9){
            grupo3++;
        }
        else if((*it)->get_scoreCVSS() >= 4.0 && (*it)->get_scoreCVSS() <= 4.9){
            grupo4++;
        }
        else if((*it)->get_scoreCVSS() >= 5.0 && (*it)->get_scoreCVSS() <= 5.9){
            grupo5++;
        }
        else if((*it)->get_scoreCVSS() >= 6.0 && (*it)->get_scoreCVSS() <= 6.9){
            grupo6++;
        }
        else if((*it)->get_scoreCVSS() >= 7.0 && (*it)->get_scoreCVSS() <= 7.9){
            grupo7++;
        }
        else if((*it)->get_scoreCVSS() >= 8.0 && (*it)->get_scoreCVSS() <= 8.9){
            grupo8++;
        }
        else if((*it)->get_scoreCVSS() >= 9.0 && (*it)->get_scoreCVSS() <= 10.0){
            grupo9++;
        }
    }
    cabecalho_histograma();
    cout << "\t| SCORE |\t| QUANTIDADE |\t| PERCENTUAL |" << endl;
    cout << "     de 0.0 ate 0.9"; histograma_grafico(grupo0); cout << "]" << endl;
    cout << "     de 1.0 ate 1.9"; histograma_grafico(grupo1); cout << "]" << endl;
    cout << "     de 2.0 ate 2.9"; histograma_grafico(grupo2); cout << "]" << endl;
    cout << "     de 3.0 ate 3.9"; histograma_grafico(grupo3); cout << "]" << endl;
    cout << "     de 4.0 ate 4.9"; histograma_grafico(grupo4); cout << "]" << endl;
    cout << "     de 5.0 ate 5.9"; histograma_grafico(grupo5); cout << "]" << endl;
    cout << "     de 6.0 ate 6.9"; histograma_grafico(grupo6); cout << "]" << endl;
    cout << "     de 7.0 ate 7.9"; histograma_grafico(grupo7); cout << "]" << endl;
    cout << "     de 8.0 ate 8.9"; histograma_grafico(grupo8); cout << "]" << endl;
    cout << "     de 9.0 ate 10.0"; histograma_grafico(grupo9); cout << "]" << endl;
    system("pause");
}

void Sistema::cabecalho_exportData()
{
    system("cls");
    cabecalho();
    cout << "\t\t| EXPORTAR REGISTROS |" << endl
         << endl;
}

void Sistema::exportData(){
    Registro R;
    float begin_scoreCVSS = 0, end_scoreCVSS = 0;
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
    cout << endl << "DIGITE VALOR INICIAL DO SCORE CVSS: ";
    fflush(stdin);
    cin >> begin_scoreCVSS;
    cout << "DIGITE VALOR FINAL DO SCORE CVSS: ";
    fflush(stdin);
    cin >> end_scoreCVSS;

    cabecalho_exportData();
    cout << endl << "CVSS SCORE -> INICIAL: " << begin_scoreCVSS << " FINAL: " << end_scoreCVSS;
    //cout PUBLISH DATE
    if (end_scoreCVSS < begin_scoreCVSS){
        cout << endl << "VALORES ERRADOS" << endl;
    }
    else{
        int tam = 0;
        string nameArchive;
        string nameDirectory = "C:\\tmp\\";
        cout << endl << "DIGITE NOME DO ARQUIVO(SEM EXTENSAO): ";
        fflush(stdin);
        getline(cin, nameArchive);
        cout << endl << "| ARQUIVO EXPORTADO PARA " << nameDirectory << nameArchive+".txt |" << endl;
        vector<Registro *>::iterator it;
        fstream arch_expo(nameDirectory+nameArchive+".txt", iostream::out | iostream::trunc);
        if(arch_expo.is_open()){
            arch_expo << "CVE ID	CWE ID	Vulnerability Types	Publish Date	Update Date	CVSS Score	Gained Access Level	Access	Complexity	Authentication	Confidentialy	Integrity	Availability	Description";
            for (it = dados.begin(); it != dados.end(); ++it){
                if((*it)->get_scoreCVSS() >= begin_scoreCVSS  && (*it)->get_scoreCVSS() <= end_scoreCVSS){
                    arch_expo << endl << (*it)->toExport();
                    //arch_expo << R;
                    tam++;
                }
            }
            arch_expo.close();
            cout << endl << tam << " REGISTROS ADICIONADOS!" << endl;
            system("pause");
        }
        else
        {
            cout << "Arquivo nao carregado!" << endl;
            system("pause");
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
             << endl
             << "1-LOCALIZAR POR 'CVE ID'" << endl
             << "2-LOCALIZAR POR 'DESCRIPTION'" << endl
             << "3-HISTOGRAMA 'SCORE'" << endl
             << "4-EXPORTAR DADOS" << endl
             << "5-LISTAR REGISTROS" << endl
             << "0-SAIR" << endl
             << endl;
        cout << "SELECIONE A OPCAO DESEJADA(DE 0 A 5): ";
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
            sistema.histograma();
        }
        else if (op == 4)
        {
            sistema.exportData();
        }
        else if (op == 5)
        {
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
            else if (op == 0)
            {
                //sistema.~Sistema();
                cout << "FECHANDO PROGRAMA!!" << endl;
            }
        }
    } while (op != 0);
}

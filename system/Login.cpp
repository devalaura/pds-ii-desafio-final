#include "Login.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void cadastrar(string nome, string cpf, string username, string senha) {
    ifstream arquivo("usuarios.txt");
    string linha;

        if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo para cadastrar.\n";
        return;
    }
    
    // Pula a primeira linha do arquivo
    if (arquivo.is_open()) {
        getline(arquivo, linha);
    }
    
    arquivo.close();
    
    // Abre o arquivo novamente para append
    ofstream arquivoAppend("usuarios.txt",  ios::app);
    arquivoAppend << username << "," << senha << "," << nome << "," << cpf << ",0" <<  endl;
    arquivoAppend.close();
}

bool verificar_login( string username,  string senha,  string &nome,  string &cpf, int &tipo) {
    ifstream arquivo("usuarios.txt");
    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha_arquivo, nome_arquivo, cpf_arquivo, tipo_str;
        getline(ss, usuario, ',');
        getline(ss, senha_arquivo, ',');
        getline(ss, nome_arquivo, ',');
        getline(ss, cpf_arquivo, ',');
        getline(ss, tipo_str, ',');

        if (usuario == username && senha_arquivo == senha) {
            nome = nome_arquivo;
            cpf = cpf_arquivo;
            tipo =  stoi(tipo_str);
            return true;
        }
    }
    return false;
}

void criar_admin_padrao() {
    ifstream arquivo("usuarios.txt");
    string linha;
    bool admin_existe = false;

    // Verifica se o usuário admin já existe no arquivo
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha, nome, cpf, tipo;
        getline(ss, usuario, ',');
        getline(ss, senha, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');
        getline(ss, tipo, ',');

        if (usuario == "admin") {
            admin_existe = true;
            break;
        }
    }
    arquivo.close();

    // Se o admin não existir, cria o usuário admin padrão
    if (!admin_existe) {
        ofstream out("usuarios.txt", ios::app);
        out << "admin,admin,Admin,0,1\n";
        out.close();
    }
}

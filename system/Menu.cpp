#include "Menu.hpp"
#include "../gerenciamento/Admin.hpp"
#include "../gerenciamento/Cliente.hpp"
#include "Login.hpp"
#include <iostream>
#include <limits>
using namespace std;

void menu() {
    int opcao;
    string input;
    string username, senha, nome, cpf;
    bool login_realizado = false;

    // roda o menu até que o usuário decida desligar o sistema
    while (true) {
        cout << "1. Cadastrar\n2. Fazer Login\n3. Desligar sistema\nEscolha: ";
        while (true) {
            getline(cin, input);
            
            try {
                opcao = stoi(input);
                break;
            } catch (const invalid_argument& e) {
                cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        switch (opcao) {
            case 1:
                // realiza o cadastro do usuario
                cout << "Digite o nome: ";
                getline(  cin, nome); 
                cout << "Digite o CPF: ";
                getline(  cin, cpf);  
                cout << "Digite o username: ";
                getline(  cin, username);
                cout << "Digite a senha: ";
                getline(  cin, senha);
                cadastrar(nome, cpf, username, senha);
                break;

            case 2:
                // realiza o login do usuario
                cout << "Digite o username: ";
                getline(  cin, username);
                cout << "Digite a senha: ";
                getline(  cin, senha);
                int tipo;

                // verifica se os dados estão corretos e qual o tipo de usuario (admin ou cliente)
                if (verificar_login(username, senha, nome, cpf, tipo)) {
                    cout << "Login realizado com sucesso!\n";

                    // abre o menu correto (admin ou cliente) dependendo do tipo que está no arquivo
                    if (tipo == 1) {
                        Admin admin(nome, cpf, username, senha);
                        admin.menu();
                    } else {
                        Cliente cliente(nome, cpf, username, senha);
                        cliente.menu();
                    }
                } else {
                    cout << "Username ou senha incorretos. Tente novamente.\n";
                }
                cin.ignore(); // remove qualquer entrada residual que possa interferir em leituras subsequentes
                break;

            case 3:
                cout << "Desligando sistema...\n";
                return;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}
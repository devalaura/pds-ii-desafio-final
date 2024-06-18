#include "Menu.hpp"
#include "../GerenciamentoBiblioteca/Admin.hpp"
#include "../GerenciamentoBiblioteca/Cliente.hpp"
#include "Login.hpp"
#include <iostream>
#include <limits>
using namespace std;

void menu() {
    int opcao;
    string input;
    string username, senha, nome, cpf;
    bool login_realizado = false;

    while (true) {
        cout << "1. Cadastrar\n2. Fazer Login\n3. Desligar sistema\nEscolha: ";
        while (true) {
            getline(  cin, input);
            try {
                opcao = stoi(input);
                break;
            } catch (const   invalid_argument& e) {
                cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        switch (opcao) {
            case 1:
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
                cout << "Digite o username: ";
                getline(  cin, username);
                cout << "Digite a senha: ";
                getline(  cin, senha);
                int tipo;
                if (verificar_login(username, senha, nome, cpf, tipo)) {
                    cout << "Login realizado com sucesso!\n";
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
                cin.ignore(); // Consume any remaining newline characters
                break;
            case 3:
                cout << "Desligando sistema...\n";
                return;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}
#include "Cliente.hpp"
#include "./../model/Livro.hpp"
#include <iostream>
#include <limits>
#include "./../database/interfaces/Repository.hpp"

Cliente::Cliente(string nome, string cpf, string username, string senha)
    : Pessoa(nome, cpf, username, senha, 0) {}

void Cliente::menu() {
    int opcao;
    string input;

    Repository* repo = new Repository();
    
    while (true) {
        cout << "1. Pegar Livro\n2. Devolver Livro\n3. Listar Livros\n4. Deslogar\nEscolha: ";
        while (true) {
            getline(cin, input);
            try {
                opcao = stoi(input);
                break;
            } catch (const invalid_argument& e) {
                cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        vector<Livro> livros;
        switch (opcao) {
            case 1:
                cout << "Pegar Livro (em desenvolvimento)\n";
                break;
            case 2:
                cout << "Devolver Livro (em desenvolvimento)\n";
                break;
            case 3:
                cout << "Listar Livros\n";
                livros = repo->get_all_books();
                for (Livro livro : livros) {
                    cout << "Titulo: " << livro.getTitulo() << "\n";
                    cout << "Autor: " << livro.getAutor() << "\n";
                    cout << "Ano de publicacao: " << livro.getAnoDePublicacao() << "\n";
                    cout << "ISBN: " << livro.getIsbn() << "\n\n";
                }
                break;
            case 4:
                cout << "Deslogando...\n";
                return;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}
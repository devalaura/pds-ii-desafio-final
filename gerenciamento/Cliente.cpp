#include "Cliente.hpp"
#include "./../model/Livro.hpp"
#include <iostream>
#include <limits>
#include "./../database/interfaces/Repository.hpp"

Cliente::Cliente(string nome, string cpf, string username, string senha)
    : Pessoa(nome, cpf, username, senha, 0) {}

void Cliente::listarLivros() {
    cout << "Listar Livros\n";
    vector<Livro> livros = repo->get_available_books();
    for (Livro livro : livros) {
        cout << "Titulo: " << livro.getTitulo() << "\n";
        cout << "Autor: " << livro.getAutor() << "\n";
        cout << "Ano de publicacao: " << livro.getAnoDePublicacao() << "\n";
        cout << "ISBN: " << livro.getIsbn() << "\n\n";
    }
}

void Cliente::pegarLivro(int isbn) {
    vector<Livro> livros = repo->get_available_books();

    for (Livro livro : livros) {
        if (livro.getIsbn() == isbn) {
            livro.setDisponivel(1);
            repo->update_book_by_isbn(livro);
            cout << "O livro '" << livro.getTitulo() << "' com ISBN " << isbn << " foi pego com sucesso.\n";
            return;
        }
    }

    cout << "Livro com ISBN " << isbn << " não encontrado ou já está alugado.\n";
    
}
void Cliente::devolverLivro(int isbn) {
    vector<Livro> livros = repo->get_unavailable_books();

    for (Livro livro : livros) {
        if (livro.getIsbn() == isbn) {
            livro.setDisponivel(0);
            repo->update_book_by_isbn(livro);
            cout << "O livro '" << livro.getTitulo() << "' com ISBN " << isbn << " foi devolvido com sucesso.\n";
            return;
        }
    }

    cout << "Livro com ISBN " << isbn << " não encontrado ou já está disponível.\n";
}


void Cliente::menu() {
    int opcao;
    string input;
    while (true) {
        cout << "1. Pegar Livro\n2. Devolver Livro\n3. Listar Livros\n4. Deslogar\nEscolha: ";
        while (true) {
            getline(cin, input);
            try {
                opcao = stoi(input);
                break;
            }
            catch (const invalid_argument& e) {
                cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        switch (opcao) {
        case 1:
            int isbn;
            cout << "Digite o ISBN do livro que voce deseja alugar:\n";
            getline(cin, input);
            try {
                isbn = stoi(input);
                pegarLivro(isbn);
            }
            catch (const invalid_argument& e) {
                cout << "ISBN invalido. Tente novamente.\n";
            }
            break;
        case 2: {
            int isbn;
            cout << "Digite o ISBN do livro que voce deseja devolver:\n";
            getline(cin, input);
            try {
                isbn = stoi(input);
                devolverLivro(isbn);
            }
            catch (const invalid_argument& e) {
                cout << "ISBN invalido. Tente novamente.\n";
            }
            break;
        }
        case 3:
            cout << endl << "Livros disponiveis na biblioteca: " << endl;
            listarLivros();
            break;
        case 4:
            cout << "Deslogando...\n";
            cout << "Pressione enter para continuar...";
            return;
        default:
            cout << "Opcao invalida. Tente novamente. " << endl;
        }
    }
}

#include "Admin.hpp"
#include "Livro.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
using namespace std;

Admin::Admin(string nome, string cpf, string username, string senha)
    : Pessoa(nome, cpf, username, senha, 1) {}

void Admin::set_admin(string username) {
    fstream arquivo("usuarios.txt", ios::in | ios::out);
    string linha;
    bool encontrado = false;
    string conteudo;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha, nome, cpf, tipo;
        getline(ss, usuario, ',');
        getline(ss, senha, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');
        getline(ss, tipo, ',');

        if (usuario == username) {
            encontrado = true;
            linha = usuario + "," + senha + "," + nome + "," + cpf + ",1";
        }
        conteudo += linha + "\n";
    }

    arquivo.close(); // Fechar o arquivo para reabrir em modo de escrita
    arquivo.open("usuarios.txt", ios::out | ios::trunc); // Abrir em modo de escrita truncando o conteúdo anterior

    if (arquivo.is_open()) {
        arquivo << conteudo; // Escrever o conteúdo modificado de volta no arquivo
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para escrita.\n";
    }

    if (encontrado) {
        cout << "Admin definido para o usuario.\n";
    } else {
        cout << "Usuario nao encontrado.\n";
    }
}


void Admin::remove_admin(string username) {
    fstream arquivo("usuarios.txt", ios::in | ios::out);
    string linha;
    bool encontrado = false;
    string conteudo;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha, nome, cpf, tipo;
        getline(ss, usuario, ',');
        getline(ss, senha, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');
        getline(ss, tipo, ',');

        if (usuario == username) {
            encontrado = true;
            linha = usuario + "," + senha + "," + nome + "," + cpf + ",0";
        }
        conteudo += linha + "\n";
    }

    arquivo.close(); // Fechar o arquivo para reabrir em modo de escrita
    arquivo.open("usuarios.txt", ios::out | ios::trunc); // Abrir em modo de escrita truncando o conteúdo anterior

    if (arquivo.is_open()) {
        arquivo << conteudo; // Escrever o conteúdo modificado de volta no arquivo
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para escrita.\n";
    }

    if (encontrado) {
        cout << "Administracao removida do usuario.\n";
    } else {
        cout << "Usuário não encontrado.\n";
    }
}


void Admin::menu() {
    int opcao;
    string input;
    Livro livro;
    vector<Livro> livros;
    string arquivo = "livros.txt";

    // Carregar livros do arquivo
      ifstream fileIn(arquivo);
    if (fileIn.is_open()) {
        string linha;
        while (getline(fileIn, linha)) {
            stringstream ss(linha);
            string titulo, autor, ano, isbn;
            getline(ss, titulo, ',');
            getline(ss, autor, ',');
            getline(ss, ano, ',');
            getline(ss, isbn, ',');
            
            livro.setTitulo(titulo);
            livro.setAutor(autor);
            livro.setAnoDePublicacao(  stoi(ano));
            livro.setIsbn(  stoi(isbn));
            livros.push_back(livro);
        }
        fileIn.close();
    }

    while (true) {
          cout << "1. Adicionar livro\n"
                  << "2. Deletar livro\n"
                  << "3. Listar livros\n"
                  << "4. Atualizar livro\n"
                  << "5. Set Admin\n"
                  << "6. Remove Admin\n"
                  << "7. Deslogar\n"
                  << "Escolha: ";
        
        while (true) {
            getline(  cin, input);
            try {
                opcao =   stoi(input);
                break;
            } catch (const   invalid_argument& e) {
                  cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        switch (opcao) {
            case 1: {

                cout << "Insira as informacoes para adicionar um novo livro:\n";
                cout << "Titulo: ";
                getline(  cin, input);
                livro.setTitulo(input);

                cout << "Autor: ";
                getline(  cin, input);
                livro.setAutor(input);

                cout << "Ano de publicacao: ";
                getline(  cin, input);
                livro.setAnoDePublicacao(  stoi(input));

                cout << "ISBN: ";
                getline(  cin, input);
                livro.setIsbn(  stoi(input));

                livros.push_back(livro);

                // Salvar livro no arquivo
                ofstream fileOut(arquivo,   ios::app);
                fileOut << livro.getTitulo() << "," << livro.getAutor() << "," << livro.getAnoDePublicacao() << "," << livro.getIsbn() << "\n";
                fileOut.close();

                  cout << "Livro criado com sucesso!\n";
                break;
            }

            case 2: {
                cout << "Insira o ISBN do livro que deseja remover: ";
                getline(  cin, input);
                int isbn_pesquisa =   stoi(input);

                for (auto it = livros.begin(); it != livros.end(); ++it) {
                    if (it->getIsbn() == isbn_pesquisa) {
                        livros.erase(it);
                        break;
                    }
                }

                // Salvar alterações no arquivo
                ofstream fileOut(arquivo);
                for (const auto& livro : livros) {
                    fileOut << livro.getTitulo() << "," << livro.getAutor() << "," << livro.getAnoDePublicacao() << "," << livro.getIsbn() << "\n";
                }
                fileOut.close();
                cout << "Livro removido com sucesso!\n";
                break;
            }

            case 3: {
                cout << "\nLivros disponiveis na biblioteca:\n";
                for (const auto& livro : livros) {
                    cout << "Titulo: " << livro.getTitulo() << "\n";
                    cout << "Autor: " << livro.getAutor() << "\n";
                    cout << "Ano de publicacao: " << livro.getAnoDePublicacao() << "\n";
                    cout << "ISBN: " << livro.getIsbn() << "\n\n";
                }
                break;
            }

            case 4: {
                cout << "Atualizar livro\n";
                cout << "Insira o ISBN do livro que deseja atualizar: ";
                getline(  cin, input);
                int isbn_pesquisa =   stoi(input);

                for (auto& livro : livros) {
                    if (livro.getIsbn() == isbn_pesquisa) {
                        cout << "Insira as novas informacoes do livro:\n";
                        cout << "Titulo: ";
                        getline(  cin, input);
                        livro.setTitulo(input);

                        cout << "Autor: ";
                        getline(  cin, input);
                        livro.setAutor(input);

                        cout << "Ano de publicacao: ";
                        getline(  cin, input);
                        livro.setAnoDePublicacao(  stoi(input));

                        cout << "ISBN: ";
                        getline(  cin, input);
                        livro.setIsbn(  stoi(input));

                        break;
                    }
                }

                // Salvar alterações no arquivo
                ofstream fileOut(arquivo);
                for (const auto& livro : livros) {
                    fileOut << livro.getTitulo() << "," << livro.getAutor() << "," << livro.getAnoDePublicacao() << "," << livro.getIsbn() << "\n";
                }
                fileOut.close();
                cout << "Livro alterado com sucesso!\n";
                break;
            }

            case 5: {
                string usuario;
                cout << "Digite o username do usuario a ser setado como admin: ";
                getline(cin, usuario);
                set_admin(usuario);
                break;
            }

            case 6: {
                string usuario;
                cout << "Digite o username do admin a ter sua administracao removida: ";
                getline(cin, usuario);
                remove_admin(usuario);
                break;
            }

            case 7:
                cout << "Deslogando...\n";
                return;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}

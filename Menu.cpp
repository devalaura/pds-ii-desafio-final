#include <iostream>
#include "Livro.hpp"
#include <vector> //vetor alocado dinamicamente 

using namespace std;

void Menu(){
    int opcao;
    Livro livro;
    vector<Livro> livros; //cria um vetor para armazenar os livros
    string titulo;  
    string autor;
    int ano_de_publicacao;
    int isbn;
    int isbn_pesquisa;

    cout << "Sistema de Biblioteca" << endl;
    
    do {
        cout << endl << "Opcoes: " << endl;
        cout << "1 - Adicionar novo livro; " << endl;
        cout << "2 - Remover livro;" << endl;
        cout << "3 - Listar livros;" << endl;
        cout << "4 - Fechar menu" << endl;

        cout << "Selecione uma opcao: " << endl;
        cin >> opcao;

        if(opcao >= 1 && opcao <= 4){
            switch(opcao){
                case 1:
                    cout << "Insira as informacoes abaixo para adicionar um novo livro ao sistema: " << endl;
                    cout << "Titulo: " << endl;
                    cin.ignore();
                    getline(cin, titulo); //armazenar uma string
                    livro.setTitulo(titulo);

                    cout << "Autor: " << endl;
                    getline(cin, autor);
                    livro.setAutor(autor);

                    cout << "Ano de publicacao: " << endl;
                    cin >> ano_de_publicacao;
                    livro.setAnoDePublicacao(ano_de_publicacao);

                    cout << "ISBN " << endl;
                    cin >> isbn;
                    livro.setIsbn(isbn);

                    livros.push_back(livro);
                break;

                case 2: 
                    cout << "Insira o ISBN do livro que deseja remover do sistema: " << endl;
                    cin >> isbn_pesquisa;

                    for(int i = 0; i < livros.size(); i++){
                        if(livros[i].getIsbn() == isbn_pesquisa){ //compara se o isbn encontrado é o mesmo do que desejamos remover
                            livros.erase(livros.begin() + i); //deletar um livro pelo indice
                        }
                    }

                break;

                case 3:
                    cout << endl << "Livros disponiveis na biblioteca: " << endl;

                    for(int i = 0; i < livros.size(); i++){
                        cout << "Titulo: " << livros[i].getTitulo() << endl;
                        cout << "Autor: " << livros[i].getAutor() << endl;
                        cout << "Ano de publicacao: " << livros[i].getAnoDePublicacao() << endl;
                        cout << "ISBN: " << livros[i].getIsbn() << endl << endl;
                    }

                break;

                case 4:
                    cout << "Fechando Sistema da Biblioteca" << endl;
                break;
            }
        }
        else{
            cout << endl << "Opcao invalida! " << endl << endl;
        }

    } while(opcao != 4);
    
}
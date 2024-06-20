#include <gmock/gmock.h>
#include "Livro.hpp"

class MockLivro : public Livro {
public:
    MOCK_METHOD(string, getTitulo, (), (override));
    MOCK_METHOD(string, getAutor, (), (override));
    MOCK_METHOD(int, getAnoDePublicacao, (), (override));
    MOCK_METHOD(int, getIsbn, (), (override));

    MOCK_METHOD(void, setTitulo, (string titulo), (override));
    MOCK_METHOD(void, setAutor, (string autor), (override));
    MOCK_METHOD(void, setAnoDePublicacao, (int ano_de_publicacao), (override));
    MOCK_METHOD(void, setIsbn, (int isbn), (override));
};


TEST(LivroTest, GetTitulo) {
    MockLivro mockLivro;

    // Configura o comportamento do objeto mock
    EXPECT_CALL(mockLivro, getTitulo())
       .Times(1)
       .WillOnce(Return("Mock Titulo"));

    // Crie uma instância da classe que usa a classe Livro
    MyClass myClass(&mockLivro);

    // Chame a função que usa a classe Livro
    string titulo = myClass.getLivroTitulo();

    // Verifique se a função getTitulo foi chamada corretamente
    Mock::VerifyAndClearExpectations(&mockLivro);

    // Verifique se o título retornado é o esperado
    ASSERT_EQ(titulo, "Mock Titulo");
}
/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 06  : Lista Simples e Duplas (seções 3.2 e 3.2 AD; seções 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 106: Uso de classe e funções parametrizadas (template)
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 04 de outubro de 2022
 *   Data alteração: 04 de outubro de 2022
 *
 *--------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------------------------------------------------
// Classes Lista e "No da lista" com tipos parametricos
//---------------------------------------------------------
template <typename T>
class No
{
public:
    T dado;
    No * proximo;

    No(T d_in) { dado = d_in; proximo = nullptr; }
};

template <typename T>
class lista
{
public:
    No<T> * inicio;

    lista() { inicio = nullptr; }
    void Insere(T);
};

// Definindo uma função membro fora da Classe
template <typename T>
void lista<T>::Insere(T dado_ins)
{
    No<T> * aux = new No<T>(dado_ins);
    if (inicio)
       aux->proximo = inicio;
    inicio = aux;
}

//-------------------------------------
// Testes
//-------------------------------------
// Classe Pessoa
struct t_Pessoa
{
    int     ID_Pessoa;
    string  Nome_Pessoa;

    // construtor do objeto pessoa
    t_Pessoa(int p_ID = 0, string p_nome = "") { ID_Pessoa = p_ID; Nome_Pessoa = p_nome; }
};

int main()
{
    // Listasw polimorficas no tipo de dados que os Nós guardam
    lista<int>      lista_de_inteiros;
    lista<string>   lista_de_strings;
    lista<t_Pessoa> lista_de_pessoas;


    cout << "Hello world!" << endl;

    // Testanto a lista de INTEIROS
    // Inserindo os dados
    for( int i = 0 ; i < 10; i++ )
        lista_de_inteiros.Insere(i);
    // SELECT tipo SCAN da lista toda
    for( No<int> * aux = lista_de_inteiros.inicio; aux; aux = aux->proximo)
        cout << aux->dado << endl;

    // Testanto a lista de STRINGS
    string str = "";
    for( char i = '0' ; i <= '9'; i++ ) {
        str = (str + i);
        lista_de_strings.Insere(str);
    }
    for( No<string> * aux = lista_de_strings.inicio; aux; aux = aux->proximo)
        cout << aux->dado << endl;

    // Testanto a lista de PESSOAS
    t_Pessoa aux_p;
    for( char i = 0 ; i < 10; i++ ) {
        aux_p = t_Pessoa(i,(string("Ze das Coves") + string(i,'s'))); // criando um Pessoa com o construtor
        lista_de_pessoas.Insere(aux_p);
    }
    for( No<t_Pessoa> * aux = lista_de_pessoas.inicio; aux; aux = aux->proximo)
    {
        aux_p = aux->dado;
        cout << "ID  : " << aux_p.ID_Pessoa   << endl;
        cout << "Nome: " << aux_p.Nome_Pessoa << endl;
    }

    return 0;
}

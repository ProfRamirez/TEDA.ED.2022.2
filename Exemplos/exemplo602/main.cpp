/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 06  : Lista Simples e Duplas (seções 3.2 e 3.2 AD; seções 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 602: Lista Duplamente Encadeada
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 06 de outubro de 2022
 *   Data alteração: 06 de outubro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

class ListaD; // para poder declarar que a ListaD é FRIEND da classe NoD
//-----------------------------
// No com dois ponteiros.
// Um para o proximo Nó e
// outro para o Nó anterior
//-----------------------------
class NoD
{
    int dado;

    NoD * prox, *anterior;
public:
    NoD(int p_dado) : dado(p_dado) { prox = anterior = nullptr; }
    friend ListaD;
};
//------------------------------------
// Agora a classe Lista pode
// ter dois ponteiros, um
// para o Nó no INICIO da Lista
// e outro para o Nó no FIM da lista
//------------------------------------
class ListaD
{
    NoD *inicio, *fim;

public:
    ListaD() { inicio = fim = nullptr; }
    void InsereFim(int d);
    void Print(void);
    void PrintReverso(void); // podemos agora ter o percurso na ordem inversa
};

void ListaD::InsereFim(int d)
{
    NoD * aux = new NoD(d);

    if (inicio) {
        fim->prox = aux;
        aux->anterior = fim;
        fim = aux;
    } else {
        inicio = fim = aux;
    }
}

void ListaD::Print(void)
{
    for( NoD * aux = inicio; aux; aux = aux->prox)
        cout << aux->dado << endl;
}

void ListaD::PrintReverso(void)
{
    for( NoD * aux = fim; aux; aux = aux->anterior)
        cout << aux->dado << endl;
}

int main()
{
    cout << "Exemplo de Lista Dupla" << endl;

    ListaD listaDupla;
    for( int i = 0; i < 10; i++)
        listaDupla.InsereFim(i);
    listaDupla.Print();
    listaDupla.PrintReverso();

    return 0;
}

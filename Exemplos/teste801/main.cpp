/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 08  : Filas de Prioridade (seção 4.3 AD; 6.2 a 6.5 JL)
 *   Exemplo 801: Usando lista duplas ordendas para implementar lista de prioridades
 *
 *   Módulo Principal - Exempli simples e incompleto
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 20 de outubro de 2022
 *   Data alteração: 20 de outubro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

class ListaD;
class NoD // em como dado apenas a prioridade
{
     int prioridade;
     NoD * prox, *anterior;

public:
    NoD(int p_pri) : prioridade(p_pri) { prox = anterior = nullptr; }
    int GetPrioridade(void) { return prioridade; }
    friend ListaD;
};
class ListaD
{
    NoD *inicio, *fim;

public:
    ListaD() { inicio = fim = nullptr; }
    void InsereInicio(NoD *);
    void InsereFim(NoD *);
    NoD * DeletaFim(void); // função quando fizemos uma Pilha usando Lista Duplas
    void InsereOrdenado(NoD *);
    bool Lista_esta_vazia(void) { return inicio == nullptr; } // função quando fizemos uma Pilha usando Lista Duplas
    void Print(void);
    void PrintReverso(void);
};

void ListaD::InsereInicio(NoD * aux)
{
    if (inicio) { // testa se lista vazia
        inicio->anterior = aux;
        aux->prox = inicio;
        inicio = aux;
    } else {
        inicio = fim = aux;
    }
}
void ListaD::InsereFim(NoD * aux)
{
    if (fim) { // testa se lista vazia
        fim->prox = aux;
        aux->anterior = fim;
        fim = aux;
    } else {
        inicio = fim = aux;
    }
}

void ListaD::InsereOrdenado(NoD * aux)
{
    NoD * local;
    // verifica se lista vazia ou se a prioridade e menor que a do Inicio da lista
    if ((inicio == nullptr) || (aux->GetPrioridade() <= inicio->GetPrioridade()))
        InsereInicio(aux);
    else
        // verifica se a prioridade e maior ou igual ao do Fim da lista
        if ((aux->GetPrioridade() >= fim->GetPrioridade()))
            InsereFim(aux);
        else {
            local = inicio->prox;
            // procura a posição onde será inserido o novo dado
            while (aux->GetPrioridade() > local->GetPrioridade())
                local = local->prox;
            // insere no meio, antes do no apontado por LOCAL
            aux->prox = local;
            aux->anterior = local->anterior;
            local->anterior->prox = aux;
            local->anterior = aux;
        }
}

NoD * ListaD::DeletaFim(void)
{
    NoD * aux;

    if (fim) {
        aux = fim;
        if (inicio != fim)
        {
            fim->anterior->prox = nullptr;
            fim = fim->anterior;
        }
        else
            inicio = fim = nullptr;
        return aux;
    } else {
        return nullptr; // lista vazia
    }
}
void ListaD::Print(void)
{
    for( NoD * aux = inicio; aux; aux = aux->prox)
        cout << aux->GetPrioridade() << " | ";
    cout << endl;
}

void ListaD::PrintReverso(void)
{
    for( NoD * aux = fim; aux; aux = aux->anterior)
        cout << aux->GetPrioridade() << " | ";
    cout << endl;
}

void Teste(void)
{
    ListaD lst;
    NoD * aux;
    int dado;

    srand (time(NULL));
    for( int i = 0; i < 20; i++)
    {
        dado = rand() % 100; // sorteia de 0 a 99
        aux = new NoD(dado);
        lst.InsereOrdenado(aux);
    }
    lst.Print();

/* Código de exemplo que apresentou erro pois usamos o mesmo No para atualizar a lista
        aux = new NoD(3);
        lst.InsereOrdenado(aux);
        lst.Print();
        aux = new NoD(3);
        lst.InsereOrdenado(aux);
        lst.Print();
*/
}

int main()
{
    cout << "Criando lista de prioridade usando listas duplamente encadeada ordendadas" << endl;

    Teste();

    return 0;
}

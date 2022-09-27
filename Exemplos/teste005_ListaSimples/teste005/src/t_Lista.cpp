/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matem�tica
 * DMA  - Departamento de Matem�tica Aplicada
 *
 *   MAE015 - T�picos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 05  : Lista Simples e Duplas (se��es 3.2 e 3.2 AD; se��es 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 003: Lista simples com ponteiros
 *
 *   M�dulo: Defini��o da Classe LISTA
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 27 de setembro de 2022
 *   Data altera��o: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_Lista.h"

#include <iostream>
using namespace std;

t_Lista::t_Lista()
{
    //ctor
    topo = nullptr;
    fim = nullptr;
    length = 0; // lista inicia vazia
}

t_Lista::~t_Lista()
{
    //dtor
}

void t_Lista::Put(t_No *ptr_novo)
{
    if ( topo == nullptr )
        topo = ptr_novo;
    else
        fim->prox = ptr_novo;
    fim = ptr_novo;
}

void t_Lista::Put(t_Dado d)
{
    t_No *ptr_novo = new t_No(d);
    Put(ptr_novo);
}

void t_Lista::Print(void)
{
    t_No *aux;

    aux = topo;
    while( aux )
    {
        cout << (aux->Get()).Get() << endl;
        aux = aux->prox;
    }
}

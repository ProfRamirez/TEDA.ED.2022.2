/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 05  : Lista Simples e Duplas (seções 3.2 e 3.2 AD; seções 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 003: Lista simples com ponteiros
 *
 *   Módulo: Definição da Classe LISTA
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 27 de setembro de 2022
 *   Data alteração: 27 de setembro de 2022
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

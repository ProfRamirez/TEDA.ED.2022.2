/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 05  : Lista Simples e Duplas (seções 3.2 e 3.2 AD; seções 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 005: Lista simples com ponteiros
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 27 de setembro de 2022
 *   Data alteração: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>

#include "t_Dado.h"
#include "t_Lista.h"

using namespace std;

void RunTeste(void)
{
    t_Dado d;
    t_Lista lst1;

    for(int i= 0; i < 10; i++)
    {
        d.Put(i);
        lst1.Put(d);
    }
    lst1.Print();
}

int main()
{
    cout << "Teste005: 1a implementação da listas simples" << endl;

    RunTeste();
    return 0;
}

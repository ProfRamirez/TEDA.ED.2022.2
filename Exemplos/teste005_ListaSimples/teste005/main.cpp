/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matem�tica
 * DMA  - Departamento de Matem�tica Aplicada
 *
 *   MAE015 - T�picos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 05  : Lista Simples e Duplas (se��es 3.2 e 3.2 AD; se��es 2.1 a 2.3, 2.6, 2.7.2 e 2.7.4 JL)
 *   Exemplo 005: Lista simples com ponteiros
 *
 *   M�dulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 27 de setembro de 2022
 *   Data altera��o: 27 de setembro de 2022
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
    cout << "Teste005: 1a implementa��o da listas simples" << endl;

    RunTeste();
    return 0;
}

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
 *   Módulo Classe DADOS
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 27 de setembro de 2022
 *   Data alteração: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/

#ifndef T_DADO_H
#define T_DADO_H

#include <iostream>
using namespace std;

class t_Dado
{
    public:
        t_Dado();
        t_Dado(int ip) { i = ip;}
        virtual ~t_Dado();
        int Get(void) { return i; }
        void Put(int p_i) { i = p_i; }
        void Print(void) { cout << i << endl; }

    protected:

    private:
        int i; // CHAVE Primária
};

#endif // T_DADO_H

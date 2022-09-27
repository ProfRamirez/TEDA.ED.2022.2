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
 *   M�dulo: Classe LISTA
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 27 de setembro de 2022
 *   Data altera��o: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#ifndef T_LISTA_H
#define T_LISTA_H

#include "t_No.h"

class t_Lista
{
    public:
        t_Lista();
        virtual ~t_Lista();
        void Put(t_No *ptr_novo);
        void Put(t_Dado d);
        void Print(void);

    protected:

    private:
        t_No *topo;
        t_No *fim;
        unsigned int length;
};

#endif // T_LISTA_H

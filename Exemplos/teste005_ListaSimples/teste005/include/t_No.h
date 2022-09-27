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
 *   M�dulo: Classe NO da lista
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 27 de setembro de 2022
 *   Data altera��o: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#ifndef T_NO_H
#define T_NO_H

#include "t_Dado.h"

class t_No
{
    public:

        t_No(t_Dado);
        t_No() { prox = nullptr; }
        virtual ~t_No() { delete prox; }
        void Put(t_Dado d) { dado = d; }
        t_Dado Get(void) { return dado; }

    protected:

    private:
        t_Dado dado;

        t_No *prox; // campo de liga��o
        friend class t_Lista; // para a fun��o de LISTA acessarem o campo "prox"
};

#endif // T_NO_H

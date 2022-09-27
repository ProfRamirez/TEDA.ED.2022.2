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
 *   Módulo: Classe NO da lista
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 27 de setembro de 2022
 *   Data alteração: 27 de setembro de 2022
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

        t_No *prox; // campo de ligação
        friend class t_Lista; // para a função de LISTA acessarem o campo "prox"
};

#endif // T_NO_H

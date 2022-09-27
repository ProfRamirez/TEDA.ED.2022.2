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
 *   M�dulo: Defini��o da Classe NO da lista
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 27 de setembro de 2022
 *   Data altera��o: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_No.h"

t_No::t_No(t_Dado d)
{
   dado = d;
   prox = nullptr;
}

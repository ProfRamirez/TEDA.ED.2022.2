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
 *   Módulo: Definição da Classe NO da lista
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 27 de setembro de 2022
 *   Data alteração: 27 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_No.h"

t_No::t_No(t_Dado d)
{
   dado = d;
   prox = nullptr;
}

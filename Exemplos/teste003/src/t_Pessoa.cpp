/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 03  : Introdução a linguagem C/C++
 *   Exemplo 003: Herança, Hierarquia de Classes e a 1a solução para relacionamento 1-N
 *
 *   Módulo: definição da classe PESSOA (raiz da hierarquia de classes)
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 15 de setembro de 2022
 *   Data alteração: 15 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_Pessoa.h"
#include <iostream>
#include <string>

t_Pessoa::t_Pessoa()
{
    //ctor
}

t_Pessoa::~t_Pessoa()
{
    //dtor
}

void t_Pessoa::Print(void)
{
    cout << "+" << string(64,'-') << "+" << endl;
    cout << "| CPF  : " << CPF  << string((64 - 8 - 11),' ') << "|" << endl;
    cout << "| Nome : " << Nome << string((64 - 8 - Nome.size() ),' ') << "|" << endl;
    cout << "+" << string(64,'-') << "+" << endl;
}

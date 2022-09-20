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
 *   Módulo: DEfinição da Classe CURSO
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 15 de setembro de 2022
 *   Data alteração: 15 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_Curso.h"


#include <iostream>
#include <string>
using namespace std;

t_Curso::t_Curso()
{
    //ctor
}

t_Curso::~t_Curso()
{
    //dtor
}

void t_Curso::Print(void)
{
    cout << "+" << string(54,'-') << "+" << endl;
    cout << "| CURSO" << string((54 - 6),' ') << "|" << endl;
    cout << "+" << string(54,'-') << "+" << endl;
    cout << "| Codigo: " << Codigo << string((54 - 9 - 3),' ') << "|" << endl;
    cout << "| Nome  : " << Nome   << string((54 - 9 - Nome.size()),' ') << "|" << endl;
    cout << "+" << string(54,'-') << "+" << endl;
}

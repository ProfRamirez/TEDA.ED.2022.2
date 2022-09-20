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
 *   Módulo: definição da Classe PROFESSOR
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 15 de setembro de 2022
 *   Data alteração: 15 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include "t_Professor.h"

#include <iostream>
#include <string>
using namespace std;

t_Professor::t_Professor()
{
    //ctor
    // Inicialização dos atributos internos
    for (unsigned int i = 0; i < MAX_ORIENTADOS_POR_PROFESSOR; lst_Orientados[i++]=0);
    qnt_orientados = 0;
}

t_Professor::~t_Professor()
{
    //dtor
}

// Metodos da interface do Professor
void t_Professor::Cadastra(t_SIAPE pSIAPE, t_CPF pCPF, string pNome)
{
    t_Pessoa::Cadastra(pCPF, pNome); // cadastra os dados da "Pessoa Professor"
    SIAPE = pSIAPE;
}

void t_Professor::Print(void)
{
    cout << "+" << string(64,'-') << "+" << endl;
    cout << "| PROFESSOR" << string((64 - 10 ),' ') << "|" << endl;
    t_Pessoa::Print();
    cout << "| SIAPE: " << SIAPE  << string((64 - 8 - 10),' ') << "|" << endl;
    cout << "+" << string(64,'-') << "+" << endl;

}

void t_Professor::InsereOrientando(unsigned int Id_Aluno_no_array)
{
  unsigned int pos_vazia;

  if (qnt_orientados < MAX_ORIENTADOS_POR_PROFESSOR)
  {
    pos_vazia = Busca_pos_vazia();
    lst_Orientados[pos_vazia] = Id_Aluno_no_array;
    qnt_orientados++;
  }
  else
    cout << "Professor ja possui o maximo de orientados" << endl;
}

void t_Professor::PrintListaDeOrientados(void)
{
  for (unsigned int i = 0; i < MAX_ORIENTADOS_POR_PROFESSOR; i++)
  {
      cout << i << " : " << lst_Orientados[i] << " : ";
//      if (lst_Orientados[i] != 0 ) Alunos[lst_Orientados[i]].Print();
  //      else cout << " nada " << endl;
  }
}

// Metodos internos do Professor
unsigned int t_Professor::Busca_pos_vazia(void)
{
    unsigned int i;
    for ( i = 0; lst_Orientados[i] != 0 ; i++);
    return i;
}

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
 *   Módulo: Classe CURSO
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 15 de setembro de 2022
 *   Data alteração: 15 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#ifndef T_CURSO_H
#define T_CURSO_H

#include <string>
using namespace std;

typedef unsigned long int t_COD;

class t_Curso
{
    public:
        t_Curso();
        virtual ~t_Curso();
        void Cadastra(t_COD pCodigo, string pNome)
        {
          Codigo = pCodigo; Nome = pNome;
        }
        void Print(void);
        void PrintListaAlunosDoCurso(void);

    protected:

    private:
       t_COD   Codigo;
       string  Nome;
       unsigned int Alunos[1000];

};

#endif // T_CURSO_H

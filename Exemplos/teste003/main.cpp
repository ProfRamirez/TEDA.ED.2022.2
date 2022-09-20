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
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 15 de setembro de 2022
 *   Data alteração: 15 de setembro de 2022
 *
 *--------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "t_Pessoa.h"
#include "t_Aluno.h"
#include "t_Professor.h"
#include "t_Curso.h"

using namespace std;

// Area de variaveis globais
const unsigned int MAX_QNT_CURSOS = 10;
const unsigned int MAX_QNT_PROFS  = 100;
const unsigned int MAX_QNT_ALUNOS = 1000;

t_Curso           Curso[MAX_QNT_CURSOS]; // base de Cursos
t_Professor Professores[MAX_QNT_PROFS ]; // base de Professores
t_Aluno          Alunos[MAX_QNT_ALUNOS]; // base de alunos

void Cria_BD(void)
{
    Curso[0].Cadastra(100,"Matematica Aplicada");
    Curso[1].Cadastra(200,"Eng Matematica");
    Curso[2].Cadastra(300,"Ciencia da Computacao");
    Curso[2].Cadastra(300,"Eng Computacao e Informacao");

    Professores[0].Cadastra(200100, 99900088801, "Sir Isaac Newton");
    Professores[1].Cadastra(200200, 99900088802, "Johann Carl Friedrich Gauss");
    Professores[2].Cadastra(200300, 99900088803, "Albert Eistein");
    Professores[3].Cadastra(200400, 99900088804, "Leonhard Euler");
    Professores[4].Cadastra(200500, 99900088805, "Alan Mathison Turing");
    Professores[5].Cadastra(200600, 99900088806, "John von Neumann");
    Professores[6].Cadastra(200700, 99900088807, "Dennis MacAlistair Ritchie");
    Professores[7].Cadastra(200800, 99900088808, "Guido van Rossum");

    srand(time(0));
    string nomes_rnd[] = {"Alice", "Mario", "Jose", "Joao", "Maria", "Mateus", "Lucas", "Marcos", "Elisa", "Teresa", "Ana", "Barbara"};
    string sobrenomes_rnd[] =  {"da Silva Madeira", "Alves de Souza", "Bento Golcalves", "Souza de Holanda", "Alberto Nunes", "Campos Ferro"};
    for (int i = 1; i < 20; i++) // a posição [0] é vazia pois indica aluno deletado ou ausente
    {
        Alunos[i].Cadastra(122000000 + i, 44400011100 + i, (nomes_rnd[rand() % 12] + string(" ") + sobrenomes_rnd[rand() % 6]));
    }
    Professores[0].InsereOrientando(1);
    Professores[0].InsereOrientando(5);
    Professores[0].InsereOrientando(8);
}

void Consulta_BD(void)
{
    for (int i = 1; i < 20; i++)
    {
        Alunos[i].Print();
    }
    Professores[0].PrintListaDeOrientados();
}

void Roda_Exemplo003(void)
{
    Cria_BD();
    Consulta_BD();
}

int main()
{
    cout << "+------------------------------------------------------------------------------------+" << endl;
    cout << "| Exemplo 003: Herança, Hierarquia de Classes e a 1a solução para relacionamento 1-N |" << endl;
    cout << "+------------------------------------------------------------------------------------+" << endl << endl;

    Roda_Exemplo003();

    return 0;
}

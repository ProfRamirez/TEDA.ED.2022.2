#include "t_Aluno.h"
#include <iostream>

t_Aluno::t_Aluno()
{
    //ctor
}

t_Aluno::~t_Aluno()
{
    //dtor
}

void t_Aluno::Cadastra(t_DRE pDRE, t_CPF pCPF, string pNome)
{
    t_Pessoa::Cadastra(pCPF, pNome); // cadastra os dados da "Pessoa Aluno"
    DRE = pDRE;
}

void t_Aluno::Print(void)
{
    cout << "+" << string(64,'-') << "+" << endl;
    cout << "| ALUNO" << string((64 - 6 ),' ') << "|" << endl;
    t_Pessoa::Print();
//    cout << "+" << string(64,'-') << "+" << endl;
    cout << "| DRE  : " << DRE  << string((64 - 8 - 9),' ') << "|" << endl;
    cout << "+" << string(64,'-') << "+" << endl;
}

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

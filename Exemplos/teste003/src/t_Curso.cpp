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

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

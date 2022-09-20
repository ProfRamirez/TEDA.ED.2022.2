#ifndef T_PROFESSOR_H
#define T_PROFESSOR_H

#include "t_Pessoa.h"
#include <string>

using namespace std;
typedef unsigned long long int t_SIAPE;

class t_Professor : public t_Pessoa
{
    public:
        t_Professor();
        virtual ~t_Professor();
        void Cadastra(t_SIAPE pSIAPE, t_CPF pCPF, string pNome);
        void Print(void);
        void InsereOrientando(unsigned int Id_Aluno_no_array);
        void PrintListaDeOrientados(void);


    protected:

    private:
        // Constantes internas
        static const unsigned int MAX_ORIENTADOS_POR_PROFESSOR = 10;
        // Atributos internos
        unsigned int  qnt_orientados;
        // Atributos dos objetos (membros dados)
        t_SIAPE SIAPE;
        unsigned int lst_Orientados[MAX_ORIENTADOS_POR_PROFESSOR];
        // Area de metodos internos
        unsigned int Busca_pos_vazia(void);
};

#endif // T_PROFESSOR_H

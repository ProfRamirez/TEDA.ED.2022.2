/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matem�tica
 * DMA  - Departamento de Matem�tica Aplicada
 *
 *   MAE015 - T�picos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 07  : Listas, Pilhas e Filas
 *   Exemplo 701: Aplica��es de Pilhas - Preechendo uma regi�o usando Pilha
 *
 *   M�dulo Principal - FEITO EM SALA DE AULA
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data cria��o  : 13 de outubro de 2022
 *   Data altera��o: 13 de outubro de 2022
 *
 *   OBSERVACOES:
 *   Esse arquivo cont�m v�rios exemplos desenvolvidos em sala
 *   de aula durante a semana 07 da disciplina. Eles falam de Pilhas
 *   H� duas implementa��es de Pilhas, uma usando Arrays e outra
 *   usando Lista Duplamente Encadeadas (que foi implementada
 *   nas aulas da semana passada). Essa implementa��o da Lista est�
 *   incompleta.
 *   A estrutura de dados Pilha � testada na solu��o do Preenchimento
 *   de uma regi�o definida em um arquivo de strings.
 *   A fun��o PreencheUsandoPilha()
 *   vai
 *--------------------------------------------------------------
*/
#include <fstream>
#include <iostream>

using namespace std;

// Estutura para ser usada no Preenchimento com Pilhas
struct t_Ponto { int x; int y; t_Ponto(int xx=0, int yy=0) : x(xx), y(yy) {} };;

/*-----------------------------------------
 * Lista duplamente encadeada "incompleta"
 *-----------------------------------------
 */
class ListaD;
class NoD
{
     t_Ponto dado;

    NoD * prox, *anterior;
public:
    NoD(t_Ponto p_dado) { dado = p_dado; prox = anterior = nullptr; }
    t_Ponto GetDado(void) { return dado; }
    friend ListaD;
};
class ListaD
{
    NoD *inicio, *fim;

public:
    ListaD() { inicio = fim = nullptr; }
    void InsereFim(NoD *);
    NoD * DeletaFim(void);
    void Print(void);
    void PrintReverso(void);
    // teste se lista est� vazia
    bool ListaEhVazia(void) { return inicio == nullptr;}
};

void ListaD::InsereFim(NoD * aux)
{
//    NoD * aux = new NoD(d);

    if (inicio) {
        fim->prox = aux;
        aux->anterior = fim;
        fim = aux;
    } else {
        inicio = fim = aux;
    }
}

NoD * ListaD::DeletaFim(void)
{
    NoD * aux;

    if (fim) {
        aux = fim;
        if (inicio != fim)
        {
            fim->anterior->prox = nullptr;
            fim = fim->anterior;
        }
        else
            inicio = fim = nullptr;
        return aux;
    } else {
        return nullptr; // lista vazia
    }
}

void ListaD::Print(void)
{
    for( NoD * aux = inicio; aux; aux = aux->prox)
        cout << aux->dado.x << " | ";
    cout << endl;
}

void ListaD::PrintReverso(void)
{
    for( NoD * aux = fim; aux; aux = aux->anterior)
        cout << aux->dado.x << " | ";
    cout << endl;
}

/*--------------------------------------
 * Exemplo de Pilha usando Lista Dupla
 *--------------------------------------
 */
ListaD pilhaL;

void PushL(t_Ponto dado)
{
    NoD * aux;

    try
    {
        aux = new NoD(dado);
    }
    catch (std::exception& e)
    {
        std::cerr << "Pilha cheia por falta de mem�ria! " << e.what() << '\n';
    }
    pilhaL.InsereFim(aux);
}

t_Ponto PopL(void)
{
    NoD * aux;

    aux = pilhaL.DeletaFim();
    if ( aux != nullptr )
        return aux->GetDado();
    else
        cout << "Pilha vazia" << endl; // underflow
}

void PrintPilhaL(void)
{
    pilhaL.Print();
}

bool PilhaVazia(void)
{
    return pilhaL.ListaEhVazia();
}

/*----------------------------------
 * Exemplo de Pilha com array
 *----------------------------------
 */

int pilha[100];
int pos_topo_pilha = 0;

void Push(int dado)
{
    if (pos_topo_pilha != 100)
        pilha[pos_topo_pilha++] = dado;
    else
        cout << "Pilha cheia" << endl; // overflow
}

int Pop(void)
{
    if (pos_topo_pilha != 0)
        return pilha[--pos_topo_pilha];
    else
        cout << "Pilha vazia" << endl; // underflow
}

void PrintPilha(void)
{
    cout << "Pilha: ";
    for ( int i = 0; i < pos_topo_pilha; i++)
        //cout << pilha[i] << " | ";
    cout << endl;
}

/*----------------------------------
 * Duas solu��es do Preenchimento de
 * regi�o dado um ponto interior
 *----------------------------------
 */
string linha[100];

void PreencheRecursivo(int lin, int col, char marca)
{
    char c;

    c = linha[lin][col];
    if ( c != '1' && c != marca )
    {
        linha[lin][col] = marca;
        c = linha[lin-1][col];
        if ( c != '1' && c != marca ) PreencheRecursivo(lin-1,col,marca);
        c = linha[lin+1][col];
        if ( c != '1' && c != marca ) PreencheRecursivo(lin+1,col,marca);
        c = linha[lin][col+1];
        if ( c != '1' && c != marca ) PreencheRecursivo(lin,col+1,marca);
        c = linha[lin][col-1];
        if ( c != '1' && c != marca ) PreencheRecursivo(lin,col-1,marca);
    }
}

// a proxima fun��o implementa a anterior, tirando a recursividade usando uma Pilha
void PreencheUsandoPilha(int lin, int col, char marca)
{
    char c;
    t_Ponto pnt;

    // coloca o primeiro ponto na Pilha (nao testa se � interior)
    c = linha[lin][col];
    if ( c != '1' && c != marca )
    {
        pnt.x = col; pnt.y = lin;
        cout << "[" << pnt.x << ", " << pnt.y << "]" << endl;
        PushL(pnt);
    }

    while ( !PilhaVazia() ) // enquanto a pilha n�o estiver vazia
    {
        pnt = PopL();
        lin = pnt.y; col = pnt.x;
        linha[lin][col] = marca;
        c = linha[lin-1][col];
        if ( c != '1' && c != marca ) { pnt.y = lin-1; pnt.x = col; PushL(pnt); }
        c = linha[lin+1][col];
        if ( c != '1' && c != marca ) { pnt.y = lin+1; pnt.x = col; PushL(pnt); }
        c = linha[lin][col+1];
        if ( c != '1' && c != marca ) { pnt.y = lin; pnt.x = col+1; PushL(pnt); }
        c = linha[lin][col-1];
        if ( c != '1' && c != marca ) { pnt.y = lin; pnt.x = col-1; PushL(pnt); }
    }
}

void Testa_Pilha(void)
{
    ifstream arq_com_regiao_a_ser_preenchida; // arquivo que contem a matriz de pontos
    int num_linhas_matriz_pontos;

    arq_com_regiao_a_ser_preenchida.open("matriz_pontos_regiao.txt");
    int i=0; // conta numero de linhas da matriz. Todas as linhas devem come�ar e terminar por um caracter '1'
    while ( !arq_com_regiao_a_ser_preenchida.eof() )
        getline(arq_com_regiao_a_ser_preenchida, linha[i++]);
    num_linhas_matriz_pontos = i;
    cout << "Numero de Linhas da Matriz de Pontos: " << num_linhas_matriz_pontos << endl;
    arq_com_regiao_a_ser_preenchida.close();

    for(int i = 0; i < num_linhas_matriz_pontos; i++ )
        cout << linha[i] << endl;
    PreencheUsandoPilha(3,2,'@'); // tem que ser passado as coordenadas de um ponto interior da figura.
    for(int i = 0; i < num_linhas_matriz_pontos; i++ )
        cout << linha[i] << endl;
    PreencheUsandoPilha(3,2,'-');
    for(int i = 0; i < num_linhas_matriz_pontos; i++ )
        cout << linha[i] << endl;

}
int main()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "| Exemplo 701: Usando Pilhas para preencher uma regi�o (Pilha implementada com listas |" << endl;
    cout << "+-------------------------------------------------------------------------------------+" << endl << endl;

    Testa_Pilha();

    return 0;
}

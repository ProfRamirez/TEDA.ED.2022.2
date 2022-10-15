#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception {
    const char * what () const throw() {
        return "deu ruim!";
    }
};

void f1(int i)
{
    int b;

    if (i < 10)
    {
        cout << i << " eh menor que 10" << endl;
    }
    else
       throw MyException();
}
int main()
{
    cout << "Hello world!" << endl;

    try
    {
        for (int i = 0; i < 20; i +=2 ) f1(i);
    }
    catch (const char * s)
    {
        cout << s << endl;
    }
    catch (exception & e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

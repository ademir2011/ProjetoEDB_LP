#include <iostream>
#include <cstdlib>

#define lin 13
#define col 13

using namespace std;

class Gera
{
    public:
    int op;
    void geraMatriz(int op);
};

void Gera::geraMatriz(int op)
{
    int matriz[lin][col];

    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            matriz[lin][col]=rand()%3;
        }
    }

}

int main()
{

    void textbackground (int green);

    int op;
    Gera gera;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout<<"--     Inicio [1]    --"<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-\n"<<endl;

    cin>>op;

    if(op==1)
    {
        gera.geraMatriz(op);
    }



    return 0;
}

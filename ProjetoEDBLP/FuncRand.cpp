#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <SDL.h>

#define lin 8
#define col 8

using namespace std;

void geraMatriz(int matriz[lin][col])
{
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            matriz[i][j]=rand()%5;
        }
    }
}

int verificaMatrizLinha(int matriz[lin][col])
{
    int cont=0;

    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col-2;j++)
        {
            if(matriz[i][j]==matriz[i][j+1] && matriz[i][j]==matriz[i][j+2])
            {
                cont+=1;
            }
        }
    }
    return cont;
}

int verificaMatrizColuna(int matriz[lin][col])
{
    int cont=0;

    for(int i=0;i<lin-2;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matriz[i][j]==matriz[i+1][j] && matriz[i][j]==matriz[i+2][j])
            {
                cont+=1;
            }
        }
    }
    return cont;
}

void exibeMatriz(int matriz[lin][col])
{
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
srand(time(NULL));

    int op;
    int matriz[lin][col];

    cout<<"-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout<<"--     Inicio [1]    --"<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-\n"<<endl;

    cin>>op;

    if(op==1)
    {
        do
        {
            geraMatriz(matriz);
            cout<<"...Loading..."<<"\n"<<endl;
            system("cls");
        }while(verificaMatrizLinha(matriz)!=0 || verificaMatrizColuna(matriz)!=0);

        exibeMatriz(matriz);
    }
    return 0;
}

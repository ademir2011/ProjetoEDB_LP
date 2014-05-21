#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <SDL/SDL.h>

#define lin 10
#define col 10

using namespace std;

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

void geraMatriz(int matriz[lin][col])
{
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
                do
                {
                    matriz[i][j]=rand()%3;
                }while((matriz[i][j]==matriz[i][j-1] && matriz[i][j]==matriz[i][j-2]) ||
                       (matriz[i][j]==matriz[i-1][j] && matriz[i][j]==matriz[i-2][j]));
        }
    }
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



int main(int argc, char* args[])
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
       geraMatriz(matriz);
       exibeMatriz(matriz);
       cout<<"\n\n-----\n"<<verificaMatrizLinha(matriz)<<"\n-----\n\n";
       cout<<"\n\n-----\n"<<verificaMatrizColuna(matriz)<<"\n-----\n\n";
    }

    return 0;
}

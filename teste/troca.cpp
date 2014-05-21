#include <iostream>
#include <cstdlib>
#include <ctime>

#define lin 10
#define col 10

using namespace std;

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
    cout<<"\n\n    ";
    for(int m=0;m<col;m++)
    {
        cout<<m<<" ";
    }

    cout<<"\n    ";
    for(int x=0;x<col;x++)
    {
        cout<<"| ";
    }

    cout<<endl;

    for(int i=0;i<lin;i++)
    {
        cout<<i<<" - ";
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void troca(int matriz[lin][col], int *x1, int *y1, int *x2, int *y2)
{
    int auxX, auxY, auxM;

        auxX = *x1;
        *x1  = *x2;
        *x2  = auxX;

        auxY = *y1;
        *y1  = *y2;
        *y2  = auxY;

        auxM=matriz[*x1][*y1];
        matriz[*x1][*y1]=matriz[*x2][*y2];
        matriz[*x2][*y2]=auxM;
}

int restricao(int *chave, int x1, int y1, int x2, int y2)
{
    if(((x1==x2-1 || x1==x2+1 || x1==x2)   &&
        (y1==y2-1 || y1==y2+1 || y1==y2))  &&
        (x1!=y1 || x2!=y2)
       )
    {
        *chave=1;
    }
    else
    {
        cout<<"Erro na chave !";
    }
}

int main()
{
    int ks = 1;
    int matriz[lin][col],chave;

    geraMatriz(matriz);
    srand(time(NULL));

    int x1, y1;
    int x2, y2;

    do{

    srand(time(NULL));
    exibeMatriz(matriz);

    cout<<"\n\nEscolha as posicoes para troca:\n";
    cout<<"x1:";
    cin>>x1;
    cout<<"y1:";
    cin>>y1;
    cout<<"x2:";
    cin>>x2;
    cout<<"y2:";
    cin>>y2;

    cout<<"\n\nx1:"<<x1<<" y1:"<<y1<<" x2:"<<x2<<" y2:"<<y2<<endl;

    restricao(&chave,x1,y1,x2,y2);
    if(chave==1)
    {
        troca(matriz, &x1, &y1, &x2, &y2);
    }

    cout<<"x1:"<<x1<<" y1:"<<y1<<" x2:"<<x2<<" y2:"<<y2;

    }while(ks==1);

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

#define lin 5
#define col 5

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

void trocaIDA(int matriz[lin][col], int x1, int y1, int x2, int y2)
{
    int auxM;

    auxM=matriz[x1][y1];
    matriz[x1][y1]=matriz[x2][y2];
    matriz[x2][y2]=auxM;
}

int compara(int matriz[lin][col], int *chave, int x1, int y1, int x2, int y2, int *x4, int *y4)
{
    if( (x1==x2 && (y1==y2-1 || y1==y2+1)  || (y1==y2 && (x1==x2-1 || x1==x2+1)))   &&
            (
               ((matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1-2])      ||
                (matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1+2])      ||
                (matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1+2][y1])      ||
                (matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1-2][y1])      ||
                (matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1-1][y1])      ||
                (matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1-1]))
                                                  ||
               ((matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2-2])      ||
                (matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2+2])      ||
                (matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2+2][y2])      ||
                (matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2-2][y2])      ||
                (matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2-1][y2])      ||
                (matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2-1]))
            )
        )
    {
        if(
               (matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1+2]) ||
               (matriz[x1][y1]==matriz[x1][y1-2] && matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1+1]) ||
               (matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1+2][y1]) ||
               (matriz[x1][y1]==matriz[x1-2][y1] && matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1+1][y1])
          )
        {
            *x4=x1;
            *y4=y1;
        }
        if(
                   (matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2+2]) ||
                   (matriz[x2][y2]==matriz[x2][y2-2] && matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2+1]) ||
                   (matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2+2][y2]) ||
                   (matriz[x2][y2]==matriz[x2-2][y2] && matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2+1][y2])
               )
        {
            *x4=x2;
            *y4=y2;
        }
        cout<<"Trocou !!!";
    }

    else
    {
        cout<<"Nao trocou !!!";
        *chave=1;
    }
}

void trocaVOLTA(int matriz[lin][col], int *chave, int x1, int y1, int x2, int y2)
{
    if(*chave==1)
    {
        int auxM;

        auxM=matriz[x1][y1];
        matriz[x1][y1]=matriz[x2][y2];
        matriz[x2][y2]=auxM;
    }
}

int main()
{
    int ks = 1;
    int matriz[lin][col]= { {2,2,1,5,6},
                            {3,2,1,3,1},
                            {1,4,5,1,7},
                            {3,5,1,2,9},
                            {4,2,9,3,5}};

    srand(time(NULL));
   // geraMatriz(matriz);

    int x1, y1, x2, y2, chave=0, x4=0, y4=0;

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

    trocaIDA(matriz, x1, y1, x2, y2);
    compara(matriz, &chave, x1, y1, x2, y2, &x4, &y4);
    trocaVOLTA(matriz, &chave, x1, y1, x2, y2);

    cout<<x4<<" "<<y4<<"\n";

    chave=0;

    }while(ks==1);

    return 0;
}

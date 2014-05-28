#include <iostream>
#include <cstdlib>
#include <ctime>

#define lin 5
#define col 5
using namespace std;

void superBonus(int matriz[lin][col], int elem)
{
     int i, j, aux;
     for(i = 0;i < lin;i++)
     {
             for(j = 0;j < col;j++)
             {
                   if(matriz[i][j] == elem)
                   {
                                  for(aux = i;aux >= 0;aux--)
                                  {
                                          if((aux - 1)>=0)
                                          {
                                                matriz[aux][j]= matriz[aux - 1][j];
                                          }
                                          else
                                          {
                                                matriz[aux][j]= rand()%5;
                                          }
                                  }
                   }
             }
     }
}

void exibeMatriz(int matriz[lin][col])
{
    /*cout<<"\n\n    ";
    for(int m=0;m<col;m++)
    {
        cout<<m<<"\t";
    }

    cout<<"\n    ";
    for(int x=0;x<col;x++)
    {
        cout<<"| ";
    }

    cout<<endl;*/

    for(int i=0;i<lin;i++)
    {
        //cout<<i<<" - ";
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
}


int main(){
   // cout<< "bem vindo\n";
    int matriz[lin][col];
  int i, j;
  for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
              matriz[i][j] = rand()%5;
        }
  }
    exibeMatriz(matriz);
    superBonus(matriz, 2);
    cout<< "\n\n\n\n\n";
    exibeMatriz(matriz);
    system ("pause");
    return 0;
}

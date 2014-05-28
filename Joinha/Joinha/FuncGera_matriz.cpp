#include <iostream>
#include <cstdlib>

#define lin 10
#define col 10

//A matriz gera elementos randomicos, sem repeticao de 3 ou mais em sequencia
//esta gerando ints entre 0 e (a - 1)


void FuncGera_matriz(int matriz[10][10]){
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

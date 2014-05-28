#include <iostream>

#define lin 10
#define col 10


void FuncExibe_matriz(int matriz[lin][col])
{

    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

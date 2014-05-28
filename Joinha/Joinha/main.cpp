#include <iostream>
#include "FuncGera_matriz.h"
#include "FuncExibe_matriz.h"
#include "Funcprocura.h"

#define lin 10
#define col 10


int main(){

int mat[lin][col] =     {{1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10},
                        {1,2,3,4,5,6,7,8,9,10}};
int qtd = 5;
//FuncGera_matriz(mat[lin][col]);
FuncExibe_matriz(mat);

return 0;

}


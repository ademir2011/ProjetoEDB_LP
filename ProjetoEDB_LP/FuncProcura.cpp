#include <iostream>
#include <cstdlib>
using namespace std;

#define lin 5
#define col 5

void FuncProcura(int matriz[lin][col]){
    int c1, c2, c3, c4, c5;                 //contadores para colunas
    int repetidos;                          //quantidade de repetidos
    int l = 0;                              //contador para linha

    // ---------- iniciar verificação de elementos repetidos

    for(l = 0; l < lin; l++){
        for(c1 = 0;c1 < col; c1++){;
                c2 = c1 + 1;
                c3 = c2 + 1;
                c4 = c3 + 1;
                c5 = c4 + 1;
                if(c1 < col && c2 < col && matriz[l][c1] == matriz[l][c2]){             //tem 2 repetidos?
                    if(c3 < col && matriz[l][c1] == matriz[l][c3]){                     //tem 3 repetidos?
                        if(c4 < col && matriz[l][c1] == matriz[l][c4]){                 //tem 4 repetidos?
                            if(c5 < col && matriz[l][c1] == matriz[l][c5]){             //tem 5 repetidos?
                            repetidos = 5;

                            break;
                            }
                        repetidos = 4;

                        break;
                        }
                    repetidos = 3;


                    break;
                    }
                /*repetidos = 2;
                cout << "funcao com " << repetidos << " elementos repetidos a partir de " << c1 << "\n";
                cout << "na linha " << l << "\n";
                break;*/
                }
        }
    }
}




void geraMatriz(int matriz[lin][col]){
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            //matriz[i][j]=rand()%5;
            matriz[i][j]= j;
        }
    }
}

void exibeMatriz(int matriz[lin][col]){
        for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){

//int mat[lin][col];
int c1, c2;
int x = 5, y = 5;
int mat[lin][col] ={{1,2,2,2,2},
                    {3,4,5,5,5},
                    {1,2,2,4,5},
                    {1,1,1,1,1},
                    {1,2,3,4,5}};
exibeMatriz(mat);
FuncProcura(mat);
return 0;
}



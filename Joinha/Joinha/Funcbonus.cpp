#include <iostream>

#define lin 10
#define col 10

//Essa função será chamada quando houver uma troca com o tipo bonus.
//Esse tipo retira da matriz uma área de 3x3 ao redor do elemento especial(bonus)
//na sua nova posição.
//A função troca os elementos por zero no momento
//



void bonus(int matriz[lin][col], int linha, int coluna)
{        //funções bonus para cada tipo de localização na matriz
    int i, j;

    // ------------ Caso esteja no miolo da matriz

    if(linha >= 1 && linha < lin - 1 && coluna >= 1 && coluna < col - 1){

        for(i = (linha - 1); (i <= linha + 1); i++){
            for(j = (coluna - 1); j <= (coluna + 1); j++){
                matriz[i][j] = 1;
            }
        }
    }

    // ------------ Caso esteja na linha 0

    else if(linha == 0){

    //caso esteja na linha 0 e em coluna do meio

        if (coluna > 0 && coluna < col - 1 ){
            for(i = linha; (i <= linha + 1); i++){
                for(j = (coluna - 1); j <= (coluna + 1); j++){
                    matriz[i][j] = 1;
                }
            }
        }

    //caso esteja na linha 0 e na coluna 0

        else if(coluna == 0){
            for(i = linha; (i <= linha + 1); i++){
                    for(j = coluna; j <= (coluna + 1); j++){
                        matriz[i][j] = 1;
                    }
                }
        }

    //caso esteja na linha 0 e na coluna N

        else if(coluna == col - 1){
            for(i = linha; (i <= linha + 1); i++){
                for(j = (coluna - 1); j <= coluna; j++){
                    matriz[i][j] = 1;
                }
            }
        }


    }

    // ------------ caso esteja na linha N

    else if (linha == lin - 1){

    //caso esteja na linha N e em coluna do meio

        if (coluna > 0 && coluna < col - 1){
            for(i = linha - 1; i <= linha; i++){
                for(j = (coluna - 1); j <= (coluna + 1); j++){
                    matriz[i][j] = 1;
                }
            }
        }

    //caso esteja na linha N e na coluna 0

        else if(coluna == 0){
            for(i = linha - 1; i <= linha; i++){
                for(j = coluna; j <= (coluna + 1); j++){
                    matriz[i][j] = 1;
                }
            }
        }

    //caso esteja na linha N e na coluna N

        else if(coluna == col - 1){
            for(i = (linha - 1); i <= linha; i++){
                for(j = (coluna - 1); j <= coluna; j++){
                    matriz[i][j] = 1;
                }
            }
        }
    }

    // ------------ Caso esteja em linha do meio

    else{

    // caso esteja na coluna 0

            if(coluna == 0){
                for(i = linha - 1; i <= linha + 1; i++){
                    for(j = coluna; j <= (coluna + 1); j++){
                        matriz[i][j] = 1;
                    }
                }
            }
    // caso esteja na coluna N

            else if(coluna == col - 1){
                for(i = linha - 1; i <= linha + 1; i++){
                    for(j = coluna - 1; j <= coluna; j++){
                        matriz[i][j] = 1;
                    }
                }
            }

    }
}

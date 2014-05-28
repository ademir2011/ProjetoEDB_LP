#include <iostream>

#define lin 10
#define col 10

//Essa função retorna um caso ache algum tipo de sequencia com repetições na matriz
//e também altera os valores referenciados pelo main para retornar um
//tamanho               - quantidades de itens repetidos na sequencia
//tipo                  - subtipo que determina qual estrutura será tratada
//coordenada linha      - a coordenada da linha do elemento base
//coordenada coluna     - a coordenada da coluna do elemento base


int FuncProcura(int matriz[lin][col], int *repetidos, int *tipo, int *coord_linha, int *coord_coluna){
    int c1, c2, c3, c4, c5;                 //contadores para colunas
    int l = 0;                              //contador para linha

    // ---------- iniciar verificação de elementos *repetidos

    for(l = 0; l < lin; l++){
        for(c1 = 0;c1 < col; c1++){;
            c2 = c1 + 1;
            c3 = c2 + 1;
            c4 = c3 + 1;
            c5 = c4 + 1;


                if(c1 < col && c2 < col && matriz[l][c1] == matriz[l][c2]){                                             //tem 2 *repetidos?
                    if(c3 < col && matriz[l][c1] == matriz[l][c3]){                                                     //tem 3 *repetidos?
                        if(c4 < col && matriz[l][c1] == matriz[l][c4]){                                                 //tem 4 *repetidos?
                            if(c5 < col && matriz[l][c1] == matriz[l][c5]){                                             //tem 5 *repetidos?

                                if(l >= 0 && l < lin - 2){                                                              //T7 de cabeça pra cima
                                    if(matriz[l][c3] == matriz[l + 1][c3] && matriz[l][c3] == matriz[l + 2][c3]){       //tamanho 7 *tipo 1
                /* 7.1 */              {*repetidos = 7;
                                        *tipo = 1;                                                                       //7 *repetidos em T
                                        *coord_linha = l;                                                                //linha do elemento base
                                        *coord_coluna = c3;                                                              //coluna do elemento base
                                        return 1;}                                                                         //será excluido com a implementacao do return
                                    }
                                }
                                else if(l > 1 && l < lin){
                                    if(matriz[l][c3] == matriz[l - 1][c3] && matriz[l][c3] == matriz[l - 2][c3]){       //tamanho 7 *tipo 2
                /* 7.2 */              {*repetidos = 7;
                                        *tipo = 2;                                                                       //7 *repetidos em T(de cabeça para baixo)
                                        *coord_linha = l;
                                        *coord_coluna = c3;                                                            //linha do elemento base
                                        return 1;}                                                                         //será excluido com a implementacao do return
                                    }
                                }
                /* 5.1 */      {*repetidos = 5;
                                *tipo = 1;                                                                               //5 *repetidos em linha
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;                                                                      //coluna do elemento base
                                return 1;}                                                                                  //será excluido com a implementacao do return
                            }
                /* 4.1 */  {*repetidos = 4;
                            *tipo = 1;                                                                                   //4 *repetidos em linha
                            *coord_linha = l;                                                                            //linha do elemento base
                            *coord_coluna = c1;                                                                          //coluna do elemento base
                            return 1;}                                                                                     //será excluido com a implementacao do return
                        }
                        if(l > 1 && l < lin - 2){                                                              //T7(*tipos 3 e 4)
                            if(matriz[l][c1] == matriz[l - 1][c1] && matriz[l][c1] == matriz[l - 2][c1]
                               && matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l + 2][c1]){       //Tamanho 7 *tipo 3(deitado - perna para esquerda)
                /* 7.3 */      {*repetidos = 7;
                                *tipo = 3;
                                *coord_linha = l;                                                                //linha do elemento base
                                *coord_coluna = c1;                                                              //coluna do elemento base
                                return 1;}                                                                         //será excluido com a implementacao do return
                            }
                        }
                        if(matriz[l][c3] == matriz[l - 1][c3] && matriz[l][c3] == matriz[l - 2][c3]
                           && matriz[l][c3] == matriz[l + 1][c3] && matriz[l][c3] == matriz[l + 2][c3]){
                /* 7.4 */   {*repetidos = 7;
                            *tipo = 4;
                            *coord_linha = l;                                                                //linha do elemento base
                            *coord_coluna = c3;                                                              //coluna do elemento base
                            return 1;}                                                                          //será excluido com a implementacao do return
                        }
                        if(l > 1 && l < lin){                                                                           //L de cabeça pra cima
                            if(matriz[l][c1] == matriz[l - 1][c1] && matriz[l][c1] == matriz[l - 2][c1]){               //tamanho 5 *tipo 3
                /* 5.3 */      {*repetidos = 5;
                                *tipo = 3;                                                                               //5 *repetidos em L
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(matriz[l][c3] == matriz[l - 1][c3] && matriz[l][c3] == matriz[l - 2][c3]){               //tamanho 5 *tipo 4
                /* 5.4 */       {*repetidos = 5;
                                *tipo = 4;                                                                               //5 *repetidos em L(invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;
                                                                                        //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(matriz[l][c2] == matriz[l - 1][c2] && matriz[l][c2] == matriz[l - 2][c2]){               //tamanho 5 *tipo 4
                /* 5.8 */       {*repetidos = 5;
                                *tipo = 8;                                                                               //5 *repetidos em L(invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c2;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                        }
                        if(l < lin - 2 && l >= 0){                                                                 //L de cabeça pra baixo
                            if(matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l + 2][c1]){               //tamanho 5 *tipo 5
                /* 5.5 */      {*repetidos = 5;
                                *tipo = 5;                                                                               //5 *repetidos em L(de cabeça para baixo)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                       //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(matriz[l][c3] == matriz[l + 1][c3] && matriz[l][c3] == matriz[l + 2][c3]){               //tamanho 5 *tipo 6
                /* 5.6 */      {*repetidos = 5;
                                *tipo = 6;                                                                               //5 *repetidos em L(de cabeça para baixo e invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(matriz[l][c2] == matriz[l + 1][c2] && matriz[l][c2] == matriz[l + 2][c2]){               //tamanho 5 *tipo 7
                /* 5.7 */      {*repetidos = 5;
                                *tipo = 7;                                                                               //5 *repetidos em T
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                        }
                        if(l > 0 && l < lin - 1){                                                                           //T5 (*tipo 9)
                            if(matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l - 1][c1]){               //tamanho 5 *tipo 9
                /* 5.9 */       {*repetidos = 5;
                                *tipo = 9;                                                                               //5 *repetidos em T
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                      //coluna do elemento base
                                return 1;}                                                                                  //será excluido com a implementacao do return
                            }
                            else if(matriz[l][c3] == matriz[l - 1][c3] && matriz[l][c3] == matriz[l + 1][c3]){
                /* 5.10 */          {*repetidos = 5;
                                    *tipo = 10;                                                                               //5 *repetidos em T(cabeça para baixo)
                                    *coord_linha = l;                                                                        //linha do elemento base
                                    *coord_coluna = c3;                                                                      //coluna do elemento base
                                    return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                        }
                /* 3.1 */          {*repetidos = 3;
                                    *tipo = 1;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                             //coluna do elemento base
                                    return 1;}                                                                                         //será excluido com a implementacao do return
                    }
                }
        if(l < lin - 4 && matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l + 2][c1]
        && matriz[l][c1] == matriz[l + 3][c1] && matriz[l][c1] == matriz[l + 4][c1]){

                     /* 5.2 */      *repetidos = 5;
                                    *tipo = 2;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l + 2;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                          //coluna do elemento base
                                    return 1;
        }

        else if(l < lin - 3 && matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l + 2][c1]
        && matriz[l][c1] == matriz[l + 3][c1]){


                    /* 4.2 */       *repetidos = 4;
                                    *tipo = 2;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l + 3;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                          //coluna do elemento base
                                    return 1;
        }

        else if(l < lin - 3 && matriz[l][c1] == matriz[l + 1][c1] && matriz[l][c1] == matriz[l + 2][c1]
        && matriz[l][c1] == matriz[l + 3][c1]){

                    /* 3.2 */       *repetidos = 3;
                                    *tipo = 2;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l + 2;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                          //coluna do elemento base
                                    return 1;
        }
    }
}
return 0;
}

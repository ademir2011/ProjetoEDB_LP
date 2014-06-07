#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"

using namespace std;


Matriz::Matriz(){

    Func_Geramatriz();
}

void inline Matriz::FuncBonus(int linha, int coluna){        //funções bonus para cada tipo de localização na m

    int i, j;

    // ------------ Caso esteja no miolo da m

    if(linha >= 1 && linha < lin - 1 && coluna >= 1 && coluna < col - 1){

        for(i = (linha - 1); (i <= linha + 1); i++){
            for(j = (coluna - 1); j <= (coluna + 1); j++){
                m[i][j] = 1;
            }
        }
    }

    // ------------ Caso esteja na linha 0

    else if(linha == 0){

    //caso esteja na linha 0 e em coluna do meio

        if (coluna > 0 && coluna < col - 1 ){
            for(i = linha; (i <= linha + 1); i++){
                for(j = (coluna - 1); j <= (coluna + 1); j++){
                    m[i][j] = 1;
                }
            }
        }

    //caso esteja na linha 0 e na coluna 0

        else if(coluna == 0){
            for(i = linha; (i <= linha + 1); i++){
                    for(j = coluna; j <= (coluna + 1); j++){
                        m[i][j] = 1;
                    }
                }
        }

    //caso esteja na linha 0 e na coluna N

        else if(coluna == col - 1){
            for(i = linha; (i <= linha + 1); i++){
                for(j = (coluna - 1); j <= coluna; j++){
                    m[i][j] = 1;
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
                    m[i][j] = 1;
                }
            }
        }

    //caso esteja na linha N e na coluna 0

        else if(coluna == 0){
            for(i = linha - 1; i <= linha; i++){
                for(j = coluna; j <= (coluna + 1); j++){
                    m[i][j] = 1;
                }
            }
        }

    //caso esteja na linha N e na coluna N

        else if(coluna == col - 1){
            for(i = (linha - 1); i <= linha; i++){
                for(j = (coluna - 1); j <= coluna; j++){
                    m[i][j] = 1;
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
                        m[i][j] = 1;
                    }
                }
            }
    // caso esteja na coluna N

            else if(coluna == col - 1){
                for(i = linha - 1; i <= linha + 1; i++){
                    for(j = coluna - 1; j <= coluna; j++){
                        m[i][j] = 1;
                    }
                }
            }

    }
}

void Matriz::FuncExibe_matriz(){

for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            std::cout << m[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int Matriz::Func_Procura(int *repetidos, int *tipo, int *coord_linha, int *coord_coluna){
    int c1, c2, c3, c4, c5;                 //contadores para colunas
    int l = 0;                              //contador para linha

    // ---------- iniciar verificação de elementos *repetidos

    for(l = 0; l < lin; l++){
        for(c1 = 0;c1 < col; c1++){;
            c2 = c1 + 1;
            c3 = c2 + 1;
            c4 = c3 + 1;
            c5 = c4 + 1;


                if(c1 < col && c2 < col && m[l][c1] == m[l][c2]){                                             //tem 2 *repetidos?
                    if(c3 < col && m[l][c1] == m[l][c3]){                                                     //tem 3 *repetidos?
                        if(c4 < col && m[l][c1] == m[l][c4]){                                                 //tem 4 *repetidos?
                            if(c5 < col && m[l][c1] == m[l][c5]){                                             //tem 5 *repetidos?

                                if(l >= 0 && l < lin - 2){                                                              //T7 de cabeça pra cima
                                    if(m[l][c3] == m[l + 1][c3] && m[l][c3] == m[l + 2][c3]){       //tamanho 7 *tipo 1
                /* 7.1 */              {*repetidos = 7;
                                        *tipo = 1;                                                                       //7 *repetidos em T
                                        *coord_linha = l;                                                                //linha do elemento base
                                        *coord_coluna = c3;                                                              //coluna do elemento base
                                        return 1;}                                                                         //será excluido com a implementacao do return
                                    }
                                }
                                else if(l > 1 && l < lin){
                                    if(m[l][c3] == m[l - 1][c3] && m[l][c3] == m[l - 2][c3]){       //tamanho 7 *tipo 2
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
                            if(m[l][c1] == m[l - 1][c1] && m[l][c1] == m[l - 2][c1]
                               && m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l + 2][c1]){       //Tamanho 7 *tipo 3(deitado - perna para esquerda)
                /* 7.3 */      {*repetidos = 7;
                                *tipo = 3;
                                *coord_linha = l;                                                                //linha do elemento base
                                *coord_coluna = c1;                                                              //coluna do elemento base
                                return 1;}                                                                         //será excluido com a implementacao do return
                            }
                        }
                        if(m[l][c3] == m[l - 1][c3] && m[l][c3] == m[l - 2][c3]
                           && m[l][c3] == m[l + 1][c3] && m[l][c3] == m[l + 2][c3]){
                /* 7.4 */   {*repetidos = 7;
                            *tipo = 4;
                            *coord_linha = l;                                                                //linha do elemento base
                            *coord_coluna = c3;                                                              //coluna do elemento base
                            return 1;}                                                                          //será excluido com a implementacao do return
                        }
                        if(l > 1 && l < lin){                                                                           //L de cabeça pra cima
                            if(m[l][c1] == m[l - 1][c1] && m[l][c1] == m[l - 2][c1]){               //tamanho 5 *tipo 3
                /* 5.3 */      {*repetidos = 5;
                                *tipo = 3;                                                                               //5 *repetidos em L
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(m[l][c3] == m[l - 1][c3] && m[l][c3] == m[l - 2][c3]){               //tamanho 5 *tipo 4
                /* 5.4 */       {*repetidos = 5;
                                *tipo = 4;                                                                               //5 *repetidos em L(invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;
                                                                                        //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(m[l][c2] == m[l - 1][c2] && m[l][c2] == m[l - 2][c2]){               //tamanho 5 *tipo 4
                /* 5.8 */       {*repetidos = 5;
                                *tipo = 8;                                                                               //5 *repetidos em L(invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c2;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                        }
                        if(l < lin - 2 && l >= 0){                                                                 //L de cabeça pra baixo
                            if(m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l + 2][c1]){               //tamanho 5 *tipo 5
                /* 5.5 */      {*repetidos = 5;
                                *tipo = 5;                                                                               //5 *repetidos em L(de cabeça para baixo)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                       //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(m[l][c3] == m[l + 1][c3] && m[l][c3] == m[l + 2][c3]){               //tamanho 5 *tipo 6
                /* 5.6 */      {*repetidos = 5;
                                *tipo = 6;                                                                               //5 *repetidos em L(de cabeça para baixo e invertido horizontalmente)
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                            if(m[l][c2] == m[l + 1][c2] && m[l][c2] == m[l + 2][c2]){               //tamanho 5 *tipo 7
                /* 5.7 */      {*repetidos = 5;
                                *tipo = 7;                                                                               //5 *repetidos em T
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c3;                                                                      //coluna do elemento base
                                return 1;}                                                                                 //será excluido com a implementacao do return
                            }
                        }
                        if(l > 0 && l < lin - 1){                                                                           //T5 (*tipo 9)
                            if(m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l - 1][c1]){               //tamanho 5 *tipo 9
                /* 5.9 */       {*repetidos = 5;
                                *tipo = 9;                                                                               //5 *repetidos em T
                                *coord_linha = l;                                                                        //linha do elemento base
                                *coord_coluna = c1;                                                                      //coluna do elemento base
                                return 1;}                                                                                  //será excluido com a implementacao do return
                            }
                            else if(m[l][c3] == m[l - 1][c3] && m[l][c3] == m[l + 1][c3]){
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
        if(l < lin - 4 && m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l + 2][c1]
        && m[l][c1] == m[l + 3][c1] && m[l][c1] == m[l + 4][c1]){

                     /* 5.2 */      *repetidos = 5;
                                    *tipo = 2;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l + 2;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                          //coluna do elemento base
                                    return 1;
        }

        else if(l < lin - 3 && m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l + 2][c1]
        && m[l][c1] == m[l + 3][c1]){


                    /* 4.2 */       *repetidos = 4;
                                    *tipo = 2;                                                                                       //3 *repetidos em linha
                                    *coord_linha = l + 3;                                                                                //linha do elemento base
                                    *coord_coluna = c1;                                                                          //coluna do elemento base
                                    return 1;
        }

        else if(l < lin - 2 && m[l][c1] == m[l + 1][c1] && m[l][c1] == m[l + 2][c1]){
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

void Matriz::Func_Geramatriz(){
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
                do
                {
                    m[i][j]=rand()% 3;
                }while((m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2]) ||
                       (m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j]));
        }
    }
}

void Matriz::Func_Compara(int l1, int c1, int l2, int c2, int *esp_4_l, int *esp_4_c){
    if( (l1==l2 && (c1==c2-1 || c1==c2+1)  || (c1==c2 && (l1==l2-1 || l1==l2+1)))   &&
            (
               ((m[l1][c1]==m[l1][c1-1] && m[l1][c1]==m[l1][c1-2])      ||
                (m[l1][c1]==m[l1][c1+1] && m[l1][c1]==m[l1][c1+2])      ||
                (m[l1][c1]==m[l1+1][c1] && m[l1][c1]==m[l1+2][c1])      ||
                (m[l1][c1]==m[l1-1][c1] && m[l1][c1]==m[l1-2][c1])      ||
                (m[l1][c1]==m[l1+1][c1] && m[l1][c1]==m[l1-1][c1])      ||
                (m[l1][c1]==m[l1][c1+1] && m[l1][c1]==m[l1][c1-1]))
                                                  ||
               ((m[l2][c2]==m[l2][c2-1] && m[l2][c2]==m[l2][c2-2])      ||
                (m[l2][c2]==m[l2][c2+1] && m[l2][c2]==m[l2][c2+2])      ||
                (m[l2][c2]==m[l2+1][c2] && m[l2][c2]==m[l2+2][c2])      ||
                (m[l2][c2]==m[l2-1][c2] && m[l2][c2]==m[l2-2][c2])      ||
                (m[l2][c2]==m[l2+1][c2] && m[l2][c2]==m[l2-1][c2])      ||
                (m[l2][c2]==m[l2][c2+1] && m[l2][c2]==m[l2][c2-1]))
            )
        )
    {
        if(
               (m[l1][c1]==m[l1][c1-1] && m[l1][c1]==m[l1][c1+1] && m[l1][c1]==m[l1][c1+2]) ||
               (m[l1][c1]==m[l1][c1-2] && m[l1][c1]==m[l1][c1-1] && m[l1][c1]==m[l1][c1+1]) ||
               (m[l1][c1]==m[l1-1][c1] && m[l1][c1]==m[l1+1][c1] && m[l1][c1]==m[l1+2][c1]) ||
               (m[l1][c1]==m[l1-2][c1] && m[l1][c1]==m[l1-1][c1] && m[l1][c1]==m[l1+1][c1])
          )
        {
            *esp_4_l=l1;
            *esp_4_c=c1;
        }
        if(
                   (m[l2][c2]==m[l2][c2-1] && m[l2][c2]==m[l2][c2+1] && m[l2][c2]==m[l2][c2+2]) ||
                   (m[l2][c2]==m[l2][c2-2] && m[l2][c2]==m[l2][c2-1] && m[l2][c2]==m[l2][c2+1]) ||
                   (m[l2][c2]==m[l2-1][c2] && m[l2][c2]==m[l2+1][c2] && m[l2][c2]==m[l2+2][c2]) ||
                   (m[l2][c2]==m[l2-2][c2] && m[l2][c2]==m[l2-1][c2] && m[l2][c2]==m[l2+1][c2])
               )
        {
            *esp_4_l=l2;
            *esp_4_c=c2;
        }
        std::cout<<"Trocou !!!\n\n-------------------\n\n";
    }

    else
    {
        std::cout<<"Nao trocou !!!\n\n-------------------\n\n";
        Func_Troca(l1, c1, l2, c2);
    }
}

void Matriz::Func_Troca(int l1, int c1, int l2, int c2){
    int aux;

    aux=m[l1][c1];
    m[l1][c1]=m[l2][c2];
    m[l2][c2]=aux;
}

void Matriz::Func_Desloca(int repetidos, int tipo, int l, int c){
    switch(repetidos)
    {
            case 3:
                //linha sem bônus
                pontos = 100;
                if(tipo == 1)
                {
                    for(int j = c;j <= (c + 2); j++)
                    {
                        std::cout << "entrou aqui\n";
                            for(int i = l;i >= 0;i--)
                            {
                                  if((i - 1)>= 0)
                                  {
                                        m[i][j]= m[i - 1][j];
                                  }
                                  else
                                  {
                                        m[i][j]= rand()%3;//rand()%3;
                                  }
                            }
                    }
                }
                //coluna sem bônus
                else
                {
                        for(int i = l,j = c;i >= 0;i--)
                        {
                              if((i - repetidos)>=0)
                              {
                                    m[i][j]= m[i - repetidos][j];
                              }
                              else
                              {
                                    m[i][j]= rand()%3;
                              }
                        }
                 }break;

            case 4:
                  //linha com bônus
                  pontos  = 150;
                  if(tipo == 1)
                  {
                       for(int j = c;j <= (c + (repetidos)); j++)
                        {
                                for(int i = l;i >= 0;i--)
                                {
                                      if((i - 1)>= 0)
                                      {
                                            m[i][j]= m[i - 1][j];
                                      }
                                      else
                                      {
                                            m[i][j]= rand()%3;
                                      }
                                }
                        }
                  }
                  else
                  {
                        //coluna com bônus
                        for(int i = l,j = c;i >= 0;i--)
                        {
                              if((i - repetidos)>=0)
                              {
                                    m[i][j]= m[i - repetidos][j];
                              }
                              else
                              {
                                    m[i][j]= rand()%3;
                              }
                        }
                  }break;

            case 5:
                pontos = 200;
                 m[l][c] = 100;
                 switch(tipo)
                 {
                         case 1:
                              //linha esquerda
                              for(int j = (c - 1);j >= (c - 2); j--)
                              {
                                        for(int i = l;i >= 0;i--)
                                        {
                                                if((i - 1)>= 0)
                                                {
                                                      m[i][j]== m[i - 1][j];
                                                }
                                                else
                                                {
                                                      m[i][j]== rand()%3;
                                                }
                                        }
                              }
                                 //linha direta
                              for(int j = (c + 1);j <= (c + 2); j++)
                              {
                                      for(int i = l;i >= 0;i--)
                                      {
                                              if((i - 1)>= 0)
                                              {
                                                    m[i][j]== m[i - 1][j];
                                              }
                                              else
                                              {
                                                    m[i][j]== rand()%3;
                                              }
                                      }
                              }break;

                         case 2:
                              for(int i = (l + 2),j = c;i >= 0;i--)
                              {
                                         if((i - 2)>=0)
                                         {
                                               m[i][j]= m[i - 2][j];
                                         }
                                         else
                                         {
                                               m[i][j]= rand()%3;
                                         }
                              }
                              for(int i = (l + 1),j = c;i >= 0;i--)
                              {
                                         if((i - 2)>=0)
                                         {
                                               m[i][j]= m[i - 2][j];
                                         }
                                         else
                                         {
                                               m[i][j]= rand()%3;
                                         }
                              }break;

                         /*case 3:
                             //coluna
                             for(int i = (l - 1),j = c;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         m[i][j]= m[i - 2][j];
                                   }
                                   else
                                   {
                                         m[i][j]= rand()%3;
                                   }
                             }
                             //linha direita
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 4:
                              //coluna
                             for(int i = (l - 1),j = c;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         m[i][j]= m[i - 2][j];
                                   }
                                   else
                                   {
                                         m[i][j]= rand()%3;
                                   }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 5:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         m[i][j]= m[i - 2][j];
                                   }
                                   else
                                   {
                                         m[i][j]= rand()%3;
                                   }
                             }
                             //linha direita
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 6:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         m[i][j]= m[i - 2][j];
                                   }
                                   else
                                   {
                                         m[i][j]= rand()%3;
                                   }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 7:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 1); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (c + 1);j <= (c + 1); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 8:
                              //coluna
                             for(int i = (l - 1),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 1); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (c + 1);j <= (c + 1); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 9:
                              //coluna
                             for(int i = (l + 1),j = c;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           m[i][j]= m[i - 1][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             for(int i = l,j = c;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           m[i][j]= m[i - 1][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha direita
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 10:
                             for(int i = (l + 1),j = c;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           m[i][j]= m[i - 1][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             for(int i = l,j = c;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           m[i][j]= m[i - 1][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                 }break;

            case 7:
                 m[l][c] = 100;
                 switch(tipo)
                 {
                         case 1:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 2:
                              //coluna
                             for(int i = (l - 1),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 3:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             for(int i = (l + 1),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha direita
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;

                         case 4:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             for(int i = (l + 1),j = c;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           m[i][j]= m[i - 2][j];
                                     }
                                     else
                                     {
                                           m[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   m[i][j]== m[i - 1][j];
                                             }
                                             else
                                             {
                                                   m[i][j]== rand()%3;
                                             }
                                     }
                             }break;*/

                 }break;

    }

}
void Matriz::Func_Print_Pontos(){
    cout<<"Sua pontuacao é:"<<pontos<<"\n";
}

#include <iostream>
#include <cstdlib>
#include <ctime>


#define lin 5
#define col 5

using namespace std;

void deslocaMatrizColuna(int matriz[lin][col], int tamanho, int tipo, int x, int y)
{
    switch(tamanho)
    {       
            case 3:
                //linha sem bônus
                if(tipo == 1)
                {
                    for(int j = y;j >= (y + 2); j++)
                    {
                            for(int i = x;i >= 0;i--)
                            {
                                  if((i - 1)>= 0)
                                  {
                                        matriz[i][j]= matriz[i - 1][j];
                                  }
                                  else
                                  {
                                        matriz[i][j]= rand()%3;
                                  }
                            }
                    }
                }
                //coluna sem bônus
                else
                {
                        for(int i = x,j = y;i >= 0;i--)
                        {
                              if((i - tamanho)>=0)
                              {
                                    matriz[i][j]= matriz[i - tamanho][j];
                              }
                              else
                              {
                                    matriz[i][j]= rand()%3;
                              }
                        }
                 }break;
                 
            case 4:
                  //linha com bônus
                  matriz[x][y] = 100;
                  if(tipo == 1)
                  { 
                       for(int j = (y + 1);j <= (y + (tamanho - 1)); j++)
                        {
                                for(int i = x;i >= 0;i--)
                                {
                                      if((i - 1)>= 0)
                                      {
                                            matriz[i][j]= matriz[i - 1][j];
                                      }
                                      else
                                      {
                                            matriz[i][j]= rand()%3;
                                      }
                                }
                        }
                  }
                  else
                  {
                        //coluna com bônus
                        for(int i = (x - 1),j = y;i >= 0;i--)
                        {
                              if((i - (tamanho - 1))>=0)
                              {
                                    matriz[i][j]= matriz[i - (tamanho - 1)][j];
                              }
                              else
                              {
                                    matriz[i][j]= rand()%3;
                              }
                        }
                  }break;
                  
            case 5:
                 matriz[x][y] = 100;
                 switch(tipo)
                 {
                         case 1:
                              //linha esquerda
                              for(int j = (y - 1);j >= (y - 2); j--)
                              {
                                        for(int i = x;i >= 0;i--)
                                        {
                                                if((i - 1)>= 0)
                                                {
                                                      matriz[i][j]== matriz[i - 1][j];
                                                }
                                                else
                                                {
                                                      matriz[i][j]== rand()%3;
                                                }
                                        }
                              }
                                 //linha direta
                              for(int j = (y + 1);j <= (y + 2); j++)
                              {
                                      for(int i = x;i >= 0;i--)
                                      {
                                              if((i - 1)>= 0)
                                              {
                                                    matriz[i][j]== matriz[i - 1][j];
                                              }
                                              else
                                              {
                                                    matriz[i][j]== rand()%3;
                                              }
                                      }
                              }break;
                              
                         case 2:
                              for(int i = (x + 2),j = y;i >= 0;i--)
                              {
                                         if((i - 2)>=0)
                                         {
                                               matriz[i][j]= matriz[i - 2][j];
                                         }
                                         else
                                         {
                                               matriz[i][j]= rand()%3;
                                         }
                              }
                              for(int i = (x + 1),j = y;i >= 0;i--)
                              {
                                         if((i - 2)>=0)
                                         {
                                               matriz[i][j]= matriz[i - 2][j];
                                         }
                                         else
                                         {
                                               matriz[i][j]= rand()%3;
                                         }
                              }break;
                              
                         case 3:
                             //coluna
                             for(int i = (x - 1),j = y;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         matriz[i][j]= matriz[i - 2][j];
                                   }
                                   else
                                   {
                                         matriz[i][j]= rand()%3;
                                   }
                             }
                             //linha direita
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 4: 
                              //coluna
                             for(int i = (x - 1),j = y;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         matriz[i][j]= matriz[i - 2][j];
                                   }
                                   else
                                   {
                                         matriz[i][j]= rand()%3;
                                   }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 5:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         matriz[i][j]= matriz[i - 2][j];
                                   }
                                   else
                                   {
                                         matriz[i][j]= rand()%3;
                                   }
                             }
                             //linha direita
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 6:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                   if((i - 2)>=0)
                                   {
                                         matriz[i][j]= matriz[i - 2][j];
                                   }
                                   else
                                   {
                                         matriz[i][j]= rand()%3;
                                   }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 7:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 1); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (y + 1);j <= (y + 1); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 8:
                              //coluna
                             for(int i = (x - 1),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 1); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (y + 1);j <= (y + 1); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 9:
                              //coluna
                             for(int i = (x + 1),j = y;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 1][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             for(int i = x,j = y;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 1][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha direita
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 10:
                             for(int i = (x + 1),j = y;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 1][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             for(int i = x,j = y;i >= 0;i--)
                             {
                                     if((i - 1)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 1][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;                             
                 }break;
                                  
            case 7:
                 matriz[x][y] = 100;
                 switch(tipo)
                 {
                         case 1:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 2:
                              //coluna
                             for(int i = (x - 1),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }
                             //linha direta
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 3:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             for(int i = (x + 1),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha direita
                             for(int j = (y + 1);j <= (y + 2); j++)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                             
                         case 4:
                              //coluna
                             for(int i = (x + 2),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             for(int i = (x + 1),j = y;i >= 0;i--)
                             {
                                     if((i - 2)>=0)
                                     {
                                           matriz[i][j]= matriz[i - 2][j];
                                     }
                                     else
                                     {
                                           matriz[i][j]= rand()%3;
                                     }
                             }
                             //linha esquerda
                             for(int j = (y - 1);j >= (y - 2); j--)
                             {
                                     for(int i = x;i >= 0;i--)
                                     {
                                             if((i - 1)>= 0)
                                             {
                                                   matriz[i][j]== matriz[i - 1][j];
                                             }
                                             else
                                             {
                                                   matriz[i][j]== rand()%3;
                                             }
                                     }
                             }break;
                              
                 }break;                                              
                 
    }
        
}

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
              matriz[i][j] = j;
        }
  }
    exibeMatriz(matriz);
    
    system ("pause");
    return 0;
}

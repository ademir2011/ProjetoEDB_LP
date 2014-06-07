void Func_Desloca(int matriz[lin][col], int repetidos, int tipo, int l, int c){
    switch(repetidos)
    {
            case 3:
                //linha sematriz bônus
                if(tipo == 1)
                {
                    for(int j = c;j <= (c + 2); j++)
                    {
                        std::cout << "entrou aqui\n";
                            for(int i = l;i >= 0;i--)
                            {
                                  if((i - 1)>= 0)
                                  {
                                        matriz[i][j]= matriz[i - 1][j];
                                  }
                                  else
                                  {
                                        matriz[i][j]= rand()%3;//rand()%3;
                                  }
                            }
                    }
                }
                //coluna sematriz bônus
                else
                {
                        for(int i = l,j = c;i >= 0;i--)
                        {
                              if((i - repetidos)>=0)
                              {
                                    matriz[i][j]= matriz[i - repetidos][j];
                              }
                              else
                              {
                                    matriz[i][j]= rand()%3;
                              }
                        }
                 }break;

            case 4:
                  //linha comatriz bônus
                  matriz[l][c] = 100;
                  if(tipo == 1)
                  {
                       for(int j = (c + 1);j <= (c + (repetidos - 1)); j++)
                        {
                                for(int i = l;i >= 0;i--)
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
                        //coluna comatriz bônus
                        for(int i = (l - 1),j = c;i >= 0;i--)
                        {
                              if((i - (repetidos - 1))>=0)
                              {
                                    matriz[i][j]= matriz[i - (repetidos - 1)][j];
                              }
                              else
                              {
                                    matriz[i][j]= rand()%3;
                              }
                        }
                  }break;

            case 5:
                 matriz[l][c] = 100;
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
                                                      matriz[i][j]== matriz[i - 1][j];
                                                }
                                                else
                                                {
                                                      matriz[i][j]== rand()%3;
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
                                                    matriz[i][j]== matriz[i - 1][j];
                                              }
                                              else
                                              {
                                                    matriz[i][j]== rand()%3;
                                              }
                                      }
                              }break;

                         case 2:
                              for(int i = (l + 2),j = c;i >= 0;i--)
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
                              for(int i = (l + 1),j = c;i >= 0;i--)
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

                         /*case 3:
                             //coluna
                             for(int i = (l - 1),j = c;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l - 1),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 1); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 1); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l - 1),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 1); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 1); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 1),j = c;i >= 0;i--)
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
                             for(int i = l,j = c;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 1),j = c;i >= 0;i--)
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
                             for(int i = l,j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                 matriz[l][c] = 100;
                 switch(tipo)
                 {
                         case 1:
                              //coluna
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l - 1),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int i = (l + 1),j = c;i >= 0;i--)
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
                             for(int j = (c + 1);j <= (c + 2); j++)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             for(int i = (l + 2),j = c;i >= 0;i--)
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
                             for(int i = (l + 1),j = c;i >= 0;i--)
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
                             for(int j = (c - 1);j >= (c - 2); j--)
                             {
                                     for(int i = l;i >= 0;i--)
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
                             }break;*/

                 }break;

    }

}

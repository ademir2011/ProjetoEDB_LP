void compara(int matriz[lin][col], int *chave, int x1, int y1, int x2, int y2, int *x4, int *y4)
{
    if( (x1==x2 && (y1==y2-1 || y1==y2+1)  || (y1==y2 && (x1==x2-1 || x1==x2+1)))           &&
        (matriz[x1][y1]!=matriz[x2][y2])                                                    &&
            (
               ((matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1-2])      ||
                (matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1+2])      ||
                (matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1+2][y1])      ||
                (matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1-2][y1])      ||
                (matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1-1][y1])      ||
                (matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1-1]))
                                                  ||
               ((matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2-2])      ||
                (matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2+2])      ||
                (matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2+2][y2])      ||
                (matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2-2][y2])      ||
                (matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2-1][y2])      ||
                (matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2-1]))
            )
        )
    {
        if(
               (matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1+1] && matriz[x1][y1]==matriz[x1][y1+2]) ||
               (matriz[x1][y1]==matriz[x1][y1-2] && matriz[x1][y1]==matriz[x1][y1-1] && matriz[x1][y1]==matriz[x1][y1+1]) ||
               (matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1+1][y1] && matriz[x1][y1]==matriz[x1+2][y1]) ||
               (matriz[x1][y1]==matriz[x1-2][y1] && matriz[x1][y1]==matriz[x1-1][y1] && matriz[x1][y1]==matriz[x1+1][y1])
          )
        {
            *x4=x1;
            *y4=y1;
        }
        if(
                   (matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2+1] && matriz[x2][y2]==matriz[x2][y2+2]) ||
                   (matriz[x2][y2]==matriz[x2][y2-2] && matriz[x2][y2]==matriz[x2][y2-1] && matriz[x2][y2]==matriz[x2][y2+1]) ||
                   (matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2+1][y2] && matriz[x2][y2]==matriz[x2+2][y2]) ||
                   (matriz[x2][y2]==matriz[x2-2][y2] && matriz[x2][y2]==matriz[x2-1][y2] && matriz[x2][y2]==matriz[x2+1][y2])
               )
        {
            *x4=x2;
            *y4=y2;
        }
        cout<<"Trocou !!!";
    }

    else
    {
        cout<<"Nao trocou !!!";
        trocaIDA(matriz, x1, y1, x2, y2);
    }
}

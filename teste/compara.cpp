
int compara(int matriz[lin][col], int *chave, int x1, int y1, int x2, int y2)
{
    if( (x1==x2 && (y1==y2-1 || y1==y2+1)  || (y1==y2 && (x1==x2-1 || x1==x2+1)))   &&
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
        cout<<"Trocou !!!";
    }

    else
    {
        cout<<"Nao trocou !!!";
        *chave=1;
    }
}

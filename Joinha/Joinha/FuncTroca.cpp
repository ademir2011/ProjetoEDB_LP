
void trocaIDA(int matriz[lin][col], int x1, int y1, int x2, int y2)
{
    int auxM;

    auxM=matriz[x1][y1];
    matriz[x1][y1]=matriz[x2][y2];
    matriz[x2][y2]=auxM;
}

#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#define lin 10
#define col 10

class Matriz
{
private:
      int joia;
      int matriz[lin][col];

public:
       void FuncBonus(int matriz[lin][col], int linha, int coluna){}
       void FuncExibe_matriz(int matriz[lin][col]){}
       int Func_Procura(int matriz[lin][col], int *repetidos, int *tipo, int *coord_linha, int *coord_coluna){}
       void Func_Geramatriz(int matriz[lin][col]){}
       void Func_Troca(int matriz[lin][col], int l1, int c1, int l2, int c2){}
       void Func_Desloca(int matriz[lin][col], int repetidos, int tipo, int l, int c){}

};
#endif _MATRIZ_H_

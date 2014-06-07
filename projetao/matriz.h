#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#define lin 10
#define col 10

class Matriz
{
private:
      int pontos;
      int joia;
      int m[lin][col];

public:
       Matriz();
       void FuncBonus(int linha, int coluna);
       void FuncExibe_matriz();
       int  Func_Procura(int *repetidos, int *tipo, int *coord_linha, int *coord_coluna);
       void Func_Geramatriz();
       void Func_Troca(int l1, int c1, int l2, int c2);
       void Func_Desloca(int repetidos, int tipo, int l, int c);
       void Func_Compara(int l1, int c1, int l2, int c2, int *esp_4_l, int *esp_4_c);
};
#endif _MATRIZ_H_

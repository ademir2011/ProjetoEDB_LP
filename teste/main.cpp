#include <iostream>
#include <cstdlib>
#include <ctime>

#define lin 10
#define col 10



int main(){
Matriz m;
int i, j, cont;
int l_4, c_4;
int repetidos, tipo, l_base, c_base;

Matriz.Func_Geramatriz(matriz);
FuncExibe_matriz(matriz);

int l1, c1, l2, c2;

for(cont = 0; cont < 300; cont++){
std::cout << "digite as coordenadas de linha e coluna para troca\n";
std::cin >> l1 >> c1 >> l2 >> c2;

Func_Troca(matriz,l1,c1,l2,c2);
Func_Compara(matriz,l1,c1,l2,c2,&l_4,&c_4);
FuncExibe_matriz(matriz);
Func_Procura(matriz, &repetidos, &tipo, &l_base,&c_base);

std::cout << "\n\nElementos repetidos: " << repetidos << "\n";
std::cout << "tipo: " << tipo << "\n";
std::cout << "Coordenada l base: " << l_base << "\n";
std::cout << "Coordenada c base: " << c_base << "\n\n";

Func_Desloca(matriz,repetidos, tipo, l_base, c_base);

FuncExibe_matriz(matriz);
}

return 0;
}

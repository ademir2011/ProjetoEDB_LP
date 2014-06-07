#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"
#include "Jogo.h"

#define tam 10

using namespace std;

Jogo::Jogo(){
    for(int i=0;i <tam;i++){
        vet_r[i]=0;
    }
    menu();
}

void Jogo::menu(){
    int opcao;
    cout<<"        ""MENU\n\n1. Jogar\n2. Recordes\n";
    cin>> opcao;
    switch(opcao){
        case 1:{
            int i, j, cont;
            int l_4, c_4;
            int repetidos, tipo, l_base, c_base;

            Matriz matriz;

            matriz.FuncExibe_matriz();
            int l1, c1, l2, c2;

            for(cont = 0; cont < 300; cont++){
                cout << "digite as coordenadas de linha e coluna para troca ou degite 10 para sair.\n";
                cin >> l1;
                if (l1 == 10){
                    Jogo();
                }
                cin >> l1 >> l2 >> c2;
                if (l1 == 10){
                    Jogo();
                }
                else{

                matriz.Func_Troca(l1,c1,l2,c2);
                matriz.Func_Compara(l1,c1,l2,c2,&l_4,&c_4);
                matriz.FuncExibe_matriz();
                matriz.Func_Procura(&repetidos, &tipo, &l_base,&c_base);

                std::cout << "\n\nElementos repetidos: " << repetidos << "\n";
                std::cout << "tipo: " << tipo << "\n";
                std::cout << "Coordenada l base: " << l_base << "\n";
                std::cout << "Coordenada c base: " << c_base << "\n\n";

                matriz.Func_Desloca(repetidos, tipo, l_base, c_base);

                matriz.FuncExibe_matriz();
                }
            }
        }break;
        case 2:
            recordes();

    }
}

void Jogo::recordes(){
    int op;
    for(int i=0;i < tam;i++){
        cout<<vet_r[i]<<"\n";
    }

    cout<< "Digite 10 para sair.\n ";
    cin >> op;
    if (op == 10){
        Jogo();
    }
}

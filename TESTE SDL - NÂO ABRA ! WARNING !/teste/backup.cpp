
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

#define lin 7
#define col 7

using namespace std;

  SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Event Event;
    SDL_Surface *TelaInicial = NULL;
    SDL_Surface *TelaSec = NULL;
    SDL_Surface *JoiaAzul = NULL;
    SDL_Surface *JoiaBranca = NULL;
    SDL_Surface *JoiaVerde = NULL;
    SDL_Surface *JoiaLaranja = NULL;
//    SDL_Surface ***matriz;

void geraMatriz(int matriz[lin][col])
{
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
                do
                {
                    matriz[i][j]=rand()%4;
                }while((matriz[i][j]==matriz[i][j-1] && matriz[i][j]==matriz[i][j-2]) ||
                       (matriz[i][j]==matriz[i-1][j] && matriz[i][j]==matriz[i-2][j]));
        }
    }
}


int main(int argc, char *argv[]){
            srand(time(NULL));
    //Colocação da tabela
int coluna_atual = 1, linha_atual = 1, moveLin = 70, moveCol = 70, matriz[lin][col];


    geraMatriz(matriz);



    //Inicia e Verifica se o vídeo é criado
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        std::cout << "Erro ao iniciar video! Codigo de erro: " << SDL_GetError() << std::endl;
    }
    else
    {   //Inicia a janela
        window = SDL_CreateWindow("Joinha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        //SDL_WINDOW_RESIZABLE redimenciona a janela, (maximiza, aumenta, diminui a tela...)

        //Verifica se da erro ao criar janela
        if(window == NULL)
            std::cout << "Erro ao criar janela! Codigo de erro: " << SDL_GetError() << std::endl;
        else
        {
            //Passa a janela para dentro da surface
            surface = SDL_GetWindowSurface(window);



//            matriz[0][1] = IMG_Load("Azul1.png");
//            matriz[0][2] = IMG_Load("Branco.png");
//            matriz[0][3] = IMG_Load("Verde.png");
//            matriz[0][4] = IMG_Load("Laranja.png");


            //Carrega a imagem em imd
            TelaInicial = SDL_LoadBMP("Plano2.bmp");

            //Carregando jóia 1
            JoiaAzul = IMG_Load("Azul1.png");

            //Carregando jóia 2
            JoiaBranca = IMG_Load("Branco.png");

            //Carregando jóia 1
            JoiaVerde = IMG_Load("Verde.png");

            //Carregando jóia 2
            JoiaLaranja = IMG_Load("Laranja.png");

            //Verifica se a imagem foi encontrada
            if(TelaInicial==NULL || JoiaAzul==NULL || JoiaBranca==NULL)
            {
                std::cout<<"Alguma imagem não foi carregada corretamente, código do erro: " << SDL_GetError()<<std::endl;
            }
        }
    }

    bool close = false;
    //Enquanto a janela estiver executando faz..
    while(!close){

        //Enquanto não acontece nenhum evento (clique do mouse, teclado etc...) faz..
        while(SDL_PollEvent(&Event) != 0){

            //geras as joias aleátorias na linha 177


            if(Event.type == SDL_QUIT)
                close = true;
            if(Event.key.keysym.sym)
            {
                //Reconhece que um evento do teclado
                switch(Event.key.keysym.sym)
                {
//                caso w seja apertado
                case SDLK_w:
                    break;

                default:
                    break;
                }


            //Quando uma tecla é apertada o cursor do mouse vai para a posição 200, 200 da janela
//            if(Event.key.keysym.scancode == SDL_SCANCODE_F1)
//            {
//                SDL_WarpMouseInWindow(window, 200,200);
//            }

              //Esconde o cursor caso seja apertado a tecla F2
//            if(Event.key.keysym.scancode == SDL_SCANCODE_F2)
//            {
//                SDL_ShowCursor(0);
//            }

            }
            switch(Event.type)
            {
                case SDL_MOUSEBUTTONUP: //é clicado

                    switch(Event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            std::cout << "Botao esquerdo apertado" << std::endl;
                            SDL_MOUSEMOTION; //é movido
     	            std::cout   << "Has movido el ratón al punto ("
                                << Event.motion.x
                                << ","
                                << Event.motion.y
                                << ")."
                                << std::endl;
     	            	    break;

                        case SDL_BUTTON_MIDDLE:
     		                std::cout << "Has pulsado el botón del medio." << std::endl;
     		                break;

                        case SDL_BUTTON_RIGHT:
     		                std::cout << "Botao direito apertado" << std::endl;
     		                SDL_MOUSEMOTION; //é movido
     	            std::cout   << "Has movido el ratón al punto ("
                                << Event.motion.x
                                << ","
                                << Event.motion.y
                                << ")."
                                << std::endl;

     		                break;

                        case SDL_BUTTON_X1:
     		                std::cout << "Has pulsado X1." << std::endl;
     		                break;

                        case SDL_BUTTON_X2:
     		                std::cout << "Has pulsado X2." << std::endl;
     		                break;

                        default:
     		                std::cout << "Se ha pulsado el botón " << Event.button.button << std::endl;
     	 	                break;
     	            }

            }
        }


        // funcao principal do jogo

//Código para recortar e ajustar a imagem
//SDL_Rect src_rect = { 500, 500, 100, 200 };
//SDL_Rect dest_rect = { 75, 25, 0, 0 }; // remember, those last two zeroes are ignored
//SDL_BlitSurface(my_image, &src_rect, screen, &dest_rect);

        //SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,R,G,B));

//Um blit é uma cópia de parte da imagem de uma superfície para outra
// src é a superfície de origem
// dst é a superfície de destino
// srcrect é a área de origem
// dstrect é a área de destino
// Se srcrect ou dstrect forem NULL, significa toda a área da superfície
//SDL_BlitSurface(src, srcrect, dst, dstrect);


        //Exibe a imagem na tela
        SDL_BlitSurface(TelaInicial, NULL, surface, NULL);

//        SDL_Rect dest_rectJoiaAzul = { 227, 121, 0, 0 };
//        SDL_BlitSurface(JoiaAzul, NULL, surface, &dest_rectJoiaAzul);
//
//        SDL_Rect dest_rectJoiaBranca = { 327, 121, 0, 0 };
//        SDL_BlitSurface(JoiaBranca, NULL, surface, &dest_rectJoiaBranca);


                /*  desenhar a Matriz */
                SDL_Rect destino;
                int linha, coluna, espSup = 100, espEsq = 300,r, recebe[7][7];

                    for (linha = 0; linha < 7; linha++)
                    {
                        destino.y =espSup + (linha * moveLin);
                        for (coluna = 0; coluna < 7; coluna++)
                        {
                        destino.x = espEsq + (coluna * moveCol);
                            if(matriz[linha][coluna]==0)
                            {
                                SDL_BlitSurface(JoiaAzul, NULL, surface, &destino);
                            }
                            else if(matriz[linha][coluna]==1)
                            {
                                SDL_BlitSurface(JoiaBranca, NULL, surface, &destino);
                            }
                            else if(matriz[linha][coluna]==2)
                            {
                                SDL_BlitSurface(JoiaVerde, NULL, surface, &destino);
                            }
                            else if(matriz[linha][coluna]==3)
                            {
                                SDL_BlitSurface(JoiaLaranja, NULL, surface, &destino);
                            }

                        }
                    }
        //Atualiza a janela
        SDL_UpdateWindowSurface(window);


        // fim da funcao principal do jogo

    }

    //Libera a memória, onde a janela está alocada
    SDL_DestroyWindow(window);
    //Fecha o SDL
    SDL_Quit();
    return 0;
}

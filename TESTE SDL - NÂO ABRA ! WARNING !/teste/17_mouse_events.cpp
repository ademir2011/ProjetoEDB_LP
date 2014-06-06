#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

#define lin 7
#define col 7
#define moveLin 70
#define moveCol 70

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
    SDL_Surface *matrizTeste = NULL;

void carregaImagens()
{
            //Passa a janela para dentro da surface
            surface = SDL_GetWindowSurface(window);

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


void carregaVideo()
{
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
            carregaImagens();
        }
    }
}

void geraMatriz(int matriz[lin][col])
{
        /* desenhar a Matriz */
        SDL_Rect destino;
        int linha, coluna, espSup = 100, espEsq = 300,r, recebe[7][7];

        for (linha = 0; linha < 7; linha++)
        {
            destino.y =espSup + (linha * moveLin);
                for (coluna = 0; coluna < 7; coluna++)
                {
                    destino.x = espEsq + (coluna * moveCol);
                    SDL_BlitSurface(JoiaAzul, NULL, surface, &destino);
                }
        }
}

int main(int argc, char *argv[]){
    srand(time(NULL));

    //Colocação da tabela
    int matriz[lin][col];

    carregaVideo();

    bool close = false;
    //Enquanto a janela estiver executando faz..
    while(!close){

        //Enquanto não acontece nenhum evento (clique do mouse, teclado etc...) faz..
        while(SDL_PollEvent(&Event) != 0){

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

            }
            switch(Event.type)
            {
                case SDL_MOUSEBUTTONUP: //é clicado

                    switch(Event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            //Função Troca

                            //Função Troca
                            std::cout << "Botao esquerdo apertado" << std::endl;
                            SDL_MOUSEMOTION; //é movido
     	            std::cout   << "Has movido el ratón al punto ("
                                << Event.motion.x
                                << ","
                                << Event.motion.y
                                << ")."
                                << std::endl;
     	            	    break;

                        default:

     	 	                break;
     	            }

            }
        }

        //Inicio da funcao principal do jogo

        //Exibe a imagem na tela
        SDL_BlitSurface(TelaInicial, NULL, surface, NULL);

            geraMatriz(matriz);

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

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

#define lin 7
#define col 7
#define moveLin 66
#define moveCol 65

int matriz[lin][col];

using std::cout;
using std::cin;
using std::endl;

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
            TelaInicial = SDL_LoadBMP("imagens/planops.bmp");

            //Carregando jóia 1
            JoiaAzul = IMG_Load("imagens/Azul1.png");

            //Carregando jóia 2
            JoiaBranca = IMG_Load("imagens/Branco.png");

            //Carregando jóia 1
            JoiaVerde = IMG_Load("imagens/Verde.png");

            //Carregando jóia 2
            JoiaLaranja = IMG_Load("imagens/Laranja.png");

            //Verifica se a imagem foi encontrada
            if(TelaInicial==NULL || JoiaAzul==NULL || JoiaBranca==NULL)
            {
                cout<<"Alguma imagem não foi carregada corretamente, código do erro: " << SDL_GetError();
            }
}


void carregaVideo()
{
    //Inicia e Verifica se o vídeo é criado
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        cout << "Erro ao iniciar video! Codigo de erro: " << SDL_GetError();
    }
    else
    {   //Inicia a janela
        window = SDL_CreateWindow("Joinha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        //SDL_WINDOW_RESIZABLE redimenciona a janela, (maximiza, aumenta, diminui a tela...)

        //Verifica se da erro ao criar janela
        if(window == NULL)
            cout << "Erro ao criar janela! Codigo de erro: " << SDL_GetError();
        else
        {
            carregaImagens();
        }
    }
}

void geraMatriz()
{
        /* desenhar a Matriz */
        SDL_Rect destino;
        int linha, coluna, espSup = 75, espEsq = 285;

        for (linha = 0; linha < 7; linha++)
        {
            destino.y = espSup + (linha * moveLin);
                for (coluna = 0; coluna < 7; coluna++)
                {
                    destino.x = espEsq + (coluna * moveCol);

                    if(matriz[linha][coluna]==0)
                    {
                        SDL_BlitSurface(JoiaBranca, NULL, surface, &destino);
                    }
                    else if(matriz[linha][coluna]==1)
                    {
                        SDL_BlitSurface(JoiaAzul, NULL, surface, &destino);
                    }
                    else if(matriz[linha][coluna]==2)
                    {
                        SDL_BlitSurface(JoiaLaranja, NULL, surface, &destino);
                    }
                    else if(matriz[linha][coluna]==3)
                    {
                        SDL_BlitSurface(JoiaVerde, NULL, surface, &destino);
                    }

                }
        }
}

void geraValoresMatriz()
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

void Eventos()
{
     bool close = false;
    //Enquanto não acontece nenhum evento (clique do mouse, teclado etc...) faz..
        while(SDL_PollEvent(&Event) != 0){

            if(Event.type == SDL_QUIT)
                close = true;
            if(Event.key.keysym.sym)
            {
                //Reconhece que um evento do teclado
                switch(Event.key.keysym.sym)
                {
                //caso w seja apertado
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
                            cout << "Botao esquerdo apertado";
                            SDL_MOUSEMOTION; //é movido
                            cout << "Has movido el ratón al punto ("
                                 << Event.motion.x
                                 << ","
                                 << Event.motion.y
                                 << ").";
     	            	    break;

                        default:
     	 	                break;
     	            }
            }
        }
}

int main(int argc, char *argv[]){
    srand(time(NULL));

    geraValoresMatriz();
    carregaVideo();

    bool close = false;

    //Enquanto a janela estiver executando faz..
    while(!close){

        //Eventos que acontecens no decorrer dos loop's
        Eventos();

        //--------------------------------------Inicio da funcao principal do jogo-------------------------

        //Exibe a imagem na tela
        SDL_BlitSurface(TelaInicial, NULL, surface, NULL);

            //Gera a matriz de imagens randomicas
            geraMatriz();

        //Atualiza a janela
        SDL_UpdateWindowSurface(window);

        //--------------------------------------Fim da funcao principal do jogo----------------------------
    }

    //Libera a memória, onde a janela está alocada
    SDL_DestroyWindow(window);
    //Fecha o SDL
    SDL_Quit();
    return 0;
}

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

#define lin 7
#define col 7
#define moveLin 66
#define moveCol 65
#define Botoes 5

int x,y;
int matriz[lin][col];
int face=0;
int soma=45;
int autoriza=0;

using std::cout;
using std::cin;
using std::endl;

    SDL_Event Event;
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Surface *surface2 = NULL;
    SDL_Surface *JoiaAzul = NULL;
    SDL_Surface *JoiaBranca = NULL;
    SDL_Surface *JoiaVerde = NULL;
    SDL_Surface *JoiaLaranja = NULL;

    SDL_Surface *TelaInicial = NULL;
    SDL_Surface *Menu = NULL;
    SDL_Surface *Jogo = NULL;
    SDL_Surface *Gameover = NULL;

    SDL_Surface *logo;                          //LOGO
    SDL_Rect posicaologo;

    SDL_Surface *bt[5];                    //Botoes

    SDL_Rect posicaoBt[5];

void carregaImagens()
{
            //Passa a janela para dentro da surface
            surface = SDL_GetWindowSurface(window);

            //surface2 = SDL_GetWindowsSurface(window);

            //Telas
            TelaInicial = SDL_LoadBMP("imagens/telaInicial.bmp");
            Menu = SDL_LoadBMP("imagens/menu.bmp");
            Jogo = SDL_LoadBMP("imagens/planops.bmp");
           // Gameover = SDL_LoadBMP("imagens/planops.bmp");

            //Logo
            logo = SDL_LoadBMP("logo.png");

            //Botoes
            bt[0] = IMG_Load("imagens/bt1.png");
            bt[1] = IMG_Load("imagens/bt2.png");
            bt[2] = IMG_Load("imagens/bt3.png");
            bt[3] = IMG_Load("imagens/bt4.png");
            bt[4] = IMG_Load("imagens/bt5.png");

            //Joias
            JoiaAzul = IMG_Load("imagens/Azul1.png");
            JoiaBranca = IMG_Load("imagens/Branco.png");
            JoiaVerde = IMG_Load("imagens/Verde.png");
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
        while(SDL_PollEvent(&Event) != 0)
        {

            if(Event.type == SDL_QUIT)
                close = true;

            switch(face)
            {
                case 0:
                    SDL_BlitSurface(TelaInicial, NULL, surface, NULL);

                        x = Event.button.x;
                        y = Event.button.y;

                        posicaoBt[0].x=600;
                        posicaoBt[0].y=500;

                        SDL_BlitSurface(bt[0], NULL, surface, &posicaoBt[0]);

                        if(Event.button.button == SDL_BUTTON_LEFT)
                        {
                            if(x >= posicaoBt[0].x && x <= posicaoBt[0].x + posicaoBt[0].w && y >= posicaoBt[0].y && y <= posicaoBt[0].y + posicaoBt[0].h)
                            {
                                face=1;
                            }
                        }

                    break;

                //Menu
                case 1:
                    SDL_BlitSurface(Menu, NULL, surface, NULL);

                    x = Event.button.x;
                    y = Event.button.y;

                    //Exibe o menu de imagens na tela
                    for(int d=0;d<Botoes;d++)
                    {
                        posicaoBt[d].x=350;
                        posicaoBt[d].y=300+(45*d);

                        SDL_BlitSurface(bt[d], NULL, surface, &posicaoBt[d]);
                    }

                    if(Event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(x >= posicaoBt[0].x && x <= posicaoBt[0].x + posicaoBt[0].w && y >= posicaoBt[0].y && y <= posicaoBt[0].y + posicaoBt[0].h)
                        {
                            face=2;
                        }

                        if(x >= posicaoBt[4].x && x <= posicaoBt[4].x + posicaoBt[4].w && y >= posicaoBt[4].y && y <= posicaoBt[4].y + posicaoBt[4].h)
                        {
                            face=0;
                        }
                    }

                    break;

                //Jogo
                case 2:
                    autoriza=1;
                    SDL_BlitSurface(Jogo, NULL, surface, NULL);

                    x = Event.button.x;
                    y = Event.button.y;

                    posicaoBt[4].x=45;
                    posicaoBt[4].y=500;

                    SDL_BlitSurface(bt[4], NULL, surface, &posicaoBt[4]);

                    if(Event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(x >= posicaoBt[4].x && x <= posicaoBt[4].x + posicaoBt[4].w && y >= posicaoBt[4].y && y <= posicaoBt[4].y + posicaoBt[4].h)
                        {
                            face=0;
                            autoriza=0;
                        }
                    }

                    break;

                case 3:
                    break;

                default:
                    break;

                switch(Event.type)
                {
                    case SDL_MOUSEBUTTONDOWN: //é clicado

                        if(SDL_BUTTON_LEFT)
                        {
                            //Função Troca

                            //Função Troca
                            cout << "Botao esquerdo apertado\n";
                            cout << "Has movido el ratón al punto ("
                                 << Event.motion.x
                                 << ","
                                 << Event.motion.y
                                 << ").\n";
                        }
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

            if(autoriza==1)
            {
                   //Gera a matriz de imagens randomicas
            geraMatriz();
            }


        //Atualiza a janela
        SDL_UpdateWindowSurface(window);

        //--------------------------------------Fim da funcao principal do jogo----------------------------
    }

    SDL_FreeSurface(TelaInicial);
    //Libera a memória, onde a janela está alocada
    SDL_DestroyWindow(window);
    //Fecha o SDL
    SDL_Quit();
    return 0;
}

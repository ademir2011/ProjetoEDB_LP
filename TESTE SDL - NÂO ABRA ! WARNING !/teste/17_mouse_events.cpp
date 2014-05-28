#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

int main()
{
    //inicialização
    int x = 0,y = 0;
    int jogador1, jogador2;

    char linear[100];

    while(true)
    {
        if(x>100)
        {
            x=0;
        }

    debujar_circ(x, y, 100);
    x++;

    if(usuarioSair==true)
    {
        break;
    }

    }

    return 0;
}

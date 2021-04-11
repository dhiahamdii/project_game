#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include <time.h>
int main()
{
int a=1;
FILE *f=NULL;
srand(time(NULL));
a=rand()%5;
SDL_Init(SDL_INIT_VIDEO); 
SDL_Surface *ecran =NULL;
ecran=SDL_SetVideoMode(1280, 720, 32,SDL_HWSURFACE  |  SDL_DOUBLEBUF);
enigma(ecran,a);
if ( ecran == NULL)
    {
        fprintf(f,"error 404 : %s\n", SDL_GetError());
        fclose(f);
        exit(EXIT_FAILURE);
    }
SDL_Flip(ecran);
reponse(ecran,a);
SDL_Quit();
    return EXIT_SUCCESS; 
}

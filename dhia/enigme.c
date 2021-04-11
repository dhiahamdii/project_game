#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <string.h>

void solution(SDL_Surface *ecran,int a)
{
    char im[100];
    SDL_Surface *image1 = NULL;
    SDL_Rect positionFond1;
    positionFond1.x =  0 ;
    positionFond1.y =  0 ;
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    image1= IMG_Load("wrong.png");
    SDL_BlitSurface(image1,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(500);
    sprintf(im,"sol/%d.png",a);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(2000);
}

void correct(SDL_Surface *ecran)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"correct.png");
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(2000);
}

void enigma(SDL_Surface *ecran,int a)
{FILE *f=NULL;
f=fopen("compi.txt","w");
    fprintf(f,"Init SDL.\n");
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"Q/%d.png",a);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
if ( ecran == NULL)
    {
        fprintf(f,"error 404 : %s\n", SDL_GetError());
        fclose(f);
        exit(EXIT_FAILURE);
    }
    SDL_Flip(ecran);
    

}


void reponse(SDL_Surface *ecran,int a)
{int continuer =1;
    int i=0;
FILE *f=NULL;
    SDL_Event event;
    char im[100], im1[100], im2[100], im3[100],im4[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL,*image4 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"answer/%d.png",a);
    image= IMG_Load(im);
    sprintf(im1,"answer/%d/1.png",a);
    sprintf(im2,"answer/%d/2.png",a);
    sprintf(im3,"answer/%d/3.png",a);
    sprintf(im4,"answer/%d/4.png",a);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);
    image4= IMG_Load(im4);
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
if ( ecran == NULL)
    {
        fprintf(f,"error image 3 : %s\n", SDL_GetError());
        fclose(f);
        exit(EXIT_FAILURE);
    }


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=4)
                {

                    if (i==1 && a%4==1)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else if (i==2 && a%4==2)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else if (i==3 && a%4==3)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else if (i==4 && a%4==0)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,a);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==5)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=4;
                }
                if(i==5)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim);
                    SDL_Flip(ecran);

                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,ecran,&positionim);
       //SDL_Flip(ecran);
    }


}

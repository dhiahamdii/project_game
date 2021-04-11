#include "main.h"

int main(int argc, char *argv[])
{
    FILE *f=NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    f=fopen("compi.txt","w");
    fprintf(f,"Init SDL.\n");
    SDL_Surface *screen = NULL, *background = NULL,*TextMainMenu = NULL,*Textplay=NULL,*Textsettings=NULL,*Textcredits=NULL,*Textexit=NULL,*TextBack=NULL,*settings=NULL,*more=NULL,*Textmoretext=NULL,*newgame=NULL,*bar0=NULL,*bar20=NULL,*bar40=NULL,*bar60=NULL,*bar80=NULL,*bar100=NULL,*fullscreen=NULL,*fullscreenp=NULL;
    SDL_Rect backgroundPosition,position,posPlay,posSettings,posMore,posExit,posmore,possettings,posnewgame,posBack,posmoretext,posmoretext2,posmoretext3,posmoretext4,posmoretext5,posmoretext6,posmoretext7,posbar,posfull;

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1 )
    {
        printf("%s",Mix_GetError());
    }
int j=20;
    Mix_Music *bgMusic;
    bgMusic = Mix_LoadMUS("res/5oneya.mp3");
    Mix_PlayMusic(bgMusic,-1);
    /*Mix_VolumeMusic(0);*/
    Mix_Chunk *SelecSound;
    SelecSound = Mix_LoadWAV("res/sout.wav");

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    backgroundPosition.x = 0;
    backgroundPosition.y = 0;
    if ( screen == NULL)
    {
        fprintf(f,"error 404 : %s\n", SDL_GetError());
        fclose(f);
        exit(EXIT_FAILURE);
    }


    SDL_WM_SetCaption("tequila pickels !", NULL);
    background = SDL_LoadBMP("res/background .bmp");
    more = SDL_LoadBMP("res/more.bmp");
    newgame = SDL_LoadBMP("res/newgame.bmp");
    settings = SDL_LoadBMP("res/settings.bmp");
    bar0=IMG_Load("Settings/Son/bar0.png");
    bar20=IMG_Load("Settings/Son/bar20.png");
    bar40=IMG_Load("Settings/Son/bar40.png");
    bar60=IMG_Load("Settings/Son/bar60.png");
    bar80=IMG_Load("Settings/Son/bar80.png");
    bar100=IMG_Load("Settings/Son/bar100.png");
    fullscreen=IMG_Load("Settings/Fullscreen/fullscreen.png");
    fullscreenp=IMG_Load("Settings/Fullscreen/fullscreenp.png");
    SDL_BlitSurface(background, NULL, screen, &backgroundPosition);
    fprintf(f,"Chargement background \n");

    if(TTF_Init() == -1)
    {
        fprintf(f, "error 404 : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);

    }
    fprintf(f,"SDL_TTF jawo behyy \n");
    TTF_Font *policeTitre = NULL, *policeboutton = NULL;
    policeTitre = TTF_OpenFont("res/aa.ttf", 40);
    policeboutton =  TTF_OpenFont("res/snapitc.ttf", 30);


    SDL_Color couleurBlanc = {255, 255, 255};
    SDL_Color couleurBlack = {0, 0, 0};
    SDL_Color couleurRed = {255, 0, 0};
    SDL_Color couleurGreenlime = {50, 205, 50};
    TextMainMenu = TTF_RenderText_Blended(policeTitre, "Main Menu", couleurGreenlime);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    Textplay = TTF_RenderText_Blended(policeboutton, "NEW GAME", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    Textsettings = TTF_RenderText_Blended(policeboutton, "SETTINGS", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    Textcredits = TTF_RenderText_Blended(policeboutton, "MORE", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    Textexit = TTF_RenderText_Blended(policeboutton, "EXIT", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    TextBack = TTF_RenderText_Blended(policeboutton, "BACK", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    Textmoretext = TTF_RenderText_Blended(policeboutton, "", couleurBlack);
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255 ));

///////////////////
posbar.x=761;
posbar.y=233;
posfull.x=392;
posfull.y=427;


/////////////////////////

    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(background,NULL,screen,&position);

    posnewgame.x = 0;
    posnewgame.y = 0;

    posmore.x=0;
    posmore.y=0;

    possettings.x=0;
    possettings.y=0;

    posBack.x=1100;
    posBack.y=650;

    posmoretext.x=100;
    posmoretext.y=100;

    posmoretext2.x=500;
    posmoretext2.y=150;

    posmoretext3.x=500;
    posmoretext3.y=200;

    posmoretext4.x=500;
    posmoretext4.y=250;

    posmoretext5.x=500;
    posmoretext5.y=300;

    posmoretext6.x=500;
    posmoretext6.y=350;

    posmoretext7.x=500;
    posmoretext7.y=400;
    

    position.x=555;
    position.y=340;
    SDL_BlitSurface(TextMainMenu,NULL,screen,&position);

    posPlay.x=545;
    posPlay.y=425;
    SDL_BlitSurface(Textplay,NULL,screen,&posPlay);
                                                                                 
    posSettings.x=558;
    posSettings.y=475;
    SDL_BlitSurface(Textsettings,NULL,screen,&posSettings);

    posMore.x=595;
    posMore.y=525;
    SDL_BlitSurface(Textcredits,NULL,screen,&posMore);

    posExit.x=604;
    posExit.y=575;
    SDL_BlitSurface(Textexit,NULL,screen,&posExit);


    int continuer = 1,use =0,ex=0,i=0,s=0;
    SDL_Event event;
int volume=100;
    char filename[100];
    int SelecPlay=1,SelecSettings=1,SelecCredits=1,SelecExit=1,SelecBack=1;
///////////////////////////////////////////////
///////////////////////////////////////////////
/*if (i != 0)
        SDL_FreeSurface(background);*/
        //animate the background
       /* sprintf(filename, "new bg/%d.jpg", i);
        background = IMG_Load(filename);
        i++;
        if (i > 6)
        {
            i = 0;
        }
        SDL_BlitSurface(background, NULL, screen, &backgroundPosition);
if ( background == NULL)
    {
        fprintf(f,"error 404 3asba: %s\n", SDL_GetError());
        fclose(f);
        exit(EXIT_FAILURE);
    }*/
///////////////////////////////////
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;




        case SDL_MOUSEMOTION:
/////////////////////////////////////////////////////////////////////
//////////////////////////////play co///////////////////////////////////////
if(use==0)
{
            if( (event.motion.x >= posPlay.x && event.motion.x <= posPlay.x + Textplay->w+13) && (event.motion.y >= posPlay.y && event.motion.y <= posPlay.y + Textplay->h) )
            {

                if(SelecPlay == 1)
                {
                    Mix_PlayChannel(1,SelecSound,0);
                    SDL_FreeSurface(Textplay);
                    Textplay = TTF_RenderText_Blended(policeboutton, "NEW GAME", couleurGreenlime);
                    SDL_BlitSurface(Textplay,NULL,screen,&posPlay);

                }
                SelecPlay =0;
            }
            else
            {
                SDL_FreeSurface(Textplay);
                Textplay = TTF_RenderText_Blended(policeboutton, "NEW GAME", couleurBlack);
                SDL_BlitSurface(Textplay,NULL,screen,&posPlay);
                SelecPlay =1;
            }
}
/////////////////////////////////////////////////////////////////////
////////////////////////////// settings co///////////////////////////////
if(use==0)
{

            if( (event.motion.x >= posSettings.x && event.motion.x <= posSettings.x + Textsettings->w-5) && (event.motion.y >= posSettings.y && event.motion.y <= posSettings.y + Textsettings->h) )
            {

                if(SelecSettings == 1)
                {
                    Mix_PlayChannel(1,SelecSound,0);
                    SDL_FreeSurface(Textplay);
                    Textsettings = TTF_RenderText_Blended(policeboutton, "SETTINGS", couleurGreenlime);
                    SDL_BlitSurface(Textsettings,NULL,screen,&posSettings);
                }
                SelecSettings =0;
            }
            else
            {
                SDL_FreeSurface(Textsettings);
                Textsettings = TTF_RenderText_Blended(policeboutton, "SETTINGS", couleurBlack);
                SDL_BlitSurface(Textsettings,NULL,screen,&posSettings);
                SelecSettings =1;
            }}
/////////////////////////////////////////////////////////////////////
////////////////////////////////////more co/////////////////////////////////
if(use==0)
{

            if( (event.motion.x >= posMore.x && event.motion.x <= posMore.x + Textcredits->w) && (event.motion.y >= posMore.y && event.motion.y <= posMore.y + Textcredits->h) )
            {

                if(SelecCredits == 1)
                {
                    Mix_PlayChannel(1,SelecSound,0);
                    SDL_FreeSurface(Textcredits);
                    Textcredits = TTF_RenderText_Blended(policeboutton, "MORE", couleurGreenlime);
                    SDL_BlitSurface(Textcredits,NULL,screen,&posMore);
                }
                SelecCredits =0;
            }
            else
            {
                SelecCredits =1;
                SDL_FreeSurface(Textcredits);
                Textcredits = TTF_RenderText_Blended(policeboutton, "MORE", couleurBlack);
                SDL_BlitSurface(Textcredits,NULL,screen,&posMore);
            }
}
/////////////////////////////////////////////////////////////////////
////////////////////////////exit co/////////////////////////////////////////
if(use==0)
{
            if( (event.motion.x >= posExit.x && event.motion.x <= posExit.x + Textexit->w) && (event.motion.y >= posExit.y && event.motion.y <= posExit.y + Textexit->h) )
            {

                if(SelecExit == 1)
                {
                    Mix_PlayChannel(1,SelecSound,0);
                    SDL_FreeSurface(Textexit);
                    Textexit = TTF_RenderText_Blended(policeboutton, "EXIT", couleurGreenlime);
                    SDL_BlitSurface(Textexit,NULL,screen,&posExit);
                }
                SelecExit =0;
            }
            else
            {
                SelecExit =1;
                SDL_FreeSurface(Textexit);
                Textexit = TTF_RenderText_Blended(policeboutton, "EXIT", couleurBlack);
                SDL_BlitSurface(Textexit,NULL,screen,&posExit);
            }}
////////////////////////////////////////////////////////////////////

            break;   //break mousemotion//
case SDL_KEYDOWN:
//////////////////////////key quit////////////////////
            if ((event.key.keysym.sym == SDLK_ESCAPE)||(event.key.keysym.sym == SDLK_q))
                continuer = 0;
/////////////////////////

        case SDL_MOUSEBUTTONDOWN:
/////////////////////QUIT GAME/////////////////////
            if(ex==0)
{
if( ((event.button.x >= posExit.x && event.button.x <= posExit.x + Textexit->w) && (event.button.y >= posExit.y && event.button.y <= posExit.y + Textexit->h) )||(event.key.keysym.sym == SDLK_q))
            {
                continuer = 0;
            }
}
/////////////////////////////////////////////////
////////////////////////play bg/////////////////////
if(ex==0)
{
if( ((event.button.x >= posPlay.x && event.button.x <= posPlay.x + Textplay->w -5) && (event.button.y >= posPlay.y && event.button.y <= posPlay.y + Textplay->h) )||(event.key.keysym.sym == SDLK_n))
            {
            
              SDL_BlitSurface(newgame,NULL,screen,&posnewgame);
              SDL_Flip(screen);
              TextBack = TTF_RenderText_Blended(policeboutton, "BACK", couleurRed);
              SDL_BlitSurface(TextBack,NULL,screen,&posBack);
              use =1;
              ex=1;
            } 
}
///////////////////////////////////////////     
////////////////////back///////////////////   

if (( ((event.button.x >= posBack.x && event.button.x <= posBack.x + TextBack->w) && (event.button.y >= posBack.y && event.button.y <= posBack.y + TextBack->h) )&&(use!=0&&s!=1))||(event.key.keysym.sym == SDLK_b))
{
    SDL_BlitSurface(background,NULL,screen,&backgroundPosition);
    SDL_BlitSurface(TextMainMenu,NULL,screen,&position);

    use=0;
    ex=0;
    s=0;
}
/////////////////////////////////////////////////////////////
///////////back settings///////////////////
if (( ((event.button.x >= 20 && event.button.y >= 8) && (event.button.x <=120  && event.button.y <= 92) )&&((use!=0)&&(s==1)))||(event.key.keysym.sym == SDLK_b))
{
    SDL_BlitSurface(background,NULL,screen,&backgroundPosition);
    SDL_BlitSurface(TextMainMenu,NULL,screen,&position);

    use=0;
    ex=0;
    s=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
if (s==1)
{
///////////////////volume up ///////////////////
if ((event.button.x > 616 && event.button.y > 233 && event.button.x < 706 && event.button.y < 303)&& (volume<=100))    
    {
                        volume+=20;
                          

                        if(volume==20)
                        {
                         Mix_VolumeMusic(20);  
                         Mix_VolumeChunk(SelecSound,20);  
                         SDL_BlitSurface(bar20,NULL,screen,&posbar);
                         SDL_Flip(screen);                              
                        }
                         else if(volume==40)
                        {                            
                        Mix_VolumeMusic(40); 
                        Mix_VolumeChunk(SelecSound,40);   
                        SDL_BlitSurface(bar40,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                                                                   
                        }
                       else if(volume==60)
                        {                          
                        Mix_VolumeMusic(60);                                                          
                        Mix_VolumeChunk(SelecSound,60);   
                        SDL_BlitSurface(bar60,NULL,screen,&posbar);
                        SDL_Flip(screen);                             
                        }
                        else if(volume==80)
                        {                          
                        Mix_VolumeMusic(80);
                        Mix_VolumeChunk(SelecSound,80);  
                        SDL_BlitSurface(bar80,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                               
                        }
                       else if(volume==100)
                        {             
                         Mix_VolumeMusic(100);
                         Mix_VolumeChunk(SelecSound,100);  
                         SDL_BlitSurface(bar100,NULL,screen,&posbar);
                         SDL_Flip(screen);                                                                  
                        }

                     }
///////////////////////////////////////////////////////////
///////////////////volume down////////////////////////////////
if ((event.button.x > 492&& event.button.y >233 && event.button.x < 561 && event.button.y < 303)&& (volume>=0))
                     {
                         volume-=20;

                     
                        if(volume==20)
                        {                                                 
                        Mix_VolumeMusic(20);
                        Mix_VolumeChunk(SelecSound,20);
                        SDL_BlitSurface(bar20,NULL,screen,&posbar);
                        SDL_Flip(screen);                                     
                        }
                       else if(volume==40)
                        {                            
                        Mix_VolumeMusic(40);        
                        Mix_VolumeChunk(SelecSound,40);
                        SDL_BlitSurface(bar40,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                                  
                        }
                       else if(volume==60)
                        {                            
                        Mix_VolumeMusic(60);           
                        Mix_VolumeChunk(SelecSound,60);
                        SDL_BlitSurface(bar60,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                               
                        }
                        else if(volume==80)
                        {                           
                        Mix_VolumeMusic(80);                    
                        Mix_VolumeChunk(SelecSound,80); 
                        SDL_BlitSurface(bar80,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                                   
                        }                                                    
                       else if(volume==0)
                        {
                        Mix_VolumeMusic(0);                       
                        Mix_VolumeChunk(SelecSound,0); 
                        SDL_BlitSurface(bar0,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                               
                        }

                     }
///////////////////////////////////////////////
//////////////////muet//////////////////////////////
if (event.button.x > 365 && event.button.y > 233 && event.button.x < 427 && event.button.y < 303)
                        {
                        volume=0;
                        Mix_VolumeMusic(0);  
                        Mix_VolumeChunk(SelecSound,0); 
                        SDL_BlitSurface(bar0,NULL,screen,&posbar);
                        SDL_Flip(screen);                                                                     
                        }
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////fullscreen//////////////////////////////////////////////////////
if (event.button.x > 392 && event.button.y > 427 && event.button.x < 472 && event.button.y < 506)
{
screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_FULLSCREEN);

              SDL_BlitSurface(settings,NULL,screen,&possettings);
              SDL_Flip(screen); 
              SDL_BlitSurface(fullscreenp,NULL,screen,&posfull);
              SDL_Flip(screen);

}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////settings bg//////////////////////
if(ex==0)
{
if(( (event.button.x >= posSettings.x && event.button.x <= posSettings.x + Textsettings->w +50) && (event.button.y >= posSettings.y && event.button.y <= posSettings.y + Textsettings->h) )||(event.key.keysym.sym == SDLK_s))
            {

              SDL_BlitSurface(settings,NULL,screen,&possettings);
              SDL_Flip(screen);
              SDL_BlitSurface(bar100,NULL,screen,&posbar);
                        SDL_Flip(screen);
              SDL_BlitSurface(fullscreen,NULL,screen,&posfull);
                        SDL_Flip(screen);
use =1;
ex=1;
s=1;
                                                                                                                                       //TEQUILA
                                                                                                

          
                                                                                                                                                                                                                                                                                            

}
}
////////////////////////////more bg//////////////////////////
if(ex==0)
{
if( ((event.button.x >= posMore.x && event.button.x <= posMore.x + Textcredits->w) && (event.button.y >= posMore.y && event.button.y <= posMore.y + Textcredits->h) )||(event.key.keysym.sym == SDLK_m))
            {
                    SDL_BlitSurface(more,NULL,screen,&posmore);
                    SDL_Flip(screen);
                    TextBack = TTF_RenderText_Blended(policeboutton, "BACK", couleurRed);
                    SDL_BlitSurface(TextBack,NULL,screen,&posBack);
                    Textmoretext = TTF_RenderText_Blended(policeboutton, "THIS GAME IS MADE BY TEQUILA MOCKINGBIRDS TEAM", couleurBlack);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext);
                    Textmoretext = TTF_RenderText_Blended(policeboutton, "OUR TEAM :", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext2);
                    Textmoretext = TTF_RenderText_Blended(policeboutton, "Karim Ben Youssef", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext3);
Textmoretext = TTF_RenderText_Blended(policeboutton, "Fedi zayani", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext4);
Textmoretext = TTF_RenderText_Blended(policeboutton, "Dhia hamdi", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext5);
Textmoretext = TTF_RenderText_Blended(policeboutton, "Saber sebri", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext6);
Textmoretext = TTF_RenderText_Blended(policeboutton, "Mahdi damargi", couleurRed);
                    SDL_BlitSurface(Textmoretext,NULL,screen,&posmoretext7);
use =1;ex=1;
            }}
            break;
        }

        SDL_Flip(screen);
    }
    SDL_Flip(screen);
    TTF_CloseFont(policeboutton);
    TTF_CloseFont(policeTitre);

    SDL_FreeSurface(background);
    fclose(f);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
//TEQUILA//


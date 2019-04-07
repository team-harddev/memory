#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */

 void pause();

int main(int argc, char *argv[])

{


    SDL_Init(SDL_INIT_VIDEO);


    pause();

    SDL_Quit();

 

    return EXIT_SUCCESS;

}

 
void pause()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *bambou = NULL;

    SDL_Rect positionFond, positionBambou;

    positionFond.x = 0;

    positionFond.y = 0;

    positionBambou.x = 500;

    positionBambou.y = 260;

 
    int continuer = 1;
    SDL_Event event;

    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
 
    imageDeFond = IMG_Load("lac_en_montagne.bmp");

 

    /* Chargement d'un PNG avec IMG_Load

    Celui-ci est automatiquement rendu transparent car les informations de

    transparence sont codées à l'intérieur du fichier PNG */

    bambou = IMG_Load("bamboo pixel1.png");


      while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                
                continuer = 0;
               
                break;

           /* case SDL_MOUSEBUTTONUP:

                if(event.button.button == SDL_BUTTON_RIGHT)
                     {
                         continuer = 0;
                     }
                 break;

            case SDL_MOUSEMOTION:

                positionBambou.x = event.motion.x;
                positionBambou.y = event.motion.y;
                
                break;
            */
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        
                        positionBambou.y--;
                        
                        break;
                    
                    case SDLK_DOWN:
                       
                        positionBambou.y++;
                        
                        break;
                    
                    case SDLK_RIGHT:
                        
                        positionBambou.x++;
                       
                        break;
                    
                    case SDLK_LEFT:
                       
                        positionBambou.x--;
                        
                        break;

                 
                    case SDLK_ESCAPE:
                        
                        continuer = 0;
                        
                        break;
                }
           
            break;
        }
    
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_BlitSurface(bambou, NULL, ecran, &positionBambou);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bambou);
}
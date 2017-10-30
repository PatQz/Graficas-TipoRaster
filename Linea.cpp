#include <stdio.h>
#include <SDL2/SDL.h>
#include<iostream>
using namespace std;
int main( int argc, char* args[] ){
    int X1,Y1,X2,Y2;
    X1=0;
    X2=600;
    Y1=0;
    Y2=600;
    int tp=600;
    double dY, dX,k,X,Y,av,avR,avI;
    int IncYi,IncXi,IncXr,IncYr;
    //Event handler
    SDL_Event e;
    //gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{cout<<"Ingrese valor de X1: ";
    cin>>X1;
    cout<<"Ingrese valor de Y1: ";
    cin>>Y1;
    cout<<endl<<"Ingrese valor de X2: ";
    cin>>X2;
    cout<<"Ingrese valor de Y2: ";
    cin>>Y2;
    }while(X1>tp and X2>tp and Y1>tp and Y2>tp);

   if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Event event;
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(tp,tp, 0, &window, &renderer) == 0) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);
             SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, 300,0,300,600);
            SDL_RenderDrawLine(renderer, 0,300,600,300);
            SDL_SetRenderDrawColor(renderer, 255, 0,255, 255);
                
        dY=(Y2-Y1);
        dX=(X2-X1);
         // 1 - Incrementos para las secciones con avance inclinado
        if(dY>=0) IncYi = 1;
        else IncYi = -1;

        if(dX>=0)IncXi = 1;
        else IncXi = -1;
    
        // 2 - Incrementos para las secciones con avance recto:
        if(dX>=dY){
            IncYr = 0;
            IncXr = IncXi;
        }else{
            IncXr = 0;
            IncYr = IncYi;
        // Cuando dy es mayor que dx, se intercambian, para reutilizar el mismo bucle.
        // ver octantes blancos en la imagen encima del código
            k = dX;
            dX = dY;
            dY = k;
        }

        // 3  - Inicializar valores (y de error).
        X = X1;
        Y = Y1; 
        avR = (2 * dY);
        av = (avR - dX);
        avI = (av - dX);

        // 4  - Bucle para el trazado de las línea
            while(X<=X2){
                SDL_RenderDrawPoint(renderer, X+300, -Y+300);
                if(av>=0){
                    X = (X + IncXi);     // X aumenta en inclinado.
                    Y = (Y + IncYi);    // Y aumenta en inclinado.
                    av = (av + avI);     // Avance Inclinado
                }else{
                    X = (X + IncXr);     // X aumenta en recto.
                    Y = (Y + IncYr);     // Y aumenta en recto.
                    av = (av + avR);     // Avance Recto
                }
            }

        SDL_RenderPresent(renderer);
        while (1) {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        }
        

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
                }
        }
     }

    SDL_Quit();
    return 0;
}
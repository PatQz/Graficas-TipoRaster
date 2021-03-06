#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
using namespace std;
int main( int argc, char* args[] ){
    int X1,Y1,X2,Y2;
    int tp=600;
    int r;
    double dY, dX,k,X,Y,av,avR,avI,d1,d2,u,v;

    //Event handler
    SDL_Event e;
        cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{cout<<"Ingrese valor del radio: ";
        cin>>r;
    }while(r>tp);

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
            
            X=0;
            Y=r;
            d1=1-r; //valor inicial de dF(1,b-1/2)

            while(X<Y){
                X=X+1;
                if(d1<0){
                    //E
                    d1+=(2*X)+3;
                }else{
                    //SE
                    d1+=(2*X)-(2*Y)+5;
                    Y=Y-1;
                }
                SDL_RenderDrawPoint(renderer, X+300, Y+300);
                SDL_RenderDrawPoint(renderer, -X+300, Y+300);
                SDL_RenderDrawPoint(renderer, X+300, -Y+300);
                SDL_RenderDrawPoint(renderer, -X+300, -Y+300);

                SDL_RenderDrawPoint(renderer,Y+300, X+300);
                SDL_RenderDrawPoint(renderer,-Y+300, X+300);
                SDL_RenderDrawPoint(renderer,Y+300, -X+300);
                SDL_RenderDrawPoint(renderer,-Y+300, -X+300);
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
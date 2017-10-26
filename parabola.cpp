#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

int main( int argc, char* args[] ){
    int X1,Y1,X2,Y2;
    int tp=600;
    double dY, dX,k,X,Y,av,avR,avI,d1,d2,u,v,di;
    int IncYi,IncXi,IncXr,IncYr;

    //Event handler
    SDL_Event e;
    //gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
   
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
            X1=200; //a
            Y1=200; //b

            X=0;
            Y=Y1;
            int p=50;
            d1=pow(X1,2)-4*(p*Y1); //valor inicial 
            //SDL_RenderDrawPoint(renderer, X+300, Y+300);
            /*SDL_RenderDrawPoint(renderer, X+300, Y+300);
            SDL_RenderDrawPoint(renderer, -X+300, Y+300);
            SDL_RenderDrawPoint(renderer, X+300, -Y+300);
            SDL_RenderDrawPoint(renderer, -X+300, -Y+300);*/
            //REGION I
            while((pow(X1,2)*(Y+(0.5)))>(pow(Y1,2)*(X+1))){
                if(d1<0){
                    d1=d1+2*(X1)+3;
                    X=X+1;
                }else{
                    d1=d1+3*(X1)-4*p+3;
                    X=X+1;
                    Y=Y-1;
                }
                //SDL_RenderDrawPoint(renderer, X+300, Y+300);
                //SDL_RenderDrawPoint(renderer, -X+300, Y+300);
                SDL_RenderDrawPoint(renderer, X+300, -Y+300);
                SDL_RenderDrawPoint(renderer, -X+300, -Y+300);
            }
            //REGION II
            d2=pow(X1+0.5,2)-4*(p*Y1+1.0);

            while(Y>0){
               
                if(d2<0){
                    d2=d2-(4*p);
                    X=X+1;
                    Y=Y-1;
                }else{
                    d2=d2+2*(X1)-(4*p)+2;
                    Y=Y-1;
                }
                //SDL_RenderDrawPoint(renderer, X+300, Y+300);
                //SDL_RenderDrawPoint(renderer, -X+300, Y+300);
                SDL_RenderDrawPoint(renderer, X+300, -Y+300);
                SDL_RenderDrawPoint(renderer, -X+300, -Y+300);
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
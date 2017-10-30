#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
using namespace std;
int main( int argc, char* args[] ){
    int X1,Y1;
    int tp=600;
    double X,Y,d1,d2;
   
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
            int p=50; //parametro

            X=0;
            //Y=0;
            Y=0;
            //int p2,p4,d;
            //p2 = 2*p;
            //p4 = 2*p2;
            
            //REGION I
            //d=1-p;
            d1=pow(X+1.0,2)-4*(p*(Y+0.5)); //valor inicial 
            
            //se utiliza el gradiente de F(x+1,y+1/2) para dibujar en la region I
            while((4*pow(X,2)+8*X+4-16*pow(p,2))<1){
            //while(Y<p && X<=tp){
                /*if(d>=0){
                    X++;
                    //Y++;
                    d=d-p2;
                   // d1=d1+3*(X1)-4*p+3;
                }
                d = d + 2*Y +1;
                //d1=d1+2*(X1)+3;
                Y++;*/
                if(d1<0){
                    //NE
                    d1=d1+2*(X1)+3;
                    X=X+1;
                }else{
                    //E
                    d1=d1+3*(X1)-4*p+3;
                    X=X+1;
                    Y=Y+1;
                }
                SDL_RenderDrawPoint(renderer, X+300, Y+300);
                SDL_RenderDrawPoint(renderer, X+300, Y+300);
            }
            //REGION II
            //if(d == 1) d = 1 - p4;
            //else d = 1 - p2;
            //se utiliza el gradiente de F(x+1/2,y+1) para dibujar en la region I
            d2=pow(X1+0.5,2)-4*(p*Y1+1.0);
            if((4*pow(X,2)+4*X+1-16*pow(p,2))>1){
                while(X<=tp){
                    /*if(d<=0){
                        Y++;
                        //X++;
                        d=d+4*Y;
                        //d2=d2-(4*p);
                    }
                    d=d-p4;
                    //d2=d2+2*(X1)-(4*p)+2;
                    X++;*/

                    //N
                     if(d2<0){
                         d2=d2-(4*p);
                         X=X+1;
                         Y=Y1;
                    //NE
                    }else{
                         d2=d2+2*(X1)-(4*p)+2;
                         Y=Y+1;
                     }
                SDL_RenderDrawPoint(renderer, X+300, Y+300);
                SDL_RenderDrawPoint(renderer, X+300, Y+300);
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
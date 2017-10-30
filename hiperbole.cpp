#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
using namespace std;
int main( int argc, char* args[] ){
   int x,y,d1,d2,p;
   double a,b;
   int limite=600;

   if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Event event;
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(limite,limite, 0, &window, &renderer) == 0) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, 300,0,300,600);
            SDL_RenderDrawLine(renderer, 0,300,600,300);
            SDL_SetRenderDrawColor(renderer, 255, 0,255, 255);
        a=100;
        b=100;
        y=0;
        x=0;

        double aa = a*a;
        double bb = b*b;
        double aa2 = 2*aa;
        double bb2 = 2*bb;
        double fx = bb*2*a, fy = 0;

        d1=(pow(b,2)*pow(x+0.5,2))-(pow(a,2)*pow(y+1.0,2))-(pow(a,2)*pow(b,2));
        //gradiente de funcion original para region I
        //REGION I I: mientras 2x<-4*p significa que es sigue siendo menor que m=1
        //while(2*x < -4*p){
        while(x<=limite){
            //cout<<"Entre we R1"<<endl;
            //y++;
            if(d1<=0){
                //N
                cout<<"N"<<endl;
                 d1+=-(2*pow(a,2)*y)-(3*pow(a,2));
                cout<<d1<<endl;
                x++;
                y++;
            }else
            {
                //NE
                cout<<"NE"<<endl;
                y++;
                d1+=(2*pow(b,2))*(x+2*pow(b,2))-(2*pow(a,2)*y)-(3*pow(a,2));
            }
            SDL_RenderDrawPoint(renderer, x+300+a, -y+300);
            //SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            }
        
        //cout<<"Entre we R2"<<endl;
        //REGION II
        if(a>b){
        d2=(pow(b,2)*pow(x+1.0,2))-(pow(a,2)*pow(y+0.5,2))-(pow(a,2)*pow(b,2));
        while(y<=limite){
            if(d2<=0){
                //NE
                //cout<<"Entre we NE"<<endl;
                d2+=(2*pow(b,2))*x+(3*pow(b,2))-2*pow(a,2)*y-2*pow(a,2);
                
                x++;
                y++;
            }else{
                //E
                //cout<<"Entre we N"<<endl;
                d2+=2*pow(b,2)*y+3*pow(b,2);
                x++;
                //y++; 
                }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            //SDL_RenderDrawPoint(renderer, -x+300, -y+300);
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
#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
using namespace std;
int main( int argc, char* args[] ){
   int x,y;
   double a,b,d1,d2;
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

        cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
        do{cout<<"Ingrese valor de a: ";
            cin>>a;
            cout<<"Ingrese valor de b: ";
            cin>>b;
        }while(a>limite and b>limite);

        x=a;
        y=0;

        int aa = a*a;
        int bb = b*b;
        //double d1 = 2*aa - bb - 2*a*bb;

        d1=(bb*pow(x+0.5,2))-(aa*pow(y+1.0,2))-(aa*bb);
        //d1=4*(a*bb + bb - aa);
        while(2*bb*x > 2*aa*y){
            y++;
            if(d1>0){
                //N
                //CAMBIAR
                d1 += -4*aa*(2*y-3);
                
            }else{
                //NE
                x++;
                //CAMBIAR
                d1 = d1 + 4*2*bb*(x+1) - 4*aa*( 2*y +3);
            }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, x+300, y+300);
             SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, y+300);
            }
        
        //REGION II
        if(a>b){
            //este 
            d2=2*bb*(x+1)*(x+1) - 2*aa*bb - aa*(y*y + (y+1)*(y+1));
            //o este
            //d2=(bb*pow(x+1.0,2))-(aa*pow(y+0.5,2))-(aa*bb);
            while(x<=limite){
                x++;
                if(d2>0){
                    //NE
                    y++;
                    d2+=(2*bb*x+(3*bb)-2*aa*y-2*aa);
                    
                }else{
                    //E
                    d2+=2*bb*y+3*bb;
                }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, x+300, y+300);
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
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

        cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
        do{cout<<"Ingrese valor de a: ";
            cin>>a;
            cout<<"Ingrese valor de b: ";
            cin>>b;
        }while(a>limite and b>limite);

        y=0;
        x=a;

        double aa = a*a;
        double bb = b*b;
        double fx = bb*2*a, fy = 0;
        double d1 = 2*aa - bb - 2*a*bb;

        d1=(pow(b,2)*pow(x+0.5,2))-(pow(a,2)*pow(y+1.0,2))-(pow(a,2)*pow(b,2));
        while(fx > fy && x<=limite){
            if(d1<=-bb/2.0){
                //N
                d1+=-(2*pow(a,2)*y)-(3*pow(a,2));
                //x++;
               
            }else{
                //NE
                x++;
                d1+=(2*pow(b,2))*(x+2*pow(b,2))-(2*pow(a,2)*y)-(3*pow(a,2));
                fx += bb*2;
            }
            y++;
            fy += aa*2;
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            //SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            }
        
        //REGION II
        if(a>b){
            //d2=(pow(b,2)*pow(x+1.0,2))-(pow(a,2)*pow(y+0.5,2))-(pow(a,2)*pow(b,2));
            while(x<=limite){
                if(d2<=-aa/2){
                      //NE
                    d2+=(2*pow(b,2))*x+(3*pow(b,2))-2*pow(a,2)*y-2*pow(a,2);
                    y++;

                }else{
                    //E
                    d2+=2*pow(b,2)*y+3*pow(b,2);
                }
                y++;
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
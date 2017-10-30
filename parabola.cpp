#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
using namespace std;
int main( int argc, char* args[] ){
   int x,y,d1,d2,p;
    y=0;
    x=0;
   int limite=600;
    cout<<"=PROGRAMA GENERADOR DE PARABOLAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{
        cout<<"Ingrese valor de p (parametro): ";
        cin>>p;
    }while(p>limite); //FALTA SI P ES MENOR QUE 0

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

        d1=pow(x+1.0,2)-4*(p*y+0.5);
        //gradiente de funcion original para region I
        //REGION I I: mientras 2x<-4*p significa que es sigue siendo menor que m=1
        //while(2*x < -4*p){
       while(y < p && x<=limite){
            //cout<<"Entre we R1"<<endl;
            if(d1<=0){
                //E
                d1+=2*x-3;
                x++;
                //y++;
            }else{
                //NE
                d1+=2*x+3-4*p;
                x++;
                y++;
             }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            }
        
        //cout<<"Entre we R2"<<endl;
        //REGION II
        d2=pow(x+0.5,2)-4*(p*(y+1.0));
        while(x<=limite){
            if(d2<=0){
                //NE
                //cout<<"Entre we NE"<<endl;
                d2+=2*x-4*p+2;
                x++;
                y++;
            }else{
                //N
                //cout<<"Entre we N"<<endl;
                d2+=-4*p;
                //x++;
                y++; 
                }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, -y+300);
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
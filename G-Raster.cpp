#include <stdio.h>
#include <SDL2/SDL.h>
#include<iostream>
using namespace std;
void Linea(SDL_Renderer*,int);
void Circunferencia(SDL_Renderer*,int);
void SegundoOrden(SDL_Renderer*,int);
void Elipse(SDL_Renderer*,int);
void Parabola(SDL_Renderer*,int);
void Hiperbole(SDL_Renderer*,int);

int main( int argc, char* args[] ){
    SDL_Event e;
    int tp=600;
    int respuesta; 
         //MENU  
        
        cout<<"PROGRAMA GRAFICAS RASTER"<<endl;
        cout<<"Elija una opcion: "<<endl;
        cout<<"0) Linea"<<endl
            <<"1) Circunferencia"<<endl
            <<"2) Circunferencia por 2do Orden"<<endl
            <<"3) Elipse"<<endl
            <<"4) Parabola"<<endl
            <<"5) Hiperbole"<<endl;
        cout<<"Respuesta: ";
        cin>>respuesta;

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
        
        switch(respuesta){
            case 0:
                Linea(renderer,tp);
                break;
            case 1:
                Circunferencia(renderer,tp);
                break;
            case 2:
                SegundoOrden(renderer,tp);
                break;
            case 3:
                Elipse(renderer,tp);
                break;
            case 4:
                Parabola(renderer,tp);
                break;
            case 5:
                Hiperbole(renderer,tp);
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
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

void Linea(SDL_Renderer* renderer,int tp){
    int X1,Y1,X2,Y2;
    double dY, dX,k,X,Y,av,avR,avI;
    int IncYi,IncXi,IncXr,IncYr;
        
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

}

void Circunferencia(SDL_Renderer* renderer, int tp){
    int X1,Y1,X2,Y2;
    int r;
    double d1,d2,X,Y;

        cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{cout<<"Ingrese valor del radio: ";
        cin>>r;
    }while(r>tp);

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

}

void SegundoOrden(SDL_Renderer*renderer,int tp){
    int d,dE,dSE;
    int r;
    double X,Y;


    cout<<"=PROGRAMA GENERADOR DE CIRCUNFERENCIAS POR SEGUNDO ORDEN="<<endl;
    do{cout<<"Ingrese valor del radio: ";
        cin>>r;
    }while(r>tp);
            //(0,r)
            d=1-r; //valor inicial de d
            dE=3;
            dSE=-2*r+5;

            X=0;
            Y=r;

            while(X<Y){
                X++;
                if(d<0){
                    d +=dE;
                    dE+=2;
                    dSE+=2;
                }else{
                    d+=dSE;
                    dE+=2;
                    dSE+=4;
                    Y--;
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
}

void Elipse(SDL_Renderer* renderer, int tp){
     int X1,Y1,X2,Y2;
    double X,Y,d1,d2;

    cout<<"=PROGRAMA GENERADOR DE ELIPSES A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
do{cout<<"Ingrese valor de X1: ";
cin>>X1;
cout<<"Ingrese valor de Y1: ";
cin>>Y1;
}while(X1>tp and Y1>tp);
//window = SDL_CreateWindow( "Elipse", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    X=0;
    Y=Y1;
    d1=pow(Y1,2)-(pow(X1,2)*Y1) + (pow(X1,2)/4.0); 
    SDL_RenderDrawPoint(renderer, X+300, Y+300);
    SDL_RenderDrawPoint(renderer, -X+300, Y+300);
    SDL_RenderDrawPoint(renderer, X+300, -Y+300);
    SDL_RenderDrawPoint(renderer, -X+300, -Y+300);

    while((pow(X1,2)*(Y-(0.5)))>(pow(Y1,2)*(X+1))){
        if(d1<0){
            d1=d1+pow(Y1,2)*((2*X)+3);
            X=X+1;
        }else{
            d1=d1+pow(Y1,2)*((2*X)+3) + pow(X1,2)*((-2*Y)+2);
            X=X+1;
            Y=Y-1;
        }
        SDL_RenderDrawPoint(renderer, X+300, Y+300);
        SDL_RenderDrawPoint(renderer, -X+300, Y+300);
        SDL_RenderDrawPoint(renderer, X+300, -Y+300);
        SDL_RenderDrawPoint(renderer, -X+300, -Y+300);
    }

    d2=pow(Y1,2)*pow((X+(0.5)),2)+(pow(X1,2)*pow((Y-1),2))-(pow(X1,2)*pow(Y1,2));

    while(Y>0){
        if(d2<0){
            d2=d2+pow(Y1,2)*((2*X)+2) + pow(X1,2)*((-2*Y)+3);
            X=X+1;
            Y=Y-1;
        }else{
            d2=d2+pow(X1,2)*((-2*Y)+3);
            Y=Y-1;
        }
        SDL_RenderDrawPoint(renderer, X+300, Y+300);
        SDL_RenderDrawPoint(renderer, -X+300, Y+300);
        SDL_RenderDrawPoint(renderer, X+300, -Y+300);
        SDL_RenderDrawPoint(renderer, -X+300, -Y+300);
    }
}

void Parabola(SDL_Renderer*renderer,int limite){
       int x,y,d1,d2,p;
    y=0;
    x=0;
    cout<<"=PROGRAMA GENERADOR DE PARABOLAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{
        cout<<"Ingrese valor de p (parametro): ";
        cin>>p;
    }while(p>limite); 

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
            SDL_RenderDrawPoint(renderer, x+300, y+300);
             SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, y+300);
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
            SDL_RenderDrawPoint(renderer, x+300, y+300);
             SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, y+300);
            }
        
}

void Hiperbole(SDL_Renderer*renderer, int limite){
      int x,y;
   double a,b,d1,d2;
   
        /*cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
        do{cout<<"Ingrese valor de a: ";
            cin>>a;
            cout<<"Ingrese valor de b: ";
            cin>>b;
        }while(a>limite and b>limite);*/
        a=150;
        b=100;
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
                d1 += -2*aa*y-3*aa;//-4*aa*(2*y-3);
                
            }else{
                //NE
                x++;
                //CAMBIAR
                d1 = 2*bb*x+2*bb-2*aa*y-3*aa;//d1 + 4*2*bb*(x+1) - 4*aa*( 2*y +3);
            }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, x+300, y+300);
             SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, y+300);
            }
        
        //REGION II
        if(a>b){
            //este 
            d2=(bb*pow(x+1.0,2))-(aa*pow(y+0.5,2))-(aa*bb);
            while(x<=limite){
                x++;
                if(d2>0){
                     //NE
                    y++;
                    d2+=(2*bb*x)+(3*bb)-(3*aa*y)-(2*aa);   
                }else{
                   //E

                    d2+=-2*bb*-3*bb;
                }
            SDL_RenderDrawPoint(renderer, x+300, -y+300);
            SDL_RenderDrawPoint(renderer, x+300, y+300);
             SDL_RenderDrawPoint(renderer, -x+300, -y+300);
            SDL_RenderDrawPoint(renderer, -x+300, y+300);
            }
        }
}
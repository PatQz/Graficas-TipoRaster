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
void pintarSimetrico(SDL_Renderer*renderer, int x, int y);

int main( int argc, char* args[] ){
    SDL_Event e;
    int limite=600;
    int respuesta; 
         //MENU  
        
        cout<<endl<<"PROGRAMA GRAFICAS RASTER"<<endl;
        cout<<"Elija una opcion: "<<endl;
        cout<<"0) Linea"<<endl
            <<"1) Circunferencia"<<endl
            <<"2) Circunferencia por 2do Orden"<<endl
            <<"3) Elipse"<<endl
            <<"4) Parabola"<<endl
            <<"5) Hiperbole"<<endl;
        do{
            cout<<"Respuesta: ";
            cin>>respuesta;
        }while(respuesta<0 || respuesta >5);

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
         
        switch(respuesta){
            case 0:
                Linea(renderer,limite);
                break;
            case 1:
                Circunferencia(renderer,limite);
                break;
            case 2:
                SegundoOrden(renderer,limite);
                break;
            case 3:
                Elipse(renderer,limite);
                break;
            case 4:
                Parabola(renderer,limite);
                break;
            case 5:
                Hiperbole(renderer,limite);
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

void Linea(SDL_Renderer* renderer,int limite){
    int X1,Y1,X2,Y2,aux;
    double dY, dX,k,X,Y,av,avR,avI;
    int IncYi,IncXi,IncXr,IncYr;
        
    cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{
        cout<<"Ingrese valor de X1: "; cin>>X1;
        cout<<"Ingrese valor de Y1: "; cin>>Y1;
        cout<<endl<<"Ingrese valor de X2: "; cin>>X2;
        cout<<"Ingrese valor de Y2: "; cin>>Y2;
    }while(X1>limite || X2>limite || Y1>limite || Y2>limite);

    if(X2 <X1){
        aux=X2;
        X2=X1;
        X1=aux;

        aux=Y2;
        Y2=Y1;
        Y1=aux;
    }

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

void Circunferencia(SDL_Renderer* renderer, int limite){
    int X1,Y1,X2,Y2;
    int r;
    double d1,d2,X,Y;

    cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{
        cout<<"Ingrese valor del radio: ";
        cin>>r;
    }while(r>limite);

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
        pintarSimetrico(renderer,X,Y);
        pintarSimetrico(renderer,Y,X);
    }

}

void SegundoOrden(SDL_Renderer*renderer,int limite){
    int d,dE,dSE;
    int r;
    double X,Y;


    cout<<"=PROGRAMA GENERADOR DE CIRCUNFERENCIAS POR SEGUNDO ORDEN="<<endl;
    do{cout<<"Ingrese valor del radio: ";
        cin>>r;
    }while(r>limite);

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
        pintarSimetrico(renderer,X,Y);
        pintarSimetrico(renderer,Y,X);
     }
}

void Elipse(SDL_Renderer* renderer, int limite){
    int X1,Y1,X2,Y2;
    double X,Y,d1,d2;

    cout<<"=PROGRAMA GENERADOR DE ELIPSES A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{
        cout<<"Ingrese valor de X1: ";
        cin>>X1;
        cout<<"Ingrese valor de Y1: ";
        cin>>Y1;
    }while(X1>limite and Y1>limite);

    X=0;
    Y=Y1;
    d1=pow(Y1,2)-(pow(X1,2)*Y1) + (pow(X1,2)/4.0); 
    pintarSimetrico(renderer,X,Y);

    while((pow(X1,2)*(Y-(0.5)))>(pow(Y1,2)*(X+1))){
        X++;
        if(d1<0){
            d1=d1+pow(Y1,2)*((2*X)+3);
        }else{
            d1=d1+pow(Y1,2)*((2*X)+3) + pow(X1,2)*((-2*Y)+2);
            Y--;
        }
        pintarSimetrico(renderer,X,Y);
    }

    d2=pow(Y1,2)*pow((X+(0.5)),2)+(pow(X1,2)*pow((Y-1),2))-(pow(X1,2)*pow(Y1,2));

    while(Y>0){
        Y--;
        if(d2<0){
            d2=d2+pow(Y1,2)*((2*X)+2) + pow(X1,2)*((-2*Y)+3);
            X++;
        }else{
            d2=d2+pow(X1,2)*((-2*Y)+3);
        }
        pintarSimetrico(renderer,X,Y);
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
    //REGION I
    while(y < p && x<=limite){
       x++;
        if(d1<=0){
            //E
            d1+=2*x-3;
        }else{
            //NE
            d1+=2*x+3-4*p;
            y++;
         }
        pintarSimetrico(renderer,x,y);
    }
        
    //REGION II
    d2=pow(x+0.5,2)-4*(p*(y+1.0));
    while(x<=limite){
        y++;
        if(d2<=0){
            //NE
            d2+=2*x-4*p+2;
            x++;
        }else{
            //N
            d2+=-4*p;   
            }

    pintarSimetrico(renderer,x,y);
    }
        
}

void Hiperbole(SDL_Renderer*renderer, int limite){
    int x,y,a,b,aa,bb;
   double d1,d2;
   
    cout<<"=PROGRAMA GENERADOR DE LINEAS A PARTIR DE ALGORITMO DE PUNTO MEDIO="<<endl;
    do{cout<<"Ingrese valor de a: ";
        cin>>a;
        cout<<"Ingrese valor de b: ";
        cin>>b;
    }while(a>limite and b>limite);
    
    x=a;
    y=0;
    aa = a*a;
    bb = b*b;

    d1=(bb*pow(x+0.5,2))-(aa*pow(y+1.0,2))-(aa*bb);

    //REGION I
    while(x<=limite){
        y++;
        if(d1>0){
            //N
            d1 += -2*aa*y-3*aa;
        }else{
            //NE
            x++;     
            d1 += 2*bb*x+2*bb-2*aa*y-3*aa;
        }
    pintarSimetrico(renderer,x,y);
    }

    //REGION II
    if(b>a){
        d2=(bb*pow(x+1.0,2))-(aa*pow(y+0.5,2))-(aa*bb);
        while(x<=limite){
            x++;
            if(d2>0){
              //NE
                y++;
                d2+=(2*bb*x)+(3*bb)-(3*aa*y)-(2*aa);
            }else{
                //E
                d2+=-2*bb*x-3*bb;
            }
        pintarSimetrico(renderer,x,y);
        }
    }
}

void pintarSimetrico(SDL_Renderer*renderer, int x, int y){
    SDL_RenderDrawPoint(renderer, x+300, -y+300);
    SDL_RenderDrawPoint(renderer, x+300, y+300);
    SDL_RenderDrawPoint(renderer, -x+300, -y+300);
    SDL_RenderDrawPoint(renderer, -x+300, y+300);
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265358979323846264338327
#define EU 2.7182818284590452353602874

//lista de numeros con una distribucion gaussiana 
double funcion(double x);
int main(int argc, char **argv){

  //cambiando la semilla 
  
  int numero=atoi(argv[1]);
  int i;
  double x,shift,xp,y;
  
  double g1,g2;
  double valor=0;
 
  double r;
  
  srand48(numero);
  x=valor;
  
  for(i=0;i<numero;i++){
    
    shift=(drand48()-0.5)/10.0;
    y=drand48();
    
    xp=x+shift;
    
    //comparando r entre 1 y la funcion aleatoria

    if(1>funcion(xp)/funcion(x)){
      r=funcion(xp)/funcion(x);
    }
    else{
      r=1;
    }

    if(r>y){
      x=xp;
    }
    printf("%f\n",x);
    
  } 
  
}
double funcion(double x){
  return exp(-x*x/2.0);
}

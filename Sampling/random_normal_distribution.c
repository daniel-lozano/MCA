#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265358979323846264338327

//lista de numeros con una distribucion gaussiana 

int main(int argc, char **argv){

  //cambiando la semilla 
  int numero=atoi(argv[1]);
  srand48(numero);
  double x,y;
  double g1,g2;
  int i;
  
  for(i=0;i<numero;i++){
    x=drand48();
    y=drand48();
    g1=sqrt(-2.0*log(x))*cos(2*PI*y);
    g2=sqrt(-2.0*log(x))*sin(2*PI*y);
    
    if(g1>5){
      printf("%f %f\n",g1,g2);
      }
  }
}

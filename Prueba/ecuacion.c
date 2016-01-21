#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){
  
  double x_0=1;
  double xp_0=0;
  double Time=2.0*M_PI;
  double x,y=0;

  int i=1;
  int saltos=100;

  double xviejo=0;
  double yviejo=1;
  double y1viejo=0;

  FILE *f;

  printf("X Y\n");

  f=fopen("escrito.dat","w");
  fprintf(f,"%lf %lf\n",xviejo,y1viejo);

  for(i=0;i<saltos;i++){

    double x0=xviejo;
    double y0=yviejo;
    double y1=y1viejo;
   
    
    double xn=x0+Time/saltos;    
    double yn=y0+(Time/saltos)*(-x0);
    // este es el segundo paso de la derivada
    double ym= y1+(Time/saltos)*(yn);

    
   
    xviejo=xn;
    yviejo=yn;
   
    fprintf(f,"%lf %lf\n",xn,ym);
  
  }
   
  printf("imprimiendo\n");
  return 0;


}

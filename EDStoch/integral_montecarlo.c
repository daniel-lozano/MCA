#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void comparar(int *adentro, int *afuera);

int main(int argc, char **argv){
  
  int adentro=0;
  int afuera=0;
  int pasos= atoi(argv[1]);
  //printf("pasos=%i\n",pasos);
  int i,j;
  double x;
  double y;
  double e=2.71;
  double suma=0;

  for(j=0;j<1000;j++){
    suma=0;
    for(i=0;i<pasos;i++){
      x=drand48();//random number between 0 and 1 
    
      suma+=(pow(x,-1/3)+x/10.0)/pasos;
   
    }
    printf("%e\n",suma);

  }
  return 0;

}

void comparar(int *adentro, int *afuera){

}


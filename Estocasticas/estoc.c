#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define PI 3.14159265358979323846264338327

int main(int argv,char **argc){

  int N=atoi(argc[1]);
  int i,j;
  float dt=(float) 1/N;
  float T=1;
  float t=0;
  float *dW;
  float *W;
  float *Exp;
  float a=0;
  float x,y,g1;
  


  W=malloc(sizeof(float)*N);
  dW=malloc(sizeof(float)*N);
  Exp=malloc(sizeof(float)*N);
  for(j=0;j<5;j++){
    t=0;
    a=0;
    srand48(j);
    for(i=0;i<N;i++){
      t+=dt;
      
      //creating random
      
      x=drand48();
      y=drand48();
      
      //filling arrays
      W[i]= a;
      dW[i]=sqrt(dt)*(sqrt(-2.0*log(x))*cos(2*PI*y));
      a+=sqrt(dt)*(sqrt(-2.0*log(x))*cos(2*PI*y));
      Exp[i]=exp(W[i]/2+t);
      
      fprintf(stdout,"%f\n",Exp[i]);
  }
  }


  return 0;
}

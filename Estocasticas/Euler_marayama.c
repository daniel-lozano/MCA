#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define PI 3.14159265358979323846264338327

int main(int argv,char **argc){

  int N=atoi(argc[1]);
  int i,j;
  float dt=1.0/N;
  float T=100;
  float t;
  float *x1;
  float *x2;
  float x10=1;
  float x20=0;
  float g1,g2,g3,g4,random1,random2;
  float alpha=1.0;
  float betha=1.0;
  float dw1,dw2;


  x1=malloc(sizeof(float)*N);
  x2=malloc(sizeof(float)*N);
  x1[0]=x10;
  x2[0]=x20;
 
  for(j=0;j<1;j++){

    t=0;
    
    srand48(j);

    fprintf(stdout,"%f %f %f\n",t,x1[0],x2[0]);

    for(i=1;i<N;i++){

      t+=dt;
      
      //creating random
      
      g1=drand48();
      g2=drand48();
      g3=drand48();
      g4=drand48();

      random1=(sqrt(-2.0*log(g1))*cos(2*PI*g2));
      random2=(sqrt(-2.0*log(g3))*sin(2*PI*g4));
      //filling arrays
      

      dw1=sqrt(dt)*random1;
      dw2=sqrt(dt)*random2;

      x1[i]=x1[i-1]+x2[i-1]*dt+alpha*dw1;
      x2[i]=x2[i-1]-x1[i-1]*dt+betha*dw2;
      
      
      fprintf(stdout,"%f %f %f\n",t,x1[i],x2[i]);
  }
  }


  return 0;
}

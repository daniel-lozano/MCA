#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define PI 3.14159265358979323846264338327


int main(int argv,char **argc){

  int N=atoi(argc[1]);
  int i,j;
  float dt=1.0/N;
  float T=1;
  float t=0;
  float *x1,*x2,*x3,*x4;
  float x10=1;
  float g1,g2,random1;
  float f1,f2,random2;
  float h1,h2,random3;
  float i1,i2,random4;
  float theta=1.0;
  float mu=1.0;
  float sigma=0.1;
  float dw;


  x1=malloc(sizeof(float)*N);
  x1[0]=x10;
  x2=malloc(sizeof(float)*N);
  x2[0]=x10;
  x3=malloc(sizeof(float)*N);
  x3[0]=x10;
  x4=malloc(sizeof(float)*N);
  x4[0]=x10; 
  for(j=0;j<1;j++){

    t=0;
    
    srand48(j);
    fprintf(stdout,"%f %f %f %f %f\n",t,x1[0],x2[0],x3[0],x4[0]);
    for(i=1;i<N;i++){
      t+=dt;
      
      //creating random
      
      g1=drand48();
      g2=drand48();
      f1=drand48();
      f2=drand48();
      h1=drand48();
      h2=drand48();
      i1=drand48();
      i2=drand48();
      
      //filling arrays
      random1=(sqrt(-2.0*log(g1))*cos(2*PI*g2));
      random2=(sqrt(-2.0*log(f1))*cos(2*PI*f2));
      random3=(sqrt(-2.0*log(h1))*cos(2*PI*h2));
      random4=(sqrt(-2.0*log(i1))*cos(2*PI*i2));
     
      dw=random1*sqrt(dt);
      x1[i]=x1[i-1]+theta*(mu-x1[i-1])*dt+sigma*dw;

      dw=random2*sqrt(dt);
      x2[i]=x2[i-1]+theta*(mu-x2[i-1])*dt+sigma*dw;

      dw=random3*sqrt(dt);
      x3[i]=x3[i-1]+theta*(mu-x3[i-1])*dt+sigma*dw;

      dw=random4*sqrt(dt);
      x4[i]=x4[i-1]+theta*(mu-x4[i-1])*dt+sigma*dw;
     
      fprintf(stdout,"%f %f %f %f %f\n",t,x1[i],x2[i],x3[i],x4[i]);
  }
  }


  return 0;
}

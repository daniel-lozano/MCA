#include <stdio.h>
#include <math.h>

int  main(void){
  int pasos=1000;
  int i;
  float dt=1.0/pasos;
  float alpha=20.0;
  float yn;
  float T=0;
  float y0=1.0;
  FILE *f,*g;
  f=fopen("explicit.dat","w");
  fprintf(f,"%e %e\n",T,y0);

  g=fopen("implicit.dat","w");
  fprintf(g,"%e %e\n",T,y0);
   

  //explicit y_{n+1}=y_{n}+y'_{n}*dt
  
  for(i=0;i<pasos;i++){
    
    yn=y0*pow(1-alpha*dt,i);//esta es la forma en que escribimos la deribada
    T=T+dt;
    fprintf(f,"%e %e\n",T,yn);
    

  }

  //implicit y_{n+1}=y_{n}+y'_{n+1}*dt
  T=0;
 for(i=0;i<pasos;i++){
    
    yn=y0*pow(1+alpha*dt,-i);
    T=T+dt;
    fprintf(g,"%e %e\n",T,yn);
    

  }





}

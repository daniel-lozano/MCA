#include <stdio.h>
#include <math.h>

int  main(void){

  int pasos=1000;
  int i;
  float dt=1.0/pasos;
  float yn;

  //Condiciones iniciales

  float T=0;
  float y0=1.0;

  //archivos que seran escritos

  FILE *f;

  //escribiendo primera coordenada, condicion inicial

  f=fopen("RK2.dat","w");
  fprintf(f,"%e %e\n",T,y0);

  //RK2
  //k1=y'(y_{n},t_{n})
  //k2=y'(y_{n}+k1*dt,t_{n+1})
  //y_{n+1}=(k1+k2)*dt/2+y_{n}
  float k1,k2;
  for(i=0;i<pasos;i++){
    //avanza tiempo
    T=T+dt;

    //avanza y
    k1=y0+T*T;
    k2=y0+k1*dt+(T+dt)*(T+dt);
    yn=(k1+k2)*dt/2.0+y0;
    
    fprintf(f,"%e %e\n",T,yn);
    
    y0=yn;
    
    

  }

 
}

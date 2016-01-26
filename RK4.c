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

  f=fopen("RK4.dat","w");
  fprintf(f,"%e %e\n",T,y0);

  //RK2
  //k1=y'(y_{n},t_{n})
  //k2=y'(y_{n}+k1*dt,t_{n+1})
  //y_{n+1}=(k1+k2)*dt/2+y_{n}

  float k1,k2,k3,k4;

  for(i=0;i<pasos;i++){
    //avanza tiempo
    T=T+dt;

    //avanza y, aqui sabemos que la derivada esta definida como y'=y+t*t

    k1=y0+T*T; //y'(y0,t0)

    k2=y0+k1*dt/2+(T+dt/2)*(T+dt/2); //y'(y0+k1*dt/2,t0+dt/2)

    k3=y0+k2*dt/2+(T+dt/2)*(T+dt/2);//y'(y0+k2*dt/2,t0+dt/2)

    k4=y0+k3*dt+(T+dt)*(T+dt);//y'(y0+k3*dt,t0+dt)

    yn=(k1+2*k2+2*k3+k4)*dt/6.0+y0;
    
    fprintf(f,"%e %e\n",T,yn);
    
    y0=yn;
    
    

  }

  return 0;
}

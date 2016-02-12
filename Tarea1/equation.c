#include <stdio.h>
#include <math.h>

void RK4(double dt,double *y, double *v);
double vprime(double dt, double y, double v);
double yprime(double dt, double y, double v);

int  main(void){

  double Tm=pow(10,2);
  double dt=0.1;

  //Condiciones iniciales

  double T=0;
  double y0=0.0;
  double v0=1.0;
  FILE *f;
  f=fopen("osc.dat","w");

  //escribiendo primera coordenada, condicion inicial

  
  fprintf(f,"%e %e %e\n",T,y0,v0);

  
 

  while(T<Tm){

    //avanza tiempo

    T=T+dt;
    RK4(dt,&y0,&v0);
    fprintf(f,"%e  %e\n",T,y0);
   
  }

  return 0;
}

void RK4(double dt,double *y, double *v){

  double k1,k2,k3,k4;
  double l1,l2,l3,l4;
  double yin=*y;
  double vin=*v;
 
  k1=yprime(dt,yin,vin); //k1 es para y'=v
  l1=vprime(dt,yin,vin);//l1 es para v'=-y
  
  k2=yprime(dt,yin+k1*dt/2,vin+l1*dt/2);
  l2=vprime(dt,yin+k1*dt/2,vin+l1*dt/2);
  
  k3=yprime(dt,yin+k2*dt/2,vin+l2*dt/2);
  l3=vprime(dt,yin+k2*dt/2,vin+l2*dt/2);
  
  k4=yprime(dt,yin+k3*dt/2,vin+l3*dt);//y'(y0+k3*dt,t0+dt)
  l4=vprime(dt,yin+k3*dt,vin+dt*l3);
  
  yin+=(k1+2*k2+2*k3+k4)*dt/6.0;
  vin+=(l1+2*l2+2*l3+l4)*dt/6.0;
  *y=yin;
  *v=vin;
  
}

double vprime(double dt, double y, double v){
  return -y;
}
double yprime(double dt, double y, double v){
  return v;
}

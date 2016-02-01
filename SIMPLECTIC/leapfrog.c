#include <stdio.h>
#include <math.h>

void leap_frog(double dt,double *y, double *v);
double vprime(double dt, double y, double v);
double yprime(double dt, double y, double v);

int  main(void){

  double Tm=pow(10,2);
  double dt=0.01;

  //Condiciones iniciales

  double T=0;
  double y0=0.0;
  double v0=1.0;
  FILE *f,*g;
  f=fopen("osc_y.dat","w");
  g=fopen("osc_v.dat","w");

  //escribiendo primera coordenada, condicion inicial

  
  fprintf(f,"%e %e\n",T,y0);
  fprintf(g,"%e %e\n",T,v0);
  
 

  while(T<Tm){

    //avanza tiempo

    T=T+dt;
    leap_frog(dt,&y0,&v0);
    fprintf(f,"%e  %e\n",T,y0);
    fprintf(g,"%e  %e\n",T,v0);
  }

  return 0;
}

void leap_frog(double dt,double *y, double *v){
  double yin=*y;
  double vin=*v;

  /*kick*/
  vin+=0.5*vprime(dt,yin,vin)*dt;
  /*drift*/
  yin+=-1.0*vin*dt/24;
  /*kick*/
  vin+=-2*vprime(dt,yin,vin)*dt/3;
  /*drift*/
  yin+=3.0*vin*dt/4;
  /*kick*/
  vin+=2*vprime(dt,yin,vin)*dt/3;
  /*drift*/
  yin+=7.0*vin*dt/24;

  *v=vin;
  *y=yin;

}


double vprime(double dt, double y, double v){
  return -y;
}
double yprime(double dt, double y, double v){
  return v;
}

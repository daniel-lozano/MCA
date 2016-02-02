#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void inicializa(double *x_past,float dx, float dt,float nx,float nt);
void copia(double *x_past,double *x_present, float nx);
void actualiza(double *x_past,double *x_present,float dx, float dt,float nx,float nt,float c,float v);

int  main(void){

  float dt=0.1;
  float dx=0.1;
  float v=dx/dt;
  float T=10;
  float X=10;
  float c=1;
  float nx=X/dx;
  float nt=T/dt;
 
  int i;

  //punteros

  double *x_present;
  double *x_past;

  //allocanco memoria
  x_past=malloc(sizeof(double)*nx);
  x_present=malloc(sizeof(double)*nx);

  //Condicion inicial

  inicializa(x_past,dx,dt,nx,nt);


  for(i=0;i<nt;i++){
    
    actualiza(x_past,x_present,dx,dt,nx,nt,c,v);

    copia(x_past,x_present,nx);
  } 
  
  float x=0;
  for(i=0;i<nx;i++){
    x+=dx;
    printf("%e %e \n",x,x_present[i]);
  }
  
  


  
 
  return 0;
}
void inicializa(double *x_past,float dx, float dt,float nx,float nt){
  int i;
  float x=0;
  
  for(i=0;i<=nx;i++){
    x+=dx;
    if(i<=nx/2){
      x_past[i]=1;
    }
    if(i>nx/2){
      x_past[i]=0;
    }
    // printf("%e %e \n",x,x_past[i]);
  }
 

}

void copia(double *x_past,double *x_present, float nx){

  int i;
  for(i=0;i<nx;i++){
    x_past[i]=x_present[i];
  }


}

void actualiza(double *x_past,double *x_present,float dx, float dt,float nx,float nt,float c,float v){
  int i;
  for(i=1;i<(nx-1);i++){

    x_present[i]=x_past[i]-c*(x_past[i]-x_past[i-1])/(2*v);
  }

}

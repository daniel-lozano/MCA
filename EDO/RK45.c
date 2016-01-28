#include <stdio.h>
#include <math.h>

typedef double (*derivative)(double t, double y);
double func_y(double t, double y);
double exact_sol_y(double t);

int main(void){

  double y_RK45;
  double t;
  int i;

  double T=2.0;
  double step=1E-2;
  int n_step = (int)(T/step);

  t=0.0;
  y_RK45=1.0;

  double k1, k2, k3, k4,k5,k6,k7;
  double w1,w2,R;
  double y_step;
  double epsilon=0.00001;

  for(i=0;i<n_step;i++){   
    
    derivative dev=func_y;
    double y=y_RK45;
    k1 = step*dev(t,y);
    k2 = step*dev(t + step/4, y + k1/4);
    k3 = step*dev(t + 3*step/8.0 , y + k1*3/32 +9*k2/32);
    k4 = step*dev(t + 12*step/13, y + 1932*k1/2197-7200*k2/2197+7296*k3/2197);
    k5 = step*dev(t+step, y+439*k1/216-8*k2+3680*k3/513-845*k4/4104);
    k6 = step*dev(t+step/2, y-8*k1/27+2*k2-3544*k3/2565+1859*k4/4104-11*k5/40);

    w1 = y + 25*k1/216+1408*k3/2565+2197*k4/4104-k5/5;
    w2 = y + 16*k1/135+6656*k3/12825+28561*k4/56430-9*k5/50+2*k6/55;
    R = fabs(w1-w2)/step;

    double delta = 0.84*pow(epsilon/R,1/4);

    if(R<=epsilon){
      
      y_RK45+=w1-y;
       t += step;
       step=step*delta;
       printf("%f %.15e %.15e\n", t, exact_sol_y(t), y_RK45);
    }
    
    else{
      i=i-1;
      step=step*delta;
    }    
    
  }
  
  return 0;
}



double func_y(double t, double y){
  double v;
  v = y + t*t ;
  return v;
}

double exact_sol_y(double t){
  return 3.0*exp(t) - t*t -2*t -2;
}


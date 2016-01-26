#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int arg, char **argc){

  unsigned int id;
  int min;
  float x,p1,p2;
  int a,i;
  float dife;
  FILE *f;


  
  f=fopen("diferencia.dat","w");

  min = atoi(argc[1]);

  for(i=1;i<=min;i++){
    a=pow(10,i);

    for (id=a;id<=a+2;id++){
      
      x = (*(float*)&id);
      if(id==a+1){	
	p1=x;
      }
      if(id==a+2){
	p2=x;
      }
    }
    dife= p2-p1;
    //printf("p1=%.20e\n", p1);
    //printf("p2=%.20e\n", p2);
    //printf("dife=%.20e\n", dife);

    fprintf(f,"%.20e %.20e\n",p1,dife);
    
  }
 
  return 0;
}

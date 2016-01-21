#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){

  //RECORDANDO C----------------

  char a=85;
  char b=5;
  int c=a*b;
  //char c=a*b; se devuelve si es asi ya que no cabe el numero! da un numero negativo

  printf("%d\n",c);
  
  //MIRANDO LAS VARIABLES ---------------
  int A=2000000000;
  int B=3;
  long long C= A*((long long) B);
  // al hacer este "cast" lo que se logra es para hacerle entender a C: que esta variable sera llamada asi de no hacerlo los resultados no seran concluyentes 
  printf("%lld\n",C);// lld es la sigla para <long long >

 
  return 0;
  
}

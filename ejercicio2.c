#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>

void* potencia(void *arguments){
  double * vec=(double *)arguments;
  double numpow=0;
  double num=0;
  
  numpow=vec[0];
  num=vec[1];
  double i=0;
  double aux=0;
  double result=2;
  while(result<num){
    aux=result;
    result=pow(numpow,i);
    i++;
  }
  if( (num-aux) > ((num-result)*-1) ){
    printf("La potencia de %lf mas cercana a %lf es %lf \n",numpow,num,result);
  }else{
    printf("La potencia de %lf mas cercana a %lf es %lf \n",numpow,num,aux);
  }
}
int main(int argc, char *argv[])
{
  pthread_t threads[4];
  double numero=0;
  printf("Ingrese un numero:");
  scanf("%lf",&numero);
  double vec[2];
  double vec1[2];
  double vec2[2];
  double vec3[2];
  vec[0]=2;
  vec[1]=numero;
  vec1[0]=3;
  vec1[1]=numero;
  vec2[0]=5;
  vec2[1]=numero;
  vec3[0]=7;
  vec3[1]=numero;

  pthread_create(&threads[0],NULL,potencia,&vec);
  pthread_create(&threads[1],NULL,potencia,&vec1);
  pthread_create(&threads[2],NULL,potencia,&vec2);
  pthread_create(&threads[3],NULL,potencia,&vec3);
  
  pthread_join(threads[0],NULL); 
  pthread_join(threads[1],NULL); 
  pthread_join(threads[2],NULL); 
  pthread_join(threads[3],NULL); 
  
  return 0;
}

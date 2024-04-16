#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>

void *perform_work(void *arguments){
  char hola = *((char *)arguments);
  printf("Soy el hilo %d \n",pthread_self());
}

int main(int argc, char *argv[])
{

  pthread_t threads[6];
  char hola='h';
  int result_code=0;

  result_code=pthread_create(&threads[0],NULL,perform_work,&hola);

  result_code=pthread_create(&threads[1],NULL,perform_work,&hola);

  result_code=pthread_create(&threads[2],NULL,perform_work,&hola);

  result_code = pthread_join(threads[0],NULL);
  result_code = pthread_join(threads[1],NULL);
  result_code = pthread_join(threads[2],NULL);
  printf("EN proceso\n");
  result_code=pthread_create(&threads[3],NULL,perform_work,&hola);
  result_code=pthread_create(&threads[4],NULL,perform_work,&hola);
  result_code=pthread_create(&threads[5],NULL,perform_work,&hola);

  result_code = pthread_join(threads[3],NULL);
  result_code = pthread_join(threads[4],NULL);
  result_code = pthread_join(threads[5],NULL);
  printf("Fin\n");
  return 0;
}

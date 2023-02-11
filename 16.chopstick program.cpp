#include<stdio.h>

#include<pthread.h>

#include<semaphore.h>



sem_t chopstick[5];



void *eat(void *arg){

  int i = int (arg);

  int n_eat=3;

  while(n_eat){

    sem_wait(&chopstick[i]);

    sem_wait(&chopstick[(i+1)%5]);

    printf("Philosopher %d is eating \n", i);

     n_eat--;

    

    sem_post(&chopstick[i]);

    sem_post(&chopstick[(i+1)%5]);

    printf("Philosopher %d is thinking \n", i);

    

  }

  return 0;

}



int main(){

  pthread_t philosopher[5];

  int i;

  for(i=0; i<5; i++){

      sem_init(&chopstick[i],0,1);
  }



  for(i=0; i<5; i++){

      pthread_create(&philosopher[i], NULL, eat,(void*)i);
  }



  for(i=0; i<5; i++){

      pthread_join(philosopher[i], NULL);

  }

  return 0;

}

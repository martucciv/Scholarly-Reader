#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100000
#define MAXPAGE 100000000000

void fillArray(long long val[], int length, long long max){

  int i;
  for (i=0; i<length; i++)
      val[i] = rand() % MAXPAGE;
}

void printArray(long long val[], int length){

  int i;
  for (i=0; i<length; i++){
    printf("%lld ", val[i]);
  }
  printf("\n");
}

int main(){

  long long *val;
  val = (long long*)(malloc(sizeof(long long)*SIZE));
  srand(time(NULL));

  fillArray(val, SIZE, MAXPAGE);

  printArray(val, SIZE);

  free(val);

  return 0;
}

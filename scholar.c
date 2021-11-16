//Veronica Martucci
//COP3502 Fall 2021
//P4: Scholarly Reader
#include <stdio.h>
#include <stdlib.h>

//This function takes the partly sorted array and sorts the entire array
//in non-descending order
void merge(long long arr[], int low, int mid, int high){

  int length = high - low + 1;

  long long *temp = (long long*)calloc(length, sizeof(long long));

  //count1 and count2 holds the indexes to the two sorted lists
  int count1 = low;
  int count2 = mid;
  //mc keeps track of our incdex into our auxiliary array
  int mc = 0;

  while((count1 < mid) || (count2 <= high)){

    if(count2 > high || (count1 < mid && arr[count1] < arr[count2])){
      temp[mc] = arr[count1];
      count1++;
      mc++;
    }
    else{
      temp[mc] = arr[count2];
      count2++;
      mc++;
    }
  }

  for(int i = low; i <= high; i++){
    arr[i] = temp[i - low];
  }

 free(temp);
}

//This function sorts the array using merge sort
void mergeSort(long long arr[], int low, int high){

  int mid;

  if(low < high){

    mid = (low + high) / 2;

    //Sort first half of array
    mergeSort(arr, low, mid);
    //Sort second half of array
    mergeSort(arr, mid + 1, high);
    //merge both halves of the array into one.
    merge(arr, low, mid + 1, high);
  }
}

//This function checks to make sure the array is sorted. if the array
//is not sorted it returns 0 (false), else it returns 1 (true).
int isSorted(long long arr[], int length){

  for(int i = 0; i < length - 1; i++){
    if(arr[i] > arr[i + 1]){
      return 0;
    }
  }

  return 1;
}

//This function calculates the highest number of books that can be read
//without exceeding the number of pages to be read
int calculateNumBooks(long long arr[], int maxPages, int books){

  int numBooks = 0;
  int currPage = 0;

  for(int i = 0; i < books; i++){

    if((currPage += arr[i]) <= maxPages){
        numBooks++;
    }
  }

  return numBooks;
}

int main(){

  int cases;
  scanf("%d\n", &cases);

  for(int i = 0; i < cases; i++){

      int books, maxPages;
      scanf("%d %d", &books, &maxPages);

      long long *arr = (long long*)malloc(books *sizeof(long long));

      for(int j = 0; j < books; j++){
        scanf("%lld", &arr[j]);
      }

      mergeSort(arr, 0, books - 1);

      int totalBooks = 0;

      if(isSorted(arr, books)){

       totalBooks = calculateNumBooks(arr, maxPages, books);
       printf("%d\n", totalBooks);
      }

      free(arr);
  }

  return 0;
}

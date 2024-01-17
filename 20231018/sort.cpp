#include<stdio.h>
#include<iostream>

using namespace std;

void swap (int *x, int *y) {
  int temp;    

  temp = *x;
  *x = *y;
  *y = temp;
}

void insertion_sort (int array[], int array_size) {
  int i, j;

  for (i = 1; i < array_size; i++) 
  {   
    j = i;
    while ((j > 0) && (array[j-1] > array[j])) 
    {  
      swap(&array[j-1], &array[j]); 
      j--;
    }
  }
}

int main (void) {
  int array[10] = { 1, 9, 3, 2, 5, 7, 4, 6, 8, 0 };
  int i;

  for (i = 0; i < 10; i++) 
  { 
    cout << array[i];
  }
  
  cout << endl;

  insertion_sort(array, 10);

  for (i = 0; i < 10; i++) 
  { 
    cout << array[i]; 
  }
  
  cout << endl;

  return 0;
}

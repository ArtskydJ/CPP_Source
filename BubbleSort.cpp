//Bubble Swap
//2013-03-14

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NumOfElements 20000
//#define NEWSWAP


void randomize(int arr[])
  {
  srand (time(NULL));
  for (int i=0; i<NumOfElements; i++)
    {
    arr[i]=rand()%1000;
    }
  }


#ifdef NEWSWAP
  void swap(int &x, int &y)
    {
    x ^= y;
    y ^= x;
    x ^= y;
    }
  /*
  Time:
  2.516
  2.526
  2.495
  2.519
  2.519
  */
#else
  void swap(int &x, int &y)
    {
    int tmp = x;
    x = y;
    y = tmp;
    }
  /*
  Time:
  2.180
  2.188
  2.193
  2.184
  2.188
  */
#endif


void iterate(int arr[], int n)
  {
  for (int i=0; i<n; i++)
    {
    std::cout<<i<<"\t"<<arr[i]<<"\n";
    }
  std::cout<<"\n";
  }


void bubbleSort(int arr[], int n)
  {
  bool swapped = true;
  int j = 0;
  while (swapped)
    {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i++)
      {
      if (arr[i] > arr[i+1])
        {
        swap(arr[i], arr[i+1]);
        swapped = true;
  } } } }


int main()
  {
  int array[NumOfElements];
  randomize(array);
  //iterate(array,NumOfElements);
  bubbleSort(array,NumOfElements);
  //iterate(array,NumOfElements);
  return 0;
  }

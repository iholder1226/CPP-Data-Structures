/*
ComSc-210 Data Structures Lab9
   main.cpp
   Purpose: This program tests Heap ATD objects using different implementations.
            The implementations are as follows:
				1. Array implementation
                2. STL implementation
   @author  Isaiah Holder
   @version 11-24-2010*/
#include"Array_Heap.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace::std;

int main(){
  //Declare array based heap object
  Array_Heap<int> heap;
  //Declare an array of unordered integers to test the heap object
  int arraySize = 10;
  int testInput[]={5,4,2,3,1,8,6,7,9,10};
  //Add test values to heap structure
  heap.elements = new int[10];
  heap.length = 0;
  for(int i = 0; i < arraySize;i++){
	heap.length++;
	heap.elements[heap.length-1] = testInput[i];
	heap.ReHeapUp(0,heap.length-1);
  }
  //Print values stored on the heap structure
  cout << "ARRAY HEAP" << endl;
  for(int i = 0; i < arraySize; i++){
	cout << heap.elements[0] << endl;
	heap.elements[0] = heap.elements[heap.length-1];
	heap.length--;
	heap.ReHeapDown(0,heap.length-1);
  }


//***************************************** STL heap implementation  ****************************************
  
  //Declare a vecor to hold the test values.
  vector<int> heap2(testInput,testInput + arraySize);

  //Call the make heap function passing the vector's begining and ending values as parameters
  make_heap(heap2.begin(),heap2.end());

  //Print the values stored on the heap structure
  cout << endl << "STL HEAP" << endl;
  while(!heap2.empty()){
	cout << heap2.front() << endl;
	pop_heap(heap2.begin(),heap2.end());
	heap2.pop_back();
  }
  system("pause");
  return 0;
}
/*
   ComSc-210 Data Structures Lab9
   main.cpp
   Purpose: This program tests Priority Queue ATD objects using different implementations.
            The implementations are as follows:
				1. Array implementation
				2. Pointer implementation
                3. STL implementation
   @author  Isaiah Holder
   @version 11-24-2010
*/
#include<iostream>
using namespace::std;
#include"Array_PQueue.h"
#include"Pointer_PQueue.h"
#include<queue>

int main(){
  cout << "Array based Priority Queue: Priority Given To Higher Values" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Based Priority Queue 
  Array_PQueue<int> queue1(6);
 
  //Call isEmpty to test positive case
  cout << "IsEmpty/true                void                         ";
  if(queue1.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Push index values from a for loop into the stack
  cout << "Enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue1.Enqueue(i,queue1.GetLength());
	  cout << i << " ";
  }
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "IsEmpty/false               void                         ";
  if(queue1.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Denqueue and print queue values
  try{	 
	  cout << "Dequeue and print           void                         ";
	  while(!queue1.IsEmpty()){
		  cout << queue1.Dequeue() << " ";
	  }
	  cout << endl;
  }
  catch(EmptyQueue ex){
    cerr << endl << "EmptyQueue exception thrown" << endl;
  }

  //Enqueue index values from a for loop into the stack
  cout << "Enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue1.Enqueue(i,queue1.GetLength());
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call isFull to test positive case
  cout <<"IsFull/true                 void                         ";
  if(queue1.IsFull())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Call makeEmpty
  cout << "MakeEmpty                   void                         void" << endl;
  queue1.MakeEmpty();

  //Call isEmpty to test makeEmpty
  cout << "IsEmpty/true                void                         ";
  if(queue1.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  system("pause");

//*********************************Pointer Queue *****************************************

   system("cls");
  cout << "Pointer Based Priority Queue: Priority Given To Higher Values" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Queue 
  Pointer_PQueue<int> queue2;
 
  //Call isEmpty to test positive case
  cout << "IsEmpty/true                void                         ";
  if(queue2.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Enqueue index values from a for loop into the stack
  cout << "Enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue2.Enqueue(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "IsEmpty/false               void                         ";
  if(queue2.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Dequeue and print queue values
 try{	 
	  cout << "Dequeue and print           void                         ";
	  while(!queue2.IsEmpty()){
		  cout << queue2.Dequeue() << " ";
	  }
	  cout << endl;
  }
  catch(EmptyQueue ex){
    cerr << endl << "EmptyQueue exception thrown" << endl;
  }
  //Enqueue index values from a for loop into the stack
  cout << "Enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue2.Enqueue(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call makeEmpty
  cout << "MakeEmpty                   void                         void" << endl;
  queue2.MakeEmpty();

  //Call isEmpty to test makeEmpty
  cout << "IsEmpty/true                void                         ";
  if(queue2.IsEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  system("pause");

 //******************************************STL Queue *****************************************************************
  system("cls");
  cout << "STL Based Priority Queue: Priority Given To Higher Values" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Queue 
  priority_queue<int> queue3;
 
  //Call isEmpty to test positive case
  cout << "empty/true                 void                          ";
  if(queue3.empty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Enqueue index values from a for loop into the stack
  cout << "push                      ";
  for(int i = 1; i < 6; i++){
	  queue3.push(i);
	  cout << i << " ";
  }
  cout << "                     void" << endl;

 //Call empty to test negitive case
  cout << "empty/false                void                          ";
  if(queue3.empty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Dequeue and print queue values
  try{	 
	  cout << "pop and print              void                        ";
	  while(!queue3.empty()){
		  cout << queue3.top() << " ";
		  queue3.pop();
	  }
	  cout << endl;
  }
  catch(EmptyQueue ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  system("pause");

  return 0;
}
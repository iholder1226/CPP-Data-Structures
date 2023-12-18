//Isaiah Holder
//Lab-5
#include"ArrayStack.h"
#include"PointerStack.h"
#include"ArrayQueue.h"
#include"PointerQueue.h"
#include<iostream>
#include<stack>
#include<queue>
using namespace::std;


int main(){
  //***********************************Array Stack ***************************************

  cout << "Array based stack:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare array base stack object with a maximum size of 5
  ArrayStack stack1(5);

  //Call isEmpty to test positive case
  cout << "isEmpty/true                void                         ";
  if(stack1.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Call isFull to test negitive case
  cout <<"isFull/false                void                         ";
  if(stack1.isFull())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Push index values from a for loop into the stack
  cout << "push                        ";
  for(int i = 1; i < 6; i++){
	  stack1.push(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call isEmpty to test negitive case
  cout << "isEmpty/false               void                         ";
  if(stack1.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Top, pop and print stack values
  try{	 
	  cout << "top,pop and print           void                         ";
	  while(!stack1.isEmpty()){
	    cout << stack1.getTop() << " ";
        stack1.pop();
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  //Push index values from a for loop into the stack
  cout << "push                        ";
  for(int i = 1; i < 6; i++){
	  stack1.push(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call isFull to test positive case
  cout <<"isFull/true                 void                         ";
  if(stack1.isFull())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  system("pause");  

//************************************Linked Stack*******************************************

  //Test pointer based stack
  system("cls");
  cout << "Pointer based stack:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare PointerStack object
  PointerStack stack2;

  //Call isEmpty to test positive case
  cout << "isEmpty/true                void                         ";
  if(stack2.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Call isFull to test negitive case
  cout <<"isFull/false                void                         ";
  if(stack2.isFull())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Push index values from a for loop into the stack
  cout << "push                        ";
  for(int i = 1; i < 6; i++){
	  stack2.push(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call isEmpty to test negitive case
  cout << "isEmpty/false               void                         ";
  if(stack2.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Top, pop and print stack values
  try{	 
	  cout << "top,pop and print           void                         ";
	  while(!stack2.isEmpty()){
	    cout << stack2.getTop() << " ";
        stack2.pop();
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }
  system("pause");  

  //******************************STL Stack *********************************************
  //Test STL based stack
  system("cls");
  cout << "STL based stack:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare STL stack object
  stack<int> stack3;

  //Call isEmpty to test positive case
  cout << "empty/true                  void                         ";
  if(stack3.empty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Push index values from a for loop into the stack
  cout << "push                        ";
  for(int i = 1; i < 6; i++){
	  stack3.push(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "empty/false                 void                         ";
  if(stack3.empty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Top, pop and print stack values
  try{	 
	  cout << "top,pop and print           void                         ";
	  while(!stack3.empty()){
		  cout << stack3.top() << " ";
        stack3.pop();
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  system("pause");


  //******************************Array Queue *********************************************
  
  system("cls");
  cout << "Array based Queue:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Queue 
  ArrayQueue queue1(5);
 
  //Call isEmpty to test positive case
  cout << "isEmpty/true                void                         ";
  if(queue1.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Push index values from a for loop into the stack
  cout << "enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue1.enqueue(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "isEmpty/false               void                         ";
  if(queue1.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Denqueue and print queue values
  try{	 
	  cout << "Dequeue and print           void                         ";
	  while(!queue1.isEmpty()){
		  cout << queue1.dequeue() << " ";
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  //Enqueue index values from a for loop into the stack
  cout << "Enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue1.enqueue(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

  //Call isFull to test positive case
  cout <<"isFull/true                 void                         ";
  if(queue1.isFull())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Call makeEmpty
  cout << "makeEmpty                   void                         void" << endl;
  queue1.makeEmpty();

  //Call isEmpty to test makeEmpty
  cout << "isEmpty/true                void                         ";
  if(queue1.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  system("pause");

//*********************************Pointer Queue *****************************************

   system("cls");
  cout << "Pointer based Queue:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Queue 
  PointerQueue queue2;
 
  //Call isEmpty to test positive case
  cout << "isEmpty/true                void                         ";
  if(queue2.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;

  //Enqueue index values from a for loop into the stack
  cout << "enqueue                     ";
  for(int i = 1; i < 6; i++){
	  queue2.enqueue(i);
	  cout << i << " ";
  }
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "isEmpty/false               void                         ";
  if(queue2.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Denqueue and print queue values
  try{	 
	  cout << "dequeue and print           void                         ";
	  while(!queue2.isEmpty()){
		  cout << queue2.dequeue() << " ";
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  //Call makeEmpty
  cout << "makeEmpty                   void                         void" << endl;
  queue2.makeEmpty();

  //Call isEmpty to test makeEmpty
  cout << "isEmpty/true                void                         ";
  if(queue2.isEmpty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  system("pause");

  //******************************************STL Queue *****************************************************************
  system("cls");
  cout << "STL based Queue:" << endl;
  cout << "---------------------------------------------------------------------"<< endl;
  cout << "Opertation                 Input                         Output" << endl;
  cout << "---------------------------------------------------------------------"<< endl;

  //Declare Array Queue 
  queue<int> queue3;
 
  //Call isEmpty to test positive case
  cout << "empty/true                void                         ";
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
  cout << "                   void" << endl;

 //Call empty to test negitive case
  cout << "empty/false               void                         ";
  if(queue3.empty())
	cout << "true";
  else
	cout << "false";
  cout << endl;
  
  //Dequeue and print queue values
  try{	 
	  cout << "pop and print             void                         ";
	  while(!queue3.empty()){
		  cout << queue3.front() << " ";
		  queue3.pop();
	  }
	  cout << endl;
  }
  catch(EmptyStack ex){
    cerr << endl << "EmptyStack exception thrown" << endl;
  }

  system("pause");

  return 0;
}
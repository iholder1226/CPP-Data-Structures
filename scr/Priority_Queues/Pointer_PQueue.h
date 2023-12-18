/* 
   ComSc-210 Data Structures
   Pointer_PQueue.h
   ADT:Priority Queue, Templetized
   @author  Isaiah Holder
   @version 11-24-2010
*/

#ifndef _PointerPQ
#define _PointerPQ
#endif
#include"Errors.h"
//Struct Definition for linked priority queue
template<class type>
struct node{
   type value;
   node* nextPtr;
   node* prevPtr;
};
template<class type>
class Pointer_PQueue{
public:
    Pointer_PQueue(void);
    ~Pointer_PQueue(void);
    void MakeEmpty(void);
    bool IsEmpty(void);
    bool IsFull(void);
    void Enqueue(type);
    type Dequeue(void);
    int GetLength(void);
    void Print(void);
private:
	node<type>* currentItem;
	node<type>* headPtr; 
	node<type>* prevPtr;
	int length;
};

template<class type>
Pointer_PQueue<type>::Pointer_PQueue(void){
  headPtr = NULL;
  prevPtr = NULL;
  length = 0;
  currentItem = headPtr;
}
template<class type>
Pointer_PQueue<type>::~Pointer_PQueue(void){
  node<type>* temp;
  if(IsEmpty()){
    delete headPtr;
  }
  else{
    while(headPtr->nextPtr != NULL){
      temp = headPtr;
      headPtr = headPtr->nextPtr;
      delete temp;
    }
    delete headPtr;
  }
}
template<class type>
void Pointer_PQueue<type>::MakeEmpty(void){
  node<type>* temp;
  while(headPtr != NULL){
      temp = headPtr;
      headPtr = headPtr->nextPtr;
      delete temp;
  }
  prevPtr = NULL;
  length = 0;
  currentItem = headPtr;
}
template<class type>
bool Pointer_PQueue<type>::IsEmpty(void){
  return length == 0;
}
template<class type>
bool Pointer_PQueue<type>::IsFull(void){
  node<type>* testNode;
  try{
    testNode = new node<type>;
	return false;
  }
  catch(std::bad_alloc){
     return true;
  }
}
template<class type>
void Pointer_PQueue<type>::Enqueue(type newItem){
	try{
		if(IsFull()){
          throw FullQueue();
	    }
	}
	catch(FullQueue()){
        cout << "Queue is full!" << endl;
		return;
	}
	if(IsEmpty()){
		headPtr = new node<type>;
		headPtr->value = newItem;
		headPtr->nextPtr = NULL;
		headPtr->prevPtr = NULL;
		currentItem = headPtr;
		length++;
		return;
	}
	node<type>* newNode;
	while(newItem < currentItem->value && currentItem->nextPtr != NULL){
		prevPtr = currentItem;
		currentItem = currentItem->nextPtr;
	}
	if(currentItem->nextPtr == NULL){
		newNode = new node<type>;
		if(currentItem->value > newItem){
		  newNode->value = newItem;
		  newNode->prevPtr = currentItem;
		  newNode->nextPtr = currentItem->nextPtr;
		  currentItem->nextPtr = newNode;
		  currentItem = headPtr;
		  length++;
		}
		else{
          newNode->value = newItem;
		  newNode->prevPtr = currentItem->prevPtr;
		  if(prevPtr == NULL){
              newNode->nextPtr = currentItem;
	          currentItem->prevPtr = newNode;
		      headPtr = newNode;
	      }
	      else{
	          currentItem->prevPtr->nextPtr = newNode;
	          newNode->nextPtr = currentItem;
	          currentItem->prevPtr = newNode;
	      }
	      currentItem = headPtr;
	      length++;
	   }
	}
	else{
      newNode = new node<type>;
	  newNode->value = newItem;
	  newNode->prevPtr = currentItem->prevPtr;
	  if(prevPtr == NULL){
          newNode->nextPtr = currentItem;
	      currentItem->prevPtr = newNode;
		  headPtr = newNode;
	  }
	  else{
	      currentItem->prevPtr->nextPtr = newNode;
	      newNode->nextPtr = currentItem;
	      currentItem->prevPtr = newNode;
	  }
	  currentItem = headPtr;
	  length++;
	}
}
template<class type>
type Pointer_PQueue<type>::Dequeue(void){
	type value = headPtr->value;
	node<type>* temp = headPtr;
	headPtr = headPtr->nextPtr;
	length--;
	delete temp;
	return value;
}
template<class type>
int Pointer_PQueue<type>::GetLength(void){
    return length;
}
template<class type>
void Pointer_PQueue<type>::Print(void){
	while(currentItem->nextPtr != NULL){
       cout << currentItem->value << endl;
	   currentItem = currentItem->nextPtr;
	}
	cout << currentItem->value << endl;
	currentItem = headPtr;
}
//Isaiah Holder
#include"PointerQueue.h"
#include<cstddef>
#include<new>

struct node{
  int value;
  node* next;
};

PointerQueue::PointerQueue(void){
  front = NULL;
  rear = NULL;
}
PointerQueue:: ~PointerQueue(void){
  makeEmpty();
}
void PointerQueue::makeEmpty(){
  node* temp;
  while(front != NULL){
    temp = front;
	front = front->next;
	delete temp;
  }
}
void PointerQueue::enqueue(int item){
  if(isFull())
	  throw FullQueue();
  else{
	  node* newNode;
	  newNode = new node;
	  newNode->value = item;
	  newNode->next = NULL;
	  if(rear == NULL)
		  front = newNode;
	  else
		  rear->next = newNode;
	  rear = newNode;
  }
}
int PointerQueue::dequeue(void){
  int value;
  if(isEmpty())
	  throw EmptyQueue();
  else{
    node* temp;
	temp = front;
	value = front->value;
	front = front->next;
	if(front == NULL)
      rear == NULL;
	delete temp;
  }
  return value;
}
bool PointerQueue::isEmpty(void)const{
  return (front == NULL);
}
bool PointerQueue::isFull(void) const{
  node* temp;
  try{
    temp = new node;
	delete temp;
	return false;
  }
  catch(std::bad_alloc ex){
    return true;
  }
}


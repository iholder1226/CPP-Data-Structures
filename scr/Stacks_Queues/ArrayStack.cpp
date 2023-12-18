//Isaiah Holder
//Lab-5

#include"ArrayStack.h"

//Constructor prototypes
ArrayStack::ArrayStack(void){
  top = -1;
  maxSize = 100;
  stack = new int[maxSize];
}
ArrayStack::ArrayStack(int max){
  top = -1;
  maxSize = max;
  stack = new int[maxSize];

}
ArrayStack::~ArrayStack(void){
  delete [] stack;
}

//Transformers
int ArrayStack::pop(void){
  if(isEmpty())
	  throw EmptyStack();
  top--;

}
void ArrayStack::push(int item){
  if(isFull())
	  throw FullStack();
  stack[++top] = item;

}
//Observers
bool ArrayStack::isFull(void){
  return (top == maxSize-1);
}
bool ArrayStack::isEmpty(void){
  return (top == -1);
}
int ArrayStack::getTop(void){
  if(isEmpty())
	  throw EmptyStack();
  return stack[top];
}

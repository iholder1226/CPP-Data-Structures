//Isaiah Holder

#include"PointerStack.h"
#include"iostream"
using namespace::std;
PointerStack::PointerStack(void){
  topPtr = NULL;
}
PointerStack::~PointerStack(void){
  node *tempTop;	
  while(topPtr != NULL){
    tempTop = topPtr;
	topPtr = topPtr->next;
	delete tempTop;
  }
}
void PointerStack::push(int item){
  if(isFull())
	  throw FullStack();
  node* location = new node;
  location->value = item;
  location->next = topPtr;
  topPtr = location;
}
int PointerStack::pop(void){
	if(isEmpty())
		throw EmptyStack();
	node* temp = topPtr;
	topPtr = topPtr->next;
	int val = temp->value;
	delete temp;
	return val;
}
int PointerStack::getTop(void){
    return topPtr->value;
}
bool PointerStack::isFull(void){
	try{
      node* testNode = new node();
	  delete testNode;
	  return false;
	}
	catch(std::bad_alloc ex){
      return true;
	}
}
bool PointerStack::isEmpty(void){
    return(topPtr == NULL);
}


#include"ArrayQueue.h"

ArrayQueue::ArrayQueue(int max){
  maxSize = max+1;
  front = maxSize -1;
  rear = maxSize -1;
  queue = new int[maxSize];
}
ArrayQueue::~ArrayQueue(void){
   delete [] queue;
}
void ArrayQueue::makeEmpty(void){
 front = -1;
 rear = -1;
}
bool ArrayQueue::isFull(){
  return ((rear+1)% maxSize == front);
}
bool ArrayQueue::isEmpty(){
  return (rear == front);
}
void ArrayQueue::enqueue(int item){
  if(isFull())
    throw FullQueue();
  rear = (rear +1)% maxSize;
  queue[rear]= item;
}
int ArrayQueue::dequeue(void){
  if(isEmpty())
    throw EmptyQueue();
  front = (front + 1)% maxSize;
  int value = queue[front];
  return value;
}

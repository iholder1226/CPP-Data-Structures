//Isaiah Holder
//Header file for linked implementation of the queue ADT

//Error classes
#ifndef _exceptions
#define _exceptions
  class FullQueue{};
  class EmptyQueue{};
#endif
//Declare scruct to represent each node in the linked structure
struct node;

//PointerQueue class declaration
class PointerQueue{
public:
  PointerQueue(void);
  ~PointerQueue(void);
  void makeEmpty();
  void enqueue(int);
  int dequeue(void);
  bool isEmpty(void) const;
  bool isFull(void) const;
private:
	node* front;
	node* rear;
};
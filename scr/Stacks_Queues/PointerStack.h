//Isaiah Holder
#ifndef _exceptions
#define _exceptions
  class FullStack{};
  class EmptyStack{};
#endif

struct node{
  int value;
  node* next;
  node* prev;
};

class PointerStack{
public:
  PointerStack(void);
  ~PointerStack(void);
  void push(int);
  int pop(void);
  int getTop(void);
  bool isFull(void);
  bool isEmpty(void);
private:
  node* topPtr;
  
};
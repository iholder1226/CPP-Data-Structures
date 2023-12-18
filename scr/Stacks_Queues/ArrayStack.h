//Exception classes
#ifndef _exceptions
#define _exceptions
  class FullStack{};
  class EmptyStack{};
#endif;

class ArrayStack{
public:
	//Constructor prototypes
    ArrayStack(int maxSize);
    ArrayStack(void);
	//Destructor
    ~ArrayStack(void);
	//Transformers
	int pop(void);
	void push(int newElement);
	bool isFull(void);
	bool isEmpty(void);
	int getTop(void);

private:
	int top;
	int maxSize;
	int *stack;
};
//Error classes
class FullQueue {};
class EmptyQueue{};

class ArrayQueue{
public:
  ArrayQueue(int max = 50);
  ~ArrayQueue(void);
  void makeEmpty(void);
  bool isFull();
  bool isEmpty();
  void enqueue(int item);
  int dequeue(void);

private:
  int * queue;
  int front;
  int rear;
  int maxSize;

};
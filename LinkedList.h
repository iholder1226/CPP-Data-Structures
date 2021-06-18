struct node{
  int value;
  node* next;
};

class LinkedList{
public:
  LinkedList();
  int getNextItem(void);
  double findAvg(void);
  int findHighVal(void);
  int findLowVal(void);
  int findSum(void);
  void clearList(void);
  void resetList(void);
  void addItem(int);
  bool deletItem(int);
  void printList(void);
  void buildList(void);
  int getLength(void);
  int retrieveItem(int);
private:
  node* currentItem;
  int length;
  node* head;

};
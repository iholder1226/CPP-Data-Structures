struct node{
  int value;
	node* next;
};

class Linked_List{
public:
  Linked_List();
  int getNextItem(void);
	double findAvg(void);
	int findHighVal(void);
	int findLowVal(void);
	int findSum(void);
	void clearList(void);
	void resetList(void);
	void addItem(void);
	void deletItem(void);
  void printList(void);
	void buildList(void);
private:
	node* currentItem;
	int length;
	node* head;

};
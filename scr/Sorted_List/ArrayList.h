#ifndef _ArrayList
#define _ArrayList
class ArrayList {
private:
    int maxSize;
	int length;
	int list[20];
	int currentItem;
public:
	ArrayList(void);
    int getNextItem(void);
	int getLength(void);
	bool isFull(void);
	int retrieveItem(int item);
	double findAvg(void);
	int findHighVal(void);
	int findLowVal(void);
	int findSum(void);
	void clearList(void);
	void resetList(void);
	void addItem(int);
	bool deletItem(int);
    void printList(void);
	void badInsert(int);
	
};
#endif
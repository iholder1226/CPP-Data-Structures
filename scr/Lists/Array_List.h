#ifndef _ArrayList
#define _ArrayList
class ArrayList {
private:
    int maxSize;
	int length;
	int* list;
	int currentItem;
public:
	ArrayList(int maxSize);
    int getNextItem(void);
	bool isFull(void);
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
	
};
#endif
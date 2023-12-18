#include <list>

class cList{
public:
	cList(void);
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
	
private:
	list<int> myList;
	//int length;
};
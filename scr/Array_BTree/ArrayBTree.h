//Isaiah Holder
//ComSc-210
//Lab-8, Array based binary tree

#include<iostream>
#include<stack>
using namespace::std;
//error classes
class FullTree{};
class EmptyTree{};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class ArrayBTree{
public:
	ArrayBTree(int maxSize = 100);
	~ArrayBTree();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	void RetrieveItem(bool& found, int& item);
	void InsertItem(int item);
	bool DeleteItem(int item);
	void ResetTree();
	int GetNextItem(OrderType order, bool& finished,int& start);
	void Print(OrderType order);

private:
	void SetBranchIndexes(void);
	int* tree;
	int left;
	int right;
	int root;
	int bottomLeft;
	int bottomRight;
    int currentItem;
	int traversCount;
	stack<char> leftRightStack;
	int length;
	int maxSize;
	bool isEmpty, isFull;

};
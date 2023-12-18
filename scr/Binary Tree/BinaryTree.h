//Isaiah Holder
//ComSc-210
//Lab-8 

#include<iostream>
#include<fstream>
#include<queue>
using namespace::std;
struct TreeNode{
  int info;
  TreeNode* leftPtr;
  TreeNode* rightPtr;
};
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	void RetrieveItem(bool& found, int& item);
	void InsertItem(int item);
	void DeleteItem(int item);
	void ResetTree(OrderType order);
	int GetNextItem( OrderType order, bool& finished);
	void Print(OrderType);
private:
	int CountNodes(TreeNode* currentNode);
	void Retrieve(TreeNode* tree, int item, bool& found);
  void Insert(TreeNode*& tree, int item);
  void Delete(TreeNode*& tree, int item);
  void DeleteNode(TreeNode*& tree);
  void GetPredecessor(TreeNode*& tree, int& data);
  void PrintTree(TreeNode* tree,OrderType order);
  void Destroy(TreeNode*& tree);
  void PreOrder(TreeNode* tree, queue<int>& preQue);
  void InOrder(TreeNode* tree, queue<int>& inQue);
  void PostOrder(TreeNode* tree, queue<int>& postQue);
  queue<int> preQue;
  queue<int> inQue;
  queue<int> postQue;
  TreeNode*  root;
};
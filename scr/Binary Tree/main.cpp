//Isaiah Holder
//ComSc-210
//Lab-8  
//The following program implements a Binary Search Tree with pointers and recursion.
#include"BinaryTree.h"
#include<fstream>
#include<iostream>
using namespace::std;

int main(){
  //Declare binary tree object
  BinaryTree tree;
  
  cout << "Pointer Based BTS" << endl;
  cout << "------------------------------------------------------------------------------" << endl
       << "Operation                           Input                           Output  "  << endl
	   << "------------------------------------------------------------------------------" << endl << endl;

  //Insert 10 values into the tree
  cout << "InsertItem(int)              5,2,3,1,8,9,7,4,6,10                    void"  << endl
	   << "------------------------------------------------------------------------------" << endl;
 
  //Insert 10 items onto the tree
  int input[10]={5,2,3,1,8,9,7,4,6,10};
  for(int i = 0; i < 10; i++){
    tree.InsertItem(input[i]);
  }
  //Print one in each traversal order
	cout << "Print(PRE_ORDER)                  enum orderType         ";
	tree.Print(PRE_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;

	cout << "Print(IN_ORDER)                   enum orderType         ";
	tree.Print(IN_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;

	cout << "Print(POST_ORDER)                 enum orderType         ";
	tree.Print(POST_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;
 
  //Retrtieve a value known to be on the structure
	cout << "RetrieveItem(bool,int)               4                            ";
	bool found;
	int searchFor = 4;
	tree.RetrieveItem(found,searchFor);
	if(found){
		cout << "Item found" << endl;
	}
	else 
		cout << "Item not found" << endl; 
    cout << endl << "------------------------------------------------------------------------------" << endl;
   
  //Retrieve a value known tobe absent from the structure
	cout << "RetrieveItem(bool,int)               230                          ";
  searchFor = 230;
	tree.RetrieveItem(found,searchFor);
	if(found){
		cout << "Item found" << endl;
	}
	else 
		cout << "Item not found" << endl;
    cout << endl << "------------------------------------------------------------------------------" << endl;

 //Delete node without childeren
	cout << "Delete(int)-without childeren        6                   ";
	int tobeDeleted = 6;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;

	//Delete node with right child branch only
	cout << "Delete(int)-with childeren/right     9                   ";
    tobeDeleted = 9;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;

	//Delete node with right child branch only
	cout << "Delete(int)-with childeren/left      8                   ";
    tobeDeleted = 8;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;

  cout << "GetLength()                         void                                ";
	int len = tree.GetLength();
	cout << len;
	cout << endl << "------------------------------------------------------------------------------" << endl;

    system("pause");
	return 0;
}

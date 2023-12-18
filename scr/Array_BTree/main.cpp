//Isaiah Holder
//ComSc-210
//Lab-8, Array based binary tree

#include"ArrayBTree.h"
#include<fstream>
using namespace::std;


int main(){
	cout << "Array Based BTS" << endl;
	cout << "------------------------------------------------------------------------------" << endl
         << "Operation                           Input                           Output  "  << endl
		 << "------------------------------------------------------------------------------" << endl;

	//Declare ArrayBTree object
	ArrayBTree tree(1000);

	//Insert 10 values into the tree
	cout << "InsertItem(int)              10 20 23 24 22 5 3 9 7 2 4              void"  << endl
	     << "------------------------------------------------------------------------------" << endl;
	int input[11]={10,20,23,24,22,5,3,9,7,2,4};
	for(int i = 0; i < 11; i++){
		tree.InsertItem(input[i]);
	}
	
	//Print one in each traversal order
	cout << "Print(PRE_ORDER)                  enum orderType            ";
	tree.Print(PRE_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;
	tree.ResetTree();

	cout << "Print(IN_ORDER)                   enum orderType            ";
	tree.Print(IN_ORDER);
	tree.ResetTree();
	cout << endl << "------------------------------------------------------------------------------" << endl;

	cout << "Print(POST_ORDER)                 enum orderType            ";
	tree.Print(POST_ORDER);
	cout << endl << "------------------------------------------------------------------------------" << endl;
	tree.ResetTree();

	//Retrtieve a value known tobe on the structure
	cout << "RetrieveItem(bool,int)               23                           ";
	bool found;
	int searchFor = 23;
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
	cout << "Delete(int)-without childeren        7              ";
	int tobeDeleted = 7;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	tree.ResetTree();
	cout << endl << "------------------------------------------------------------------------------" << endl;

	//Delete node with right child branch only
	cout << "Delete(int)-with childeren/right     20             ";
    tobeDeleted = 20;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	tree.ResetTree();
	cout << endl << "------------------------------------------------------------------------------" << endl;

	//Delete node with right child branch only
	cout << "Delete(int)-with childeren/left      10             ";
    tobeDeleted = 10;
	tree.DeleteItem(tobeDeleted);
	tree.Print(IN_ORDER);
	tree.ResetTree();
	cout << endl << "------------------------------------------------------------------------------" << endl;

	//Test GetLength
	cout << "GetLength()                         void                                ";
	int len = tree.GetLength();
	cout << len;
	cout << endl << "------------------------------------------------------------------------------" << endl;

  system("pause");
  return 0;
}
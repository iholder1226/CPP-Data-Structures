//Isaiah Holder
//ComSc-210
//Lab-8

#include"BinaryTree.h"

BinaryTree::BinaryTree(){
   root = NULL;
}

BinaryTree::~BinaryTree(){
  Destroy(root);
}
void BinaryTree::Destroy(TreeNode*& tree){
  if(tree != NULL){
    Destroy(tree->leftPtr);
    Destroy(tree->rightPtr);
    delete tree;
  }
}

void BinaryTree::MakeEmpty(){
	if(root != NULL){
		Destroy(root->leftPtr);
		Destroy(root->rightPtr);
		delete root;
	}
	root = NULL;
}

bool BinaryTree::IsEmpty(){
  return root == NULL;
}

bool BinaryTree::IsFull(){
  TreeNode* location;
  try{
     location = new TreeNode;
	 delete location;
	 return false;
  }
  catch(std::bad_alloc ex){
     return true;
  }
}

int BinaryTree::CountNodes(TreeNode* currentNode){
 if(currentNode == NULL){
	 return 0;
 }
 else{
	 return CountNodes(currentNode->leftPtr) + CountNodes(currentNode->rightPtr) + 1;
 }
}

int BinaryTree::GetLength(){
  return CountNodes(root);
}
void BinaryTree::Retrieve(TreeNode* tree, int item, bool& found){
	if(tree == NULL){
       found = false;
	}
	else if(item < tree->info){
		Retrieve(tree->leftPtr, item, found);
	}
	else if(item > tree->info){
		Retrieve(tree->rightPtr, item, found);
	}
	else{
        found = true;
	}
}
void BinaryTree::RetrieveItem(bool& found, int& item){
  Retrieve(root,item,found);
}
void BinaryTree::Insert(TreeNode*& tree, int item){
	if(tree == NULL){
      tree = new TreeNode;
	  tree->rightPtr = NULL;
	  tree->leftPtr = NULL;
	  tree->info = item;
	}
	else if(item < tree->info){
		Insert(tree->leftPtr, item);
	}
	else{
		Insert(tree->rightPtr, item);
	}
}
void BinaryTree::InsertItem(int item){
  Insert(root,item);
}
void BinaryTree::GetPredecessor(TreeNode*& tree, int& data){
  while(tree->rightPtr != NULL){
    tree = tree->rightPtr;
  }
  data = tree->info;
}
void BinaryTree::DeleteItem(int item){
  Delete(root,item);
}
void BinaryTree::DeleteNode(TreeNode*& tree){
  int data ;
  TreeNode* tempPtr;

  tempPtr = tree;
  if(tree->leftPtr == NULL){
    tree = tree->rightPtr;
    delete tempPtr;
  }
  else if(tree->rightPtr == NULL){
    tree = tree->leftPtr;
    delete tempPtr;
  }
  else{
    GetPredecessor(tree->leftPtr,data);
    tree->info = data;
    Delete(tree->leftPtr,data);
  }
}
void BinaryTree::Delete(TreeNode*& tree, int item){
  if(item < tree->info){
    Delete(tree->leftPtr, item);
  }
  else if(item > tree->info){
    Delete(tree->rightPtr,item);
  }
  else
    DeleteNode(tree);
}
void BinaryTree::ResetTree(OrderType order){
  switch(order){
  case PRE_ORDER:
    PreOrder(root,preQue);
    break;
  case IN_ORDER:
    InOrder(root,inQue);
    break;
  case POST_ORDER:
    PostOrder(root, postQue);
    break;

  }
}
void BinaryTree::PreOrder(TreeNode* tree, queue<int>& preQue){
  if(tree != NULL){
    preQue.push(tree->info);
    PreOrder(tree->leftPtr,preQue);
    PreOrder(tree->rightPtr,preQue);
  }
}
void BinaryTree::InOrder(TreeNode* tree, queue<int>& inQue){
  if(tree != NULL){
    InOrder(tree->leftPtr,inQue);
    inQue.push(tree->info);
    InOrder(tree->rightPtr,inQue);
  }
}
void BinaryTree::PostOrder(TreeNode* tree, queue<int>& postQue){
  PostOrder(tree->leftPtr,postQue);
  PostOrder(tree->rightPtr,postQue);
  postQue.push(tree->info);
}
int BinaryTree::GetNextItem( OrderType order, bool& finished){
  finished = false;
  int item = 0;
  switch(order){
     
     case PRE_ORDER: 
           item = preQue.front();
           if(preQue.empty()){
             finished = true;
           }
           break;

     case IN_ORDER: 
          item = inQue.front();
          if(inQue.empty()){
            finished = true;
          }
          break;

     case POST_ORDER: 
          item = postQue.front();
          if(inQue.empty()){
            finished = true;
          }
          break;
  } 
  return item;
}
void BinaryTree::Print(OrderType order){
    PrintTree(root,order);
	
}
void BinaryTree::PrintTree(TreeNode* tree,OrderType order){
 /* if(tree != NULL){
    PrintTree(tree->leftPtr);
    cout << tree->info;
    PrintTree(tree->rightPtr);
  }*/
	
	switch(order){
	  case IN_ORDER:
		  if(tree != NULL){
              PrintTree(tree->leftPtr,order);
              cout << tree->info << ' ';
              PrintTree(tree->rightPtr,order);
          }
		  break;
	  case POST_ORDER:
		   if(tree != NULL){
              PrintTree(tree->leftPtr,order);
              PrintTree(tree->rightPtr,order);
			        cout << tree->info << ' ';
          }
		  break;
	  case PRE_ORDER:
		   if(tree != NULL){
		          cout << tree->info << ' ';
              PrintTree(tree->leftPtr,order);
              PrintTree(tree->rightPtr,order);
          }
		  break;
	}//switch*/
  
}
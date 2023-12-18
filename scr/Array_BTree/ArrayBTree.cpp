//Isaiah Holder
//ComSc-210
//Lab-8, Array based binary tree

#include"ArrayBTree.h"
#include<queue>
ArrayBTree::ArrayBTree(int max_Size){
  root = 0;
  length = 0;
  currentItem = 0;
  traversCount = 0;
  maxSize = max_Size;
  tree = new int[maxSize];
  bottomLeft = -1;
  bottomRight = -1;
  //Set all valuse to -1 to represent an emtpy spote in tree
  for(int i =0 ; i < maxSize; i++){
    tree[i] = -1;
  }
  //left branch index
  left = root*2 + 1;

  //right branch index
  right = root*2 + 2;
  isFull = false;
  isEmpty = true;
}
ArrayBTree::~ArrayBTree(){
  delete [] tree;
}
void ArrayBTree::MakeEmpty(){

  //Set all valuse to -1 to represent an emtpy spote in tree
  for(int i =0 ; i < length; i++){
    tree[i] = -1;
  }
  length = 0;
  root = 0;

  //left branch index
  left = root*2 + 1;

  //right branch index
  right = root*2 + 2;

  isFull = false;
  isEmpty = true;
}
bool ArrayBTree::IsEmpty(){
  return isEmpty;
}
bool ArrayBTree::IsFull(){
  isFull = length >= maxSize;
  return isFull;
}
int ArrayBTree::GetLength(){
  return length;
}
void ArrayBTree::RetrieveItem(bool& found, int& item){
	found = false;
	while(tree[root]> -1 && found ==false){
	  if(item < tree[root]){
        root = left;
		left = root*2+1;
		right = root*2+2;
	  }
	  else if(item > tree[root]){
        root = right;
		left= root*2+1;
		right = root*2+2;
	  }
	  else{
        if(tree[root] != -1){
          found = true;
	    }
	  }
	}
	//Reset root to top of the tree
	ResetTree();
}
void ArrayBTree::InsertItem(int item){
	int dummy = -1;
	if(IsFull()){
       throw FullTree();
	}
   while(tree[currentItem]> dummy){
	  if(item < tree[currentItem]){
        currentItem = left;
		left = currentItem*2 + 1;
		right = currentItem*2 + 2;
	  }
	  else if(item > tree[currentItem]){
        currentItem = right;
		right = currentItem*2 + 2;
		left = currentItem*2 + 1;
	  }
	}
    tree[currentItem] = item;
	length++;
	ResetTree();
    
}
bool ArrayBTree::DeleteItem(int item){
  bool found = false;
  int dummy = -1;
  while(tree[currentItem]> dummy && found ==false){
	  if(item < tree[currentItem] && tree[left] != dummy){
            currentItem = left;
		    left = currentItem*2 + 1;
			right = left;
		    right = currentItem*2 + 2;
	  }
	  else if(item > tree[currentItem] && tree[right] != dummy){
            currentItem = right;
		    right = currentItem*2 + 2;
			left = right;
		    left = currentItem*2 + 1;
	  }
	  else{
	    if(tree[left] == dummy && tree[right] == dummy){
			if(tree[currentItem] == item){
		      found = true;
              tree[currentItem] = dummy;
		      length--;
			}
			else{
				ResetTree();
				return found = false;
			}
		}
		else if(tree[left] == dummy){
			tree[currentItem] = tree[right];
			bool finished = false;
			int input; 
			int subRoot = right;
			int deleteSubTree = subRoot;
			stack<int> subTree;
			while(!leftRightStack.empty()){
				leftRightStack.pop();
			}
			int startRoot = subRoot;
			while(!finished){	  
			  input = GetNextItem(POST_ORDER,finished,subRoot);
			  subTree.push(input); 
			  tree[currentItem] = dummy;
			  if(startRoot == currentItem){
                finished = true;
			  }
			}//while

			tree[deleteSubTree] = dummy;
			currentItem = subRoot;
			finished = false;
			subTree.pop();
			while(!subTree.empty()){
				input = subTree.top();
				InsertItem(input);
				length--; //to counter balance the InsertItem function increasing the length
				subTree.pop();
				ResetTree();
			}
			found = true;
			length--;
		}//else if
		else if(tree[left] != dummy){
			stack<int> subTree;
			int input;
			bool finished = false;
			
			int tempC = currentItem;
            tempC= left;
			left = tempC*2 +1;
			right = tempC*2 + 2;
			while(tree[right] > dummy){
              tempC = right;
			  left = tempC*2+1;
			  right = tempC*2+2;
			}
			tree[currentItem] = tree[tempC];
			tempC = currentItem;
			left = currentItem*2 + 1;
		    right = currentItem*2 + 2;
			int subRoot = left;
			while(!finished){
              input = GetNextItem(POST_ORDER,finished,subRoot);
			  subTree.push(input);
			  tree[currentItem] = dummy;
			}
			ResetTree();
			while(!subTree.empty()){
				input = subTree.top();
				subTree.pop();
				if(input != tree[tempC]){
                   InsertItem(input);
				   length--;
				}
			}
			found = true;
			length--;
		}
	  }//else
	}//while
	//Reset root to top of the tree
	ResetTree();
	return found;
}
void ArrayBTree::ResetTree(){
     traversCount = currentItem = root = 0;
	 bottomRight = bottomLeft = -1;//dummy value
	 left = currentItem*2 + 1;
	 right = currentItem*2 + 2;
}
int ArrayBTree::GetNextItem(OrderType order, bool& finished, int& subRoot){
    left = subRoot*2 + 1;
    right = subRoot*2 + 2;
    char move = 'X';
    int dummy = -1;
	switch(order){
	  case PRE_ORDER:
		  currentItem = subRoot;
		  if(tree[left]> bottomLeft){
             subRoot = left;
			 left = subRoot*2+1;
			 right = subRoot*2 +2;
             leftRightStack.push('l');
			 traversCount++;
			 if(traversCount == length){
               finished = true;
			 }
			 return tree[currentItem];
		  }
		  else if(tree[right] > bottomRight){
             subRoot = right;
			 left = subRoot*2+1;
			 right = subRoot*2+2;
			 leftRightStack.push('r');
			 bottomRight = dummy;
			 traversCount++;
			 if(traversCount == length){
               finished = true;
			 }
			 return tree[currentItem];
		  }
		  else{
             //Move up one 
			 while(tree[right] <= bottomRight&& traversCount != (length-1)){
			   if(!leftRightStack.empty()){
                 int move = leftRightStack.top();
			     leftRightStack.pop();
			     if(move == 'l'){
                    subRoot = (subRoot-1)/2;
			        left = (left-1)/2;
                    right = subRoot*2 + 2;
			        bottomLeft = tree[subRoot];
			     }//else
			     else if(move== 'r'){
                    subRoot = (subRoot-2)/2;
					left = subRoot*2 + 1;
					right = subRoot*2 +2;
				    bottomRight = tree[right];
			     }//else
			   }//if
			 }//while
			 subRoot = right;
			 left = subRoot*2+1;
			 right = subRoot*2+2;
			 leftRightStack.push('r');
             traversCount++;
			 if(traversCount == length){
               finished = true;
			 }
			 return tree[currentItem];
		  }
          break;
	  case IN_ORDER://Prints left branch, then root, then right branch
	    if(tree[subRoot] != bottomLeft){
          while(tree[left] > bottomLeft){
            subRoot = left;
            left = subRoot*2 + 1;
            right = subRoot*2 + 2;
			leftRightStack.push('l');
          }
          bottomLeft = tree[subRoot];
		  traversCount++;
          return tree[subRoot];
        }
		/*If currentItem is equal to the bottomLeft index, 
		  then we know we have already gone left and returned a value.
		  Now we check to see if there is a right branch to traverse.
		*/
        else if(tree[subRoot] == bottomLeft){
             //Check to see if there is a right branch
		     if(tree[right] > bottomRight){
		         subRoot = right;
				 leftRightStack.push('r');
			     left = subRoot*2 + 1;
                 right = subRoot*2 + 2;
                while(tree[left] > bottomLeft){
                  subRoot = left;
				  leftRightStack.push('l');
                  left = subRoot*2 + 1;
                  right = subRoot*2 + 2;
                }
                bottomLeft = tree[subRoot];
				traversCount++;
				if(traversCount == length){
                   finished = true;
				   traversCount=0;
			    }
			    return tree[subRoot];
		    }
		    else{
			   //Move all indexes up one level, coming from a left branch of the tree
				if(!leftRightStack.empty()){
					move = leftRightStack.top();
					leftRightStack.pop();
				    if(move == 'r'){
					   while(true){
						 subRoot = (subRoot-2)/2;
			             left = subRoot*2 +1;
			             right = (right-2)/2;
			             bottomRight = tree[subRoot];
						 if(!leftRightStack.empty()){
						   move = leftRightStack.top();
						   leftRightStack.pop();
						 }
						 if(move == 'l' || leftRightStack.empty()){
                           break;
						 }
					   }//while
				     }//if
				     if(move == 'l'){
					     subRoot = (subRoot-1)/2;
			             left = (left-1)/2;
                         right = subRoot*2 + 2;
			             bottomLeft = tree[subRoot];
						 traversCount++;
						 if(traversCount == length){
                           finished = true;
			             }
					     return tree[subRoot];
				    }//if
				}//if
				else if(leftRightStack.empty()){
					if(move == 'r' || move == 'X'){
                       finished = true;
					   if(move == 'X')
					     return tree[subRoot];
					}
			    }
			    else{
				   traversCount++;
				   if(traversCount == length){
                     finished = true;
			       }  
                   return tree[subRoot];
			    }
		    }//else
        }//else if()
		break;
     
	  case POST_ORDER: //Prints left branch, then right branch , then root
		  while(tree[left] > bottomLeft || tree[right] > bottomRight){
		  //check for left branch
		  if(tree[subRoot] != bottomLeft){
			  while(tree[left] > bottomLeft){//Travers to the bottom left leaf of tree
                subRoot = left;              // move the root down one level to the left
				left = subRoot*2+1;          // resolves to the index value of the left branch associated with the new root
				right = subRoot*2+2;         // resolves to the index value of the right branch associated with the new root
				leftRightStack.push('l');
			  }
			  bottomLeft = tree[subRoot];          // move bottom left up one level
		  }
		  //else check for right branch
		  else if(tree[right] > bottomRight){// If there is a right branch move all index values down one level to the right
              subRoot = right;                
			  right = subRoot*2+2;
			  left = subRoot*2+1;
			  leftRightStack.push('r');
		  }
		  }//while
		  //Move root and branch indexes up one level
		  currentItem = subRoot;
		  if(!leftRightStack.empty()){
		    move = leftRightStack.top();
		    leftRightStack.pop();
		    if(move == 'l'){
                 subRoot = (subRoot-1)/2;
			     left = (left-1)/2;
                 right = subRoot*2 + 2;
			     bottomLeft = tree[subRoot];
				 if( currentItem == 0){
                    finished = true;
				 }
			     return tree[currentItem];
		    }
		    else if(move == 'r'){
			     bottomRight = tree[subRoot];
                 subRoot = (subRoot-2)/2;
	   		     left = subRoot*2 + 1;
                 right = subRoot*2 + 2;
			     bottomLeft = tree[subRoot];
				 if( currentItem == 0){
                    finished = true;
				 }
			     return tree[currentItem];
		    }
		  }
		  else if (currentItem == 0 || leftRightStack.empty()){
			  finished = true;
		      return tree[currentItem];
		  }
		 
		 // return tree[subRoot];
		  break;
	}//switch
	
}
void ArrayBTree::Print(OrderType order){
	bool finished = false;
	switch(order){
	  case IN_ORDER:
		  while(!finished){
            cout << GetNextItem(IN_ORDER,finished,root) << " ";	
		  }//while
		  ResetTree();
		  break;
	  case POST_ORDER:
		  while(!finished){
            cout << GetNextItem(POST_ORDER,finished,root) << " ";	
		  }//while
		  ResetTree();
		  break;
	  case PRE_ORDER:
		  while(!finished){
            cout << GetNextItem(PRE_ORDER,finished,root) << " ";	
		  }//while
		  ResetTree();
		  break;
	}//switch
}
void ArrayBTree::SetBranchIndexes(void){
  left = currentItem*2 + 1;
  right = currentItem*2 + 2;
}
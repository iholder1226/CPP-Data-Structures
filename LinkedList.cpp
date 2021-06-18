#include "LinkedList.h"
#include<iostream>
using namespace::std;

LinkedList::LinkedList(){
    head = 0;
	length = 0;
	currentItem = head;
}
int LinkedList::getNextItem(void){
    int nextItem = 0;
	currentItem = currentItem->next;
	nextItem = currentItem->value;
	return nextItem;
}
double LinkedList::findAvg(void){
	int sum = 0;
	while(currentItem->next != 0){
        sum += currentItem->value;
		getNextItem();
    }
	sum += currentItem->value;
    double avg = (double)sum/(length);
	resetList();
	return avg;
}
int LinkedList::findHighVal(void){
	int high = currentItem->value;
  while(currentItem->next != 0){
		if(high< currentItem->value){
			high = currentItem->value;
		}
		getNextItem();//Increments currentItem, returns copy of value stored in currentItem
    }
	if(high< currentItem->value){
			high = currentItem->value;
	}
	resetList();
	return high;
}
int LinkedList::findLowVal(void){
	int low = currentItem->value;
  while(currentItem->next != 0){
		if(low> currentItem->value){
			low = currentItem->value;
		}
		getNextItem();
    }
	if(low > currentItem->value){
			low = currentItem->value;
	}
	resetList();
	return low;
}
int LinkedList::findSum(void){
    int sum = 0;
	while(currentItem->next != 0){
        sum += currentItem->value;
		getNextItem();
    }
	sum += currentItem->value;
	resetList();
	return sum;
}
void LinkedList::clearList(void){
	while(head->next){
        getNextItem();
		delete head;
		head = currentItem;
	}
	delete head;
	head = 0;
	resetList();
}
void LinkedList::resetList(void){
  currentItem = head;
}
void LinkedList::addItem(int newItem){
	
  node* newNode;
  node* prevNode = NULL;
  bool moreToSearch = (currentItem != NULL);

  while(moreToSearch){
	if(newItem > currentItem->value){
       prevNode = currentItem;
	   currentItem = currentItem->next;
	   moreToSearch = (currentItem != NULL);
	}//if
	else{
      moreToSearch = false;
	}//else
  }//while

  //insert new node
  newNode = new node;

  if(prevNode == NULL){
	  newNode->next = currentItem;
	  head = newNode;
	  newNode->value = newItem;
  }//if
  else{
	  newNode->next = currentItem;
	  prevNode->next = newNode;
	  newNode->value = newItem;
  }
  length++;
  resetList();
}
bool LinkedList::deletItem(int deletedItem){
	bool itemDeleted = false;
	node* prevNode = NULL;
	if(currentItem->value == deletedItem){
      head = head->next;
	  length--;
	  itemDeleted = true;
	  resetList();
	}
	else{
	  while(currentItem->value != deletedItem && currentItem->next != NULL){
        prevNode = currentItem;       
		currentItem = currentItem->next;
	  }//while
	 if(currentItem->next != NULL){
        itemDeleted = true;
		prevNode->next = currentItem->next;
		length--;
	  }//if
	 else if(currentItem->value == deletedItem){
		itemDeleted = true;
		prevNode->next = currentItem->next;
		length--;
	 }//else if
	}//else
	resetList();
	return itemDeleted;
}
int LinkedList::retrieveItem(int item){
   int recordNum = 1;
   while(currentItem->value != item && currentItem->next != NULL){
      getNextItem();
      recordNum++;
   }//while
   if(currentItem->next == NULL){
	 if(currentItem->value != item)
       recordNum = -1;
	 else
		 recordNum++;
   }//if
   
   return recordNum;
}
int LinkedList::getLength(void){
  return length;
}
void LinkedList::printList(void){
	if(currentItem != NULL){
	  while(currentItem->next != NULL){
        cout << currentItem->value << " ";
        getNextItem();
      }
	  cout << currentItem->value << endl;
	}
	else{
      cout << "List is empty" << endl; 
	}
	resetList();
}


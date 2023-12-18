#include"ArrayList.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList(void){
	length = 0;
	currentItem = 0;
	maxSize = 9;
	
}
int ArrayList::getNextItem(void){
 return list[currentItem++];
}
bool ArrayList::isFull(void){
  bool isFull = false;
	if(length == maxSize){isFull = true;}
  return isFull;
}
int ArrayList::getLength(void){
   return length;
}
double ArrayList::findAvg(void){
  double avg;
  int sum =0;
  for(int i = 0; i < length;i++){
    sum += list[i];
  }
  avg = (double)sum/length;
  return avg;
}
int ArrayList::findHighVal(void){
  int highVal = list[0];
  for(int i = 1; i < length;i++){
    if(highVal < list[i]){
      highVal = list[i];
	}
  }
  return highVal;
}
int ArrayList::findLowVal(void){
  int lowVal = list[0];
  for(int i = 1; i < length;i++){
    if(lowVal > list[i]){
      lowVal = list[i];
	}
  }
  return lowVal;
}
int ArrayList::findSum(void){
  int sum =0;
  for(int i = 0; i < length;i++){
    sum += list[i];
  }
  return sum;
}
void ArrayList::clearList(void){
  delete list;
  length = 0;
  resetList();
}
void ArrayList::resetList(void){
  currentItem = 0;
}
//Binary Search to add an item
void ArrayList::addItem(int newItem){
  if(!isFull()){	
	if(length > 0){

	   //search for the right spot to insert the new value on the list
	   while(newItem > list[currentItem] && currentItem < length){
          getNextItem();
	   }
	   int j = length;
	   while(j > currentItem){
         list[j--] = list[j-1];
	   }
	   list[currentItem]= newItem;
	   length++;
	}
	else
	  list[length++]= newItem;
  }//if()
  resetList();
}
//Bad insert, adds item to end of list then bubble sorts the list
void ArrayList::badInsert(int item){
	list[length] = item;
	int j = length;
	currentItem = length-1;
	int temp;
	if(length > 0){
	  while(list[j] < list[currentItem]){
        temp = list[j];
	    list[j]= list[currentItem];
	    list[currentItem] = temp;
		if(currentItem > 0){
		  j--;
		  currentItem--;
		}
	  }
	}
	length++;
	resetList();
}
int ArrayList::retrieveItem(int item){
  int first = 0;
  int last = length -1;
  int midPoint;
  bool found = false;
  bool moreToSearch = first <= last;
  while(moreToSearch){
    midPoint = (first+last)/2;
	if(list[midPoint] == item){
       moreToSearch = false;
	   found = true;
	   return(midPoint + 1);
	}
	else if(list[midPoint] < item){
       first = midPoint+1;
       moreToSearch = first <= last;
	}
	else{
       last = midPoint-1;
       moreToSearch = first <= last;
	}

  }
  if(!found)
    return -1;
}
bool ArrayList::deletItem(int value){
  bool itemDeleted = false;
  
  //Delete item from list 
  while(currentItem < length){
    while(list[currentItem] != value && currentItem < length){ 
       getNextItem();
    }
    if(list[currentItem] == value){
      itemDeleted = true;
      int i = currentItem;
      int j = currentItem;
      while(i < length){
        list[j++] = list[++i];
      }
      length--;
    }//if
  }//while
  resetList();
  return itemDeleted;
}


void ArrayList::printList(void){
  while(currentItem < length){
    cout << getNextItem() << " ";  
  }
    cout << endl;
	resetList();
}

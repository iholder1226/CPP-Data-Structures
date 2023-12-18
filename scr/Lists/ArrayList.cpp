#include"ArrayList.h"
#include <iostream>
using namespace std;
ArrayList::ArrayList(int maxSize=0){
	length = 0;
	currentItem = 0;
	list = new int[maxSize];
	
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
  cout << "The average value of all items currently on the list is : " << avg << endl;
  return avg;
}
int ArrayList::findHighVal(void){
  int highVal = list[0];
  for(int i = 1; i < length;i++){
    if(highVal < list[i]){
      highVal = list[i];
	}
  }
  cout << "The highest value on the list is : " << highVal << endl;
  return highVal;
}
int ArrayList::findLowVal(void){
  int lowVal = list[0];
  for(int i = 1; i < length;i++){
    if(lowVal > list[i]){
      lowVal = list[i];
	}
  }
  cout << "The lowest value on the list is : " << lowVal << endl;
  return lowVal;
}
int ArrayList::findSum(void){
  int sum =0;
  for(int i = 0; i < length;i++){
    sum += list[i];
  }
  cout << "The sum of all the values on the list is : " << sum << endl;
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
void ArrayList::addItem(int newItem){
	if(length > 0){
	   int i =0;
	   while(newItem > list[i]){
          i++;
	   }
	   if(i < length){
         addItem(list[i]);
	   }
	}
	else
	  list[length++]= newItem;
}
void ArrayList::deletItem(void){
  //prompt for item to delete
  cout << "Enter a value to delete from the list:  ";
	int value;
  cin >> value;
 
//Delete item from list 
  for(int i = 0; i < length + 1; i++){
     if(list[currentItem] == value){
       i++;
       list[currentItem] = list[i];
       length--;
    }
    else{
      list[currentItem]=list[i];
    }
    getNextItem();
  }
  resetList();
}
void ArrayList::printList(void){
	cout << "Current List" << endl;
	
  while(currentItem < length){
    cout << getNextItem() << endl;  
  }
	resetList();
}
void ArrayList::buildList(void){
  char delimiter = ',';
  float group = 1;
  char num[11] = {"0123456789"};
  char* initialList = new char[100];
  int token = 0;
  int tokenCounter = 0;

  cout << "Enter one or more values seperated by a comma to start your list:" << endl;
  cout << "Enter: ";
  cin >> initialList;

  int size = strlen(initialList);
  int i;
  for(i = size-1; i >= 0; i--){
    if(initialList[i]=='-'){token *= -1;}
	if(initialList[i] != delimiter){
	  for(int j = 0; j < 10;j++){
		if(initialList[i] == num[j]){
          token += j * group;
		}
	  }//for
	}//if
	else{
      list[tokenCounter++] = token;
	  length++;
	  token = 0;
	  group = .1;
	}
	group *= 10;
  }//for
  list[tokenCounter++] = token;
  length++;
  delete initialList;
  resetList();
}//buildList()
#include "Linked_List.h"
#include<iostream>
using namespace::std;

Linked_List::Linked_List(){
  head = 0;
	length = 0;
	currentItem = head;
}
int Linked_List::getNextItem(void){
  int nextItem = 0;
	currentItem = currentItem->next;
	nextItem = currentItem->value;
	return nextItem;
}
double Linked_List::findAvg(void){
	int sum = 0;
	while(currentItem->next != 0){
        sum += currentItem->value;
		getNextItem();
    }
	sum += currentItem->value;
  double avg = (double)sum/(length);
	cout << "The avg of all values currently on the list is: " << avg << endl;
	resetList();
	return avg;
}
int Linked_List::findHighVal(void){
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
	cout << "The highest value currently on the list is: " << high << endl;
	resetList();
	return high;
}
int Linked_List::findLowVal(void){
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
	cout << "The lowest value currently on the list is: " << low << endl;
	resetList();
	return low;
}
int Linked_List::findSum(void){
    int sum = 0;
	while(currentItem->next != 0){
        sum += currentItem->value;
		getNextItem();
    }
	sum += currentItem->value;
	cout << "The sum of all values on the list is: " << sum << endl;
	resetList();
	return sum;
}
void Linked_List::clearList(void){
	while(head->next){
    getNextItem();
		delete head;
		head = currentItem;
	}
	delete head;
	head = 0;
	resetList();
}
void Linked_List::resetList(void){
  currentItem = head;
}
void Linked_List::addItem(void){
	int newItem;
	cout << "Enter value to add to the list: ";
	cin >> newItem;
	cout << endl;
	
	while(currentItem->next != 0){
		getNextItem();
	}
	currentItem->next = new node();
	currentItem->next->value = newItem;
	currentItem->next->next=0;
	length++;
  resetList();
}
void Linked_List::deletItem(void){
	int deletedItem;
	cout << "Enter the value you would like deleted: ";
	cin >> deletedItem;
	
	while(currentItem->next != 0){
		if(currentItem->value == deletedItem){
			head = currentItem->next;
			length--;
		}
		if(currentItem->next->value == deletedItem){
			currentItem->next = currentItem->next->next;
			length--;
		}
		else{
		  getNextItem();
		}
	}
    resetList();
}
void Linked_List::printList(void){
	cout << "Current List" << endl;
	while(currentItem->next != 0){
    cout << currentItem->value << endl;
    getNextItem();
  }
	cout << currentItem->value << endl;
	resetList();
}
void Linked_List::buildList(void){
  char table[11]={"0123456789"};
  char delm = ',';
  char* list = new char[100];
  int token = 0;
  float base = 1;
  cout << "Please enter one or more values seperated by a comma to start you list." << endl
	   << "Enter: ";
  cin >> list;
  cout << endl;
  int size = strlen(list);

//Tokenize input
  for(int i = size-1; i > -1;i--){
	 if(list[i]=='-'){token *= -1;}          //for negative numbers
     if(list[i]==delm){                    //reached a delimiter, add current token to the list
       node* newNode = new node();
	     newNode->next = head;
       newNode->value = token;
       head = newNode;
       token = 0;
       base = 0.1;
	     length++;
     }
     else{//build token
        for(int j = 0; j < 10; j++){
          if(list[i]==table[j]){
              token+= j * (int)base;
          }
       }
    }
    base *= 10;
  }
  node* newNode = new node();// Add last token to the list
  newNode->next = head;
  newNode->value = token;
  head = newNode;
  length++;
  resetList();
  delete list;

}

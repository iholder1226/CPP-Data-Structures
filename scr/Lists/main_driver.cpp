//Isaiah Holder
//ComSc-210
//Implementing lists using different types of disign methods.

#include<iostream>
#include<list>
using namespace std;

#include "Array_List.h"
#include "Linked_List.h"
#include "cList.h"
#include "interface.h"

int main(){
	char command[3] = {0};
	int listType = 1;
	while(listType==1||listType==2||listType==3){
      system("cls");
	  listType = home();
	  if(listType == 1){
		system("cls");
		arrayOperations();
	    cout << "Enter the max number of elements for your list: ";
        int maxSize;
        cin >> maxSize;
		ArrayList list1(maxSize);
		system("cls");
		arrayOperations();
		list1.buildList();
		system("cls");
		arrayOperations();
		list1.printList();
		system("pause");
		do{
		  system("cls");
		  arrayOperations();
		  cout << "Enter a command:";
		  cin >> command;
		  int i = 0;
		  while(command[i]!=NULL){
            command[i] = toupper(command[i]);
	        i++;
	      }
		  executeArray(command,list1);
		  if(strcmp(command, "Q") != 0){
		    system("pause");
		  }
		}
		while(strcmp(command,"Q") != 0);
		list1.clearList();
	  }
 	  else if(listType == 2){
        Linked_List list2;
		system("cls");
		linkedListOperations();
		list2.buildList();
		do{
		  system("cls");
		  linkedListOperations();
		  cout << "Enter a command:";
		  cin >> command;
		  int i = 0;
		  while(command[i]!=NULL){
            command[i] = toupper(command[i]);
	        i++;
	      }
		  executeLinked(command,list2);
		  if(strcmp(command, "Q") != 0){
		    system("pause");
		  }
		}
		while(strcmp(command,"Q") != 0);
		list2.clearList();
	  }
	  else if(listType == 3){
        list<int> list3;
		system("cls");
		cListOperations();
		buildList(list3);
		do{
		  system("cls");
		  cListOperations();
		  cout << "Enter a command:";
		  cin >> command;
		  int i = 0;
		  while(command[i]!=NULL){
            command[i] = toupper(command[i]);
	        i++;
	      }
		  executeCList(command,list3);
		  if(strcmp(command, "Q") != 0){
		    system("pause");
		  }
		}
		while(strcmp(command,"Q") != 0);
	  }
	  else{ 
	    cout << "INVALID INPUT!";
		break;
	  }
    }//while()
  return 0;
}

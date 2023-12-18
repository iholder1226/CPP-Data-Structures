void arrayOperations(){
cout << "Working With Lists - Array Based List" << endl
			 << "-------------------------------------------------------------" << endl << endl
			 << "   Operations                             Enter " << endl
			 << "-------------------------------------------------------------" << endl
			 << "Find Highest Value                          H" << endl
			 << "Find Lowest Value                           L" << endl
			 << "Find Average Value                          A" << endl
			 << "Find Sum Of All Values                      S" << endl
			 << "Add Item                                    Ad" << endl
			 << "Delete Item                                 D" << endl
			 << "Print List                                  P" << endl
			 << "Main Menu                                   Q" << endl
			 << "-------------------------------------------------------------" << endl << endl;
}
void cListOperations(){
cout << "Working With Lists - C++ STL List" << endl
			 << "-------------------------------------------------------------" << endl << endl
			 << "   Operations                             Enter " << endl
			 << "-------------------------------------------------------------" << endl
			 << "Find Highest Value                          H" << endl
			 << "Find Lowest Value                           L" << endl
			 << "Find Average Value                          A" << endl
			 << "Find Sum Of All Values                      S" << endl
			 << "Add Item                                    Ad" << endl
			 << "Delete Item                                 D" << endl
			 << "Print List                                  P" << endl
			 << "Main Menu                                   Q" << endl
			 << "-------------------------------------------------------------" << endl << endl;
}
void linkedListOperations(){
cout << "Working With Lists - Linked List" << endl
			 << "-------------------------------------------------------------" << endl << endl
			 << "   Operations                             Enter " << endl
			 << "-------------------------------------------------------------" << endl
			 << "Find Highest Value                          H" << endl
			 << "Find Lowest Value                           L" << endl
			 << "Find Average Value                          A" << endl
			 << "Find Sum Of All Values                      S" << endl
			 << "Add Item                                    Ad" << endl
			 << "Delete Item                                 D" << endl
			 << "Print List                                  P" << endl
			 << "Main Menu                                   Q" << endl
			 << "-------------------------------------------------------------" << endl << endl;
}

int home(){
  cout << "Working With Lists" << endl << endl
	   << "Choose A List Style From Below "  << endl << endl
	   << "---------------------------------------------------------------" << endl
	   << "Implementation                   Enter" << endl << endl
	   << "---------------------------------------------------------------" << endl
	   << "Array Based List                   1" << endl
	   << "Linked List                        2" << endl
	   << "C++ List                           3" << endl
	   << "---------------------------------------------------------------" << endl
	   << "Enter:";
  int listType;
  cin >> listType;
  return listType;
}

float executeArray(char* command,ArrayList &list){
	float dummy = 0.0;
	
	if(strcmp(command,"H")==0){
		  dummy = list.findHighVal();
	}
	else if(strcmp(command,"L")==0){
		dummy = list.findLowVal();
	}
	else if(strcmp(command,"A")==0){
		dummy = list.findAvg();
	}
	else if(strcmp(command,"S")==0){
		dummy = list.findSum();
	}
	else if(strcmp(command,"AD")==0){
		list.addItem();
	}
	else if(strcmp(command,"D")==0){
		list.deletItem();
	}
	else if(strcmp(command,"P")==0){
		list.printList();
	}
	else if(strcmp(command,"Q")!=0){
      cout << "INVALID COMMAND" << endl;
	}
	return dummy;
}


float executeLinked(char* command,Linked_List &list){
	float dummy = 0.0;
	
	if(strcmp(command,"H")==0){
		  dummy = list.findHighVal();
	}
	else if(strcmp(command,"L")==0){
		dummy = list.findLowVal();
	}
	else if(strcmp(command,"A")==0){
		dummy = list.findAvg();
	}
	else if(strcmp(command,"S")==0){
		dummy = list.findSum();
	}
	else if(strcmp(command,"AD")==0){
		list.addItem();
	}
	else if(strcmp(command,"D")==0){
		list.deletItem();
	}
	else if(strcmp(command,"P")==0){
		list.printList();
	}
	else if(strcmp(command,"Q")!=0){
      cout << "INVALID COMMAND" << endl;
	}
	return dummy;
}

float executeCList(char* command,list<int> &myList){
	float dummy = 0.0;
	
	if(strcmp(command,"H")==0){//Finds highest value on list
		int high = *myList.begin();
		for(list<int>::iterator it = myList.begin(); it != myList.end(); ++it){
			if(high < *it) {high = *it;}
	    }
		cout << "The highest value currently on the list is: " << high << endl; 
	}
	else if(strcmp(command,"L")==0){//Finds lowest value on list
		int low = *myList.begin();
		for(list<int>::iterator it = myList.begin(); it != myList.end(); ++it){
			if(low > *it) {low = *it;}
	    }
		cout << "The lowest value currently on the list is: " << low << endl;
	}
	else if(strcmp(command,"A")==0){//Finds the average value of all list items
	  double avg = 0;
	  int sum = 0;
	  for(list<int>::iterator it = myList.begin(); it != myList.end(); ++it){
         sum += *it;
	  }
	  avg = sum/(double)myList.size();
	  cout << "The average of all the items currently on the list is: " << avg << endl;
	}
	else if(strcmp(command,"S")==0){//Sum of all items on list
	  int sum = 0;
	  for(list<int>::iterator it = myList.begin(); it != myList.end(); ++it){
         sum += *it;
	  }
	  cout << "The sum of all values currently on the list is: " << sum << endl;
	}
	else if(strcmp(command,"AD")==0){//Add item to the list
		int newItem;
		cout << "Enter a value you would like to add to the list: " ;
		cin >> newItem;
		myList.push_back(newItem);
	}
	else if(strcmp(command,"D")==0){//Delete item from list
		int deletedItem;
		cout << "Please enter the value you would like to delete from the list: ";
		cin >> deletedItem;
		myList.remove(deletedItem);
	}
	else if(strcmp(command,"P")==0){//Print list
		list<int>::iterator it;	
		cout << "Current List" << endl;
		for(it = myList.begin(); it != myList.end();++it){
          cout << *it << endl;
		}
	}
	else if(strcmp(command,"Q")!=0){
      cout << "INVALID COMMAND" << endl;
	}
	return dummy;
}
void buildList(list<int> &myList){
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
	 if(list[i]=='-'){token *= -1;}//for negative numbers
     if(list[i]==delm){//reached a delimiter, add current token to the list
		 myList.push_front(token);
       token = 0;
       base = 0.1;
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
  // Add last token to the list
  myList.push_front(token);
  delete list;


}
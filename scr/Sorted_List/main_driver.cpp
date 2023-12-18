//Isaiah Holder
//Lab-4: Sorted Lists

#include "ArrayList.h"
#include "LinkedList.h"
#include<iostream>
#include<fstream>
using namespace::std;

int main(){
	cout << "ArrayList Object" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Operation                     Input                        Output " << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Declare and open a input file stream to a test file
	ifstream fin;
	fin.open("inputFile.dat");

	//Declare ArrayList object
	ArrayList list1;
	int testInput;
	//Add all the values from file to the ArrayList object
	while(fin >> testInput ){
		cout << "addItem(int)                  " << testInput << "                            ";
		if(!list1.isFull()){
		  list1.addItem(testInput);
		  list1.printList();
		}
		else 
			cout << "LIST IS FULL" << endl;
	}

	cout << "------------------------------------------------------------------------" << endl;
	

	//Delete implementation with valid input
	cout << "deleteItem(int)               "<< 3 << "                            "; 
	if(list1.deletItem(3)){
		cout << "Item(s) Deleted" << endl;
	}
	else{
        cout << "Item Not Found" << endl;
	}
	cout << "                                                             ";
	list1.printList();
    
	//Delete implementation with invalid input
	cout << "deleteItem(int)               "<< -9 << "                           "; 
	if(list1.deletItem(-9)){
		cout << "Item(s) Deleted." << endl;
	}
	else{
        cout << "Item Not Found" << endl;
	}
	cout << "                                                             ";
	list1.printList();
	cout << "------------------------------------------------------------------------" << endl;
  
  //Add item using badInsert()
 /* fin.seekg(0);
  fin>> testInput;
  cout << "badInsert(int)                  " << testInput << "                            ";
		if(!list1.isFull()){
			list1.badInsert(testInput);
		  list1.printList();
		}
		else 
			cout << "LIST IS FULL" << endl;
	}
  fin.close();

	cout << "------------------------------------------------------------------------" << endl;*/

	//Find  the highest value on the list
	int high = list1.findHighVal();
    cout << "findHighVal(void)            " << "Void" << "                          " << high << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Find the lowest value on the list
	int low = list1.findLowVal();
	cout << "findLowVal(void)             " << "Void" << "                          " << low << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Find the average value 
	double avg = list1.findAvg();
	cout << "findAvg(void)                " << "Void" << "                          " << avg << endl;
	cout << "------------------------------------------------------------------------" << endl;
	

	//Get the length of the list
	int len = list1.getLength();
	cout << "getLength(void)              " << "Void" << "                          " << len << endl;
	cout << "------------------------------------------------------------------------" << endl;
	
	//Retrieve an item
	int record = list1.retrieveItem(1);
	cout << "retrieveItem(1)              " << "1" << "                        " ;
	if(record > 0){cout<<"Found in record: "<< record << endl;}
	else
		cout << "Item not found" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	record = list1.retrieveItem(-1);
	cout << "retrieveItem(-1)              " << "-1" << "                        " ;
	if(record > 0){cout<<"Found in record: "<< record << endl;}
	else
		cout << "Item not found" << endl;
	cout << "------------------------------------------------------------------------" << endl;
    system("pause");
    



	//******************************************************************************************************
	system("cls");
	cout << "Linked List" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Operation                     Input                        Output " << endl;
	cout << "------------------------------------------------------------------------" << endl;
	fin.open("inputFile.dat");
	fin.seekg(0);
	LinkedList list2;

	//Add all the values from file to the ArrayList object
	while(fin >> testInput){
		cout << "addItem(int)                  " << testInput << "                            ";
		list2.addItem(testInput);
		list2.printList();
	}

	cout << "------------------------------------------------------------------------" << endl;
	fin.close();

	//Delete implementation with valid input
	cout << "deleteItem(int)               "<< 3 << "                            "; 
	if(list2.deletItem(3)){
		cout << "Item(s) Deleted" << endl;
	}
	else{
        cout << "Item Not Found" << endl;
	}
	cout << "                                                             ";
	list2.printList();
    
	//Delete implementation with invalid input
	cout << "deleteItem(int)               "<< -9 << "                           "; 
	if(list2.deletItem(-9)){
		cout << "Item(s) Deleted" << endl;
	}
	else{
        cout << "Item Not Found" << endl;
	}
	cout << "                                                             ";
	list2.printList();
	cout << "------------------------------------------------------------------------" << endl;

	//Find  the highest value on the list
    high = list2.findHighVal();
    cout << "findHighVal(void)            " << "Void" << "                          " << high << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Find the lowest value on the list
    low = list2.findLowVal();
	cout << "findLowVal(void)             " << "Void" << "                          " << low << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Find the average value 
    avg = list2.findAvg();
	cout << "findAvg(void)                " << "Void" << "                          " << avg << endl;
	cout << "------------------------------------------------------------------------" << endl;
	

	//Get the length of the list
    len = list2.getLength();
	cout << "getLength(void)              " << "Void" << "                          " << len << endl;
	cout << "------------------------------------------------------------------------" << endl;
	
	//Retrieve an item
    record = list2.retrieveItem(4);
	cout << "retrieveItem(4)              " << "4" << "                        " ;
	if(record > 0){cout<<"Found in record: "<< record << endl;}
	else
		cout << "Item not found" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	record = list2.retrieveItem(16);
	cout << "retrieveItem(-1)              " << "16" << "                         " ;
	if(record > 0){cout<<"Found in record: "<< record << endl;}
	else
		cout << "Item not found" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	system("pause");
	return 0;
}
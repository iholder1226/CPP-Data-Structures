//Isaiah Holder
//ComSc-210
//Lab-9{sets}
//12-01-2010

#include<iostream>
using namespace::std;
#include"Set.h"
#include<set>

int main(){
  cout << "Array Set:" << endl
	   << "-----------------------------------------------" << endl;
  //Declare a Set object, the store four values
  Set<char> set1;
  set1.Store('A');
  set1.Store('B');
  set1.Store('C');
  set1.Store('D');

//Declare a second set to use when testing the union, intersection, and difference operations
  Set<char> set2;
  set2.Store('C');
  set2.Store('D');
  set2.Store('E');
  set2.Store('F');

//Declare third set, as a union of set1 and set2
  Set<char> set3;
  set3 = set2.Union(set1);

//Delcare fourth set, as an intersection of set1 and set2
  Set<char> set4;
  set4 = set1.Intersection(set2);

//Declare 5th set as difference of set1 and set2
  Set<char> set5;
  set5 = set1.Difference(set2);
  cout << "Set1: ";
  set1.Print();
  cout << endl << "Set2: ";
  set2.Print();
  cout<< endl << "Union: ";
  set3.Print();
  cout << endl << "Intersection: ";
  set4.Print();
  cout << endl << "Difference: ";
  set5.Print();
  cout << endl;
  
  system("pause");

  //***********************************STL Set******************************************
  system("cls");
  cout << "STL Set:" << endl
	   << "-----------------------------------------------" << endl;
  //set 1
  set<char> setA;
  setA.insert('A');
  setA.insert('C');
  setA.insert('D');
  
  cout << "Set 1 :";
  set<char>::iterator i = setA.begin();
  while(i != setA.end()){
    cout << *i << " " ;
	i++;
  }
  cout << endl;

  //set 2
  set<char> setB;
  setB.insert('D');
  setB.insert('E');
  setB.insert('F');

  cout << "Set 2 :";
  i = setB.begin();
  while(i != setB.end()){
    cout << *i << " " ;
	i++;
  }
  cout << endl;

  //union
  set<char> setC;
  i = setA.begin();
  while(i != setA.end()){
	  setC.insert(*i);
	  i++;
  }
  i = setB.begin();
  bool found = false;
  set<char>::iterator j;
  while(i != setB.end()){
	  j = i;
	  setC.find(*i);
	  if(i != setB.end()){
		  setC.insert(*i);
	  }
	  else
		  i = j;
	  i++;
  }
  cout << "Union:";
  i = setC.begin();
  while(i != setC.end()){
    cout << *i << " " ;
	i++;
  }
  cout << endl;


  //Intersection
   set<char> setD;
   if(setA.size() >= setB.size()){
      i = setA.begin();
	  while(i != setA.end()){
		  j= setB.begin();
		  found = false;
		  while(j != setB.end() && !found){
			  if(*i == *j){
                 found = true;
			  }
			  if(found == false){
			    j++;
			  }
		  }
		  if(found){
			  setD.insert(*j);
		  }
		  i++;
	  }
  }
  else{
	  i = setB.begin();
	  while(i != setB.end()){
		  j = setA.begin();
		  found = false;
		  while(j != setA.end() && !found){
			  if(*i== *j){
                 found = true;
			  } i++;	
			  if(!found){
			    j++; 
			  }
		  }
		  if(found){
			  setD.insert(*j);
		  }
		   i++;	
	  } 
	  
  }
  cout << "Intersection:";
  i = setD.begin();
  while(i != setD.end()){
    cout << *i << " " ;
	i++;
  }
  cout << endl;


  //Difference
   set<char> setE;
   i = setA.begin();
   while(i != setA.end()){
	 j = setB.begin();
	 found = false;
	 while(j != setB.end() && found == false){
		 if(*i == *j){
           found = true;
		 }
         j++;
	 }
	 if(!found){
		 setE.insert(*i);
	 }
	 i++;
  }
  cout << "Difference:";
  i = setE.begin();
  while(i != setE.end()){
    cout << *i << " " ;
	i++;
  }
  cout << endl;
 
  system("pause");
  return 0;
}
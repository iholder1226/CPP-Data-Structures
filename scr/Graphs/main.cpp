/*
   ComSc-210 Data Structures
   main.cpp
   @author  Isaiah Holder
   @version 12-02-2010
*/
#include"Graph.h"
#include<iostream>
#include<map>

template<class type>
void BreadthFirstSearch(Graph<type> graph, type startVertex, type endVertex);

int main(){
	//Decalre Array based graph object
	Graph<node> graph(10);


	//Declare a node to hold data as it is added to the graph
	node currentVertex;
    node temp;
	//Add 1st vertext to graph
	currentVertex.value = "Atlanta";
	graph.AddVertex(currentVertex);

	//Add 2nd vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Austin";
	graph.AddVertex(currentVertex);
	//Add edge connecting Atlanta to Austin
	graph.AddEdge(temp,currentVertex,1);

	//Add 3rd vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Chicago";
	graph.AddVertex(currentVertex);
	//Add edge connecting Austin to Chicago
    graph.AddEdge(temp,currentVertex,1);

	//Add 4th vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Dallas";
	graph.AddVertex(currentVertex);
	//Add edge connecting Chicago to Dallas
    graph.AddEdge(temp,currentVertex,1);

	//Add 5th vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Denver";
	graph.AddVertex(currentVertex);
    graph.AddEdge(temp,currentVertex,1);

	//Add 6th vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Houston";
	graph.AddVertex(currentVertex);
	//Add edge connecting Dallas to Houston
    graph.AddEdge(temp,currentVertex,1);

	//Add 7th vertext to graph
	temp.setValue(currentVertex.value);
    currentVertex.value = "Washington";
	graph.AddVertex(currentVertex);
    //Add edge connecting to Houston Washington
    graph.AddEdge(temp,currentVertex,1);
	

	//Get input from user
	node departCity ;
    node destination;
    char* input = new char[20];
	cout << "------------------------------ Array----------------------------------------" << endl
		 << "Please enter the name of your departure city: ";
	cin >> input;
	departCity.setValue(input);
	
    system("cls");
	cout << "------------------------------ Array----------------------------------------" << endl
		 << "Please enter the name of your destination city: ";
	cin >> input;
	destination.setValue(input); 

	system("cls");
	cout << "------------------------------ Array----------------------------------------" << endl
		 <<"Flight Plan" << endl
		 <<"-----------------------------------------------------------------------------" << endl;
	BreadthFirstSearch<node>(graph,departCity,destination);
	cout << endl;
	system("pause");
	

//*********************************** STL MAP *******************************************
  system("cls");
  cout <<"--------------------------------STL MAP------------------------------" << endl;
  map<string, long> directory;
  directory["A"] = 1234567;
  directory["B"] = 9876543;
  directory["C"] = 3459876;

  string name = "A";

  if (directory.find(name) != directory.end()) 
      cout << "The phone number for " << name
           << " is " << directory[name] << "\n";
  else
      cout << "Sorry, no listing for " << name << "\n";
 
  delete [] input;
  system("pause");
  return 0;
}





template<class type>
void BreadthFirstSearch(Graph<type> graph, type startVertex, type endVertex){
  queue<type> queue1;
  queue<type> vertexQ;
   
  bool found = false;
  type vertex;
  type item;

  graph.ClearMarks();
  queue1.push(startVertex);

  do{
	  vertex = queue1.front();
	  queue1.pop();

	  if(vertex == endVertex){
        vertex << vertex;
		found = true;
	  }//if
	  else{
		  if(!graph.IsMarked(vertex)){
			  graph.MarkVertex(vertex);
			  vertex << vertex;
			  cout << "->";
			  graph.GetToVertices(vertex,vertexQ);

			  while(!vertexQ.empty()){
                 item = vertexQ.front();
				 vertexQ.pop();

				 if(!graph.IsMarked(item)){
					 queue1.push(item);
				 }//if
			  }//while
		  }//if
	  }//else

  } while(!queue1.empty() && !found);
  if(!found){
    cout << "\t\t\tPath not found.";
  }
}
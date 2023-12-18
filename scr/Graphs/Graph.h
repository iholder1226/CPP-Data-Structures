/*
   ComSc-210 Data Structures
   Graph.h
   @author  Isaiah Holder
   @version 12-02-2010
*/
#include<queue>
#include<string>
#include<iostream>
using namespace::std;
struct node{
	bool operator==(node otherItem){
		if(strcmp(value,otherItem.value)== 0){
            return true;
		}
		else
			return false;
	}
	bool operator<= (node otherItem){
        if(strcmp(value,otherItem.value)== 0 || strcmp(value,otherItem.value)< 0){
            return true;
		} 
		else
			return false;
	}
	bool operator<(node otherItem){
		if(strcmp(value,otherItem.value)< 0){
             return true;
		}
		else
			return false;
	}
	void operator<<(node otherItem){
		cout << otherItem.value;
	}
	void setValue(char* val){
      value = new char[(sizeof(val)/sizeof(char))];
	  strcpy(value,val);
	}
	char* value;
	
};
template<class type>
class Graph{
public:
	Graph(int maxV = 50);
	~Graph();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	void AddVertex(type);
	void AddEdge(type,type,int);
	int GetWeight(type,type);
	void GetToVertices(type,queue<type>&);
	void ClearMarks();
	void MarkVertex(type);
	bool IsMarked(type);
private:
//	int IndexIs(type);
    int numOfVertices;
	int maxVertices;
    type* vertices;
	int edges[50][50];
	bool* marks;
};

const int NULL_EDGE = 0;
template<class type>
Graph<type>::Graph(int maxV){
  numOfVertices = 0;
  maxVertices = maxV;
  vertices = new type[maxV];
  marks = new bool[maxV];
  for(int i = 0; i < maxV; i++){
    marks[i] = false;
  }
}

template<class type>
Graph<type>::~Graph(){
  //delete [] vertices;
  //delete [] marks;
}
template<class type>
void Graph<type>::AddVertex(type vertex){
  vertices[numOfVertices] = vertex;
  for(int i = 0; i < numOfVertices; i++){
	  edges[numOfVertices][i] = NULL_EDGE;
	  edges[i][numOfVertices] = NULL_EDGE;
  }
  numOfVertices++;
}


//int Graph<type>::
template<class type>
int IndexIs(type* vertices,type vertex){
  int index = 0;
  while(!(vertex == vertices[index])){
     index++;
  }
  return index;
}

template<class type>
void Graph<type>::AddEdge(type fromVertex,type toVertex,int weight){
  int row;
  int col;

  row = IndexIs(vertices,fromVertex);
  col = IndexIs(vertices,toVertex);
  edges[row][col] = weight;
}

template<class type>
int Graph<type>::GetWeight(type fromVertex,type toVertex){
  int row;
  int col;

  row = IndexIs(vertices,fromVertex);
  col = IndexIs(vertices,toVertex);
  return edges[col][row];
}

template<class type>
void Graph<type>::GetToVertices(type vertex, queue<type>& adjVertices){
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertices,vertex);
  for(toIndex = 0; toIndex < numOfVertices; toIndex++){
	if(edges[fromIndex][toIndex] != NULL_EDGE){
       adjVertices.push(vertices[toIndex]);
	}
  }
}






template<class type>
void Graph<type>::ClearMarks(){
  int index;
  for(index = 0; index < numOfVertices; index++){
    marks[index] = false;
  }
}

template<class type>
void Graph<type>::MarkVertex(type vertex){
   int index;

   index = IndexIs(vertices,vertex);
   marks[index] = true;
}

template<class type>
bool Graph<type>::IsMarked(type vertex){
  int index;

  index = IndexIs(vertices,vertex);
  return marks[index];
}

template<class type>
void Graph<type>::MakeEmpty(){
  int index;

  for(index = 0; index < numOfVertices; index++){
    vertices[index]= NULL_EDGE;
  }
}

template<class type>
bool Graph<type>::IsEmpty(){
  return (numOfVertices == 0);
}

template<class type>
bool Graph<type>::IsFull(){
  return (maxVertices == numOfVertices);
}
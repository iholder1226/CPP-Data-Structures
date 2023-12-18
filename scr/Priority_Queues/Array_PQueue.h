/* 
   ComSc-210 Data Structures
   Array_PQueue.h
   ADT:Priority Queue, Templetized
   @author  Isaiah Holder
   @version 11-24-2010
*/

#ifndef _ArrayPQ
#define _ArrayPQ
#endif
#include"Errors.h";

template<class type>
class Array_PQueue{
public:
  Array_PQueue(int max = 1000);
  ~Array_PQueue(void);
  void MakeEmpty(void);
  bool IsEmpty(void);
  bool IsFull(void);
  void Enqueue(type,int);
  type Dequeue(void);
  int GetLength(void);
  void Print(void);
private:
	int currentItem;
	int maxSize;
	int length;
	type* PQ;
  
};
template<class type>
Array_PQueue<type>::Array_PQueue(int max){
	maxSize = max;
    PQ = new type[maxSize];
	currentItem = 0; 
	length = 0;
}

template<class type>
Array_PQueue<type>::~Array_PQueue(){
    delete [] PQ;
}
template<class type>
void Array_PQueue<type>::MakeEmpty(){
  PQ = NULL;
  currentItem = 0;
  length = 0;
}
template<class type>
bool Array_PQueue<type>::IsEmpty(){
  return length == 0;
}
template<class type>
bool Array_PQueue<type>::IsFull(){
  return length == (maxSize-1);
}
template<class type>
void Array_PQueue<type>::Enqueue(type newItem,int right){
	try{
		if(IsFull()){
          throw FullQueue();
		}
	}
	catch(FullQueue){
      cout << "Queue Is Full!" << endl;
	  system("pause");
	  return;
	}
	if(IsEmpty()){
      PQ[currentItem] = newItem;
	  length++;
	  return;
	}
	int pivot = PQ[(currentItem + right)/2];
	if(newItem > pivot){
	  if(PQ[currentItem] == pivot){
		type temp;
		currentItem++;
		length++;
		while(currentItem < length){
			temp = PQ[currentItem];
            PQ[currentItem++] = newItem;
			newItem = temp;
		}
		currentItem = 0;
	    return;
	  }
	  else{
        currentItem = (currentItem+right)/2;
		Enqueue(newItem,right);
	  }
	}
	else if(newItem < pivot){
		if(currentItem == right){
			type temp;
			//Insert item then resort remainder of the list
			length++;
			while(currentItem < length){
				temp = PQ[currentItem];
                PQ[currentItem++] = newItem;
				newItem = temp;
			}
		    currentItem = 0;
            return;
		}
		else
            Enqueue(newItem,(currentItem + right)/2);
	}
	else{
        PQ[currentItem] = newItem;
		currentItem = 0;
		return;
	}
}
template<class type>
type Array_PQueue<type>::Dequeue(void){
  return PQ[--length];
}
template<class type>
int Array_PQueue<type>::GetLength(){
  return length;
}
template<class type>
void Array_PQueue<type>::Print(void){
	while(currentItem < length){
      cout << PQ[currentItem++] << endl;
	  
	}
	if(length == 0){
      cout << "List is empty." << endl;
	}
}
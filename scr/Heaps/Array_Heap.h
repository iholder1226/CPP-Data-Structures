/*
   ComSc-210 Data Structures Lab9
   Array_Heap.h
   @author  Isaiah Holder
   @version 11-24-2010*/

template<class type>
struct Array_Heap{
  void ReHeapUp(int root, int bottom);
  void ReHeapDown(int root, int bottom);
  type* elements;
  int length;
};

template<class type>
void Array_Heap<type>::ReHeapDown(int root, int bottom){
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if(leftChild <= bottom){
	  if(leftChild == bottom){
        maxChild = leftChild;
	  }
	  else{
		  if(elements[leftChild] <= elements[rightChild]){
             maxChild = rightChild;
		  }
		  else
			 maxChild = leftChild;
	  }
	  if(elements[root] < elements[maxChild]){
         type temp = elements[root];
		 elements[root] = elements[maxChild];
		 elements[maxChild] = temp;
		 ReHeapDown(maxChild,bottom);
	  }
  }
}
template<class type>
void Array_Heap<type>::ReHeapUp(int root, int bottom){
    int parent;

	if(bottom > root){
      parent = (bottom-1)/2;
	  if(elements[parent] < elements[bottom]){
	    type temp = elements[parent];
		elements[parent] = elements[bottom];
		elements[bottom] = temp;
        ReHeapUp(root,parent);
	  }
	}
}
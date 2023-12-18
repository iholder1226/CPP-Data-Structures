
template<class type>
class Set{
public:
  Set(int max =25);
  ~Set();
  void MakeEmpty();
  void Store(type item);
  void Delete(type item);
  bool IsEmpty();
  bool IsFull();
  int CardinalityIs();
  Set Union(Set setB);
  Set Intersection(Set setB);
  Set Difference(Set setB);
  type getCurrentItem();
  void getNextItem();
  void Print();
  void Reset();
private:
  type* items;
  int length;
  int maxSize;
  int currentItem;
	
};
template<class type>
Set<type>::Set(int max ){
  items = new type[max];
  maxSize = max;
  length =0;
  currentItem = 0;
}
template<class type>
Set<type>::~Set(){
  //delete [] items;
}
template<class type>
void Set<type>::MakeEmpty(){
	for(int i = 0; i < length; i++){
       items[i] = NULL;
	}
}
template<class type>
void Set<type>::Store(type item){
	bool found = false;
	for(int i = 0; i < length; i++){
		if(items[i] == item){
          found = true;
		}
	}
	if(!found){
      items[length++] = item;
	}
}
template<class type>
void Set<type>::Delete(type item){
    bool found = false;
	int i =0;
	while(!found && i < length){
		if(items[i] == item){
           found = true;
		}
		i++;
	}
	if(found){
		while(i < length){
          items[i] = items[i++];
		}
		length--;
	}
}

template<class type>
bool Set<type>::IsEmpty(){
  return (length == 0);
}
template<class type>
bool Set<type>::IsFull(){
  return (length == maxSize);
}
template<class type>
int Set<type>::CardinalityIs(){
  return length;
}

template<class type>
Set<type> Set<type>::Union(Set setB){
  Set setC;
  int i = 0;
  while(i < length){
	  setC.Store(items[i++]);
  }
  i=0;
  while(i < setB.CardinalityIs()){
	  setC.Store(setB.getCurrentItem());
	  setB.getNextItem();
	  i++;
  }
  return setC;
}
template<class type>
Set<type> Set<type>::Intersection(Set setB){
  Set setC;
  int i = 0;
  int j ;
  bool found;
  if(length >= setB.CardinalityIs()){
	  while(i < length){
		  j=0;
		  setB.Reset();
		  found = false;
		  while(j < setB.CardinalityIs() && !found){
			  if(items[i]== setB.getCurrentItem()){
                 found = true;
			  }
			  j++;
			  if(found == false){
			    setB.getNextItem();
			  }
		  }
		  if(found){
			  setC.Store(setB.getCurrentItem());
		  }
		  i++;
	  }
	  setB.Reset();
  }
  else{
	  while(i < setB.CardinalityIs()){
		  while(j < length && !found){
			  if(items[i]== setB.getCurrentItem()){
                 found = true;
			  }
			  j++;
		      i++;	  
		  }
		  if(found){
			  setC.Store(setB.getCurrentItem());
		  }
		  setB.getNextItem();
	  } 
	  setB.Reset();
  }
  return setC;
}

template<class type>
Set<type> Set<type>::Difference(Set setB){
  Set<type> setC;
  bool found;
  int i = 0;
  int j;
  while(i < length){
     j = 0;
	 found = false;
	 setB.Reset();
	 while(j < setB.CardinalityIs() && found == false){
		 if(items[i] == setB.getCurrentItem()){
           found = true;
		 }
		 setB.getNextItem();
         j++;
	 }
	 if(!found){
		 setC.Store(items[i]);
	 }
	 i++;
  }
  return setC;
}
template<class type>
type Set<type>::getCurrentItem(){
  return items[currentItem];
}
template<class type>
void Set<type>::getNextItem(){
	currentItem++;
}
template<class type>
void  Set<type>::Print(){
	int i = 0;
	while(i < length){
      cout << getCurrentItem() << " ";
      getNextItem();
	  i++;
	}
	Reset();
}
template<class type>
void Set<type>::Reset(){
  currentItem = 0;
}
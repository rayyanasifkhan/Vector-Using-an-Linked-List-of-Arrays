#pragma once

#include <iostream>  // print debugging
#include <cstdlib>   // malloc, free

using namespace std;

const int arraySize = 100;

template<typename T>
class myvector
{
private:

	struct Node {
	 
	 Node* pNext;
	 T A[arraySize];
	};
	
	int  Size;
	
	Node* Head;
	Node* Tail;

public:
	// default constructor:
	myvector()
	{       
	 Head = NULL;
	 Tail = NULL;
	 
	 Size = 0;
	}


    // constructor with initial size:
	myvector(int initial_size) 
	{   
	  	Head = NULL;
	  	Tail = NULL;
	  	Size = 0;
	  	
	  	for(int i = 0; i < initial_size; i++) {
	  		push_back(T{});
		}
	}


	// copy constructor for parameter passing:
	myvector(const myvector& other)
	{
     Node* pTemp = other.Head;
     Head = NULL;
     Tail = NULL;
     
     while (pTemp != NULL) {
     	for(int i = 0; i < arraySize; i++) {
        	push_back(pTemp->A[i]);
    	}
    	pTemp = pTemp->pNext;
     }
     
     Size = other.Size;
	
	}


	//returns the number of elements in the vector
	int size()
	{
	return Size;
	}

	//returns the value of element present at index i
	T& at(int i)
	{
	Node* pTemp = Head;
	
	for(int x = 0; x < (i / arraySize); x++) {
	   pTemp = pTemp->pNext;
	}    
	return pTemp->A[(i % arraySize)];
	}


	//adds value to the end of the vector
	void push_back(T value)
	{
	 if(Size == 0) { // I had Tail == NULL && Head == NULL which didn't make erase take this conditional statement. This will work if erase chunk of code in uncommented
	    Head = new Node;
	    Head->A[0] = value;
	    Tail = Head;
	 }
	 
	 else {
	 	if((Size % arraySize) != 0) {
	       Tail->A[(Size % arraySize)] = value;
	    }
	    else {
	       Node* pTemp = new Node;
	       Tail->pNext = pTemp;
	       pTemp->A[0] = value;
	       Tail = pTemp;
	    }
	 }
	 Size++;
	}
  
  	//an alternative to at()
	T& operator [] (int i) {
		return at(i);
	}

	//returns the value at index i
	T erase(int i) {
		
		T value = at(i);
		
		for(int y = i; y < Size - 1; y++) { 
			at(y) = at(y + 1);
		}
		at(Size - 1) = T{}; 
	
		if((Size % arraySize) == 1) {
			Node* pTemp = Head;
			
			for(int x = 0; x < ((Size / arraySize) - 1); x++) {
				pTemp = pTemp->pNext;
			}
			
			Tail = pTemp;
			Tail->pNext = NULL;
		}
		
		Size--;
		return value;
	}
	
	//returns an array of elements in range i-j;
	T* rangeof(int i, int j) {
		
		T* elementsArr = new T[j - i + 1];
		
		for(int x = i; x <= j; x++) {
			elementsArr[x - i] = at(x);
		}
		
		return elementsArr;
	}

};

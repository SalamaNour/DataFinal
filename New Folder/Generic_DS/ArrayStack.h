//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackADT.h"



template<typename ItemType> 
class ArrayStack : public StackADT<ItemType>
{
	enum { STACK_SIZE = 100 };		//max stack size.
private:
	ItemType items[STACK_SIZE];		// Array of stack items
	int      top;                   // Index to top of stack
	
public:
	 ArrayStack();                 // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop(ItemType& TopEntry);
	 bool peek(ItemType& TopEntry) const;
}; // end ArrayStack



template<typename ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<typename ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty

template<typename ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if( top == STACK_SIZE-1 ) return false;

	top++;
	items[top] = newEntry;   
	return true;
}  // end push

template<typename ItemType>
bool ArrayStack<ItemType>::pop(ItemType& TopEntry)
{

	if (isEmpty()) return false;
		
	TopEntry = items[top];		 
	top--;
	return true;

}  // end pop

template<typename ItemType>
bool ArrayStack<ItemType>::peek(ItemType& TopEntry) const
{
	if (isEmpty()) return false;
		
	TopEntry = items[top];		 
	return true;
}  // end peek


#endif

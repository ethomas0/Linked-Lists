#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string.h>
#include <iostream>
#include "Child.h"
#include <vector>


template <typename dataType>
class LinkedList
{
	template<class T1>
	friend std::ostream& operator << (std::ostream &output, const LinkedList<T1> &toStream);
	

public:
	LinkedList(); 
	LinkedList(const LinkedList& list); 
	~LinkedList();

	bool BuildList(const std::string& fileName);
	bool Insert(dataType* object);
	bool Remove(const dataType& target, dataType& result);
	bool Peek(const dataType& target, dataType& result) const;
	void DeleteList();
	bool Merge(LinkedList& list2); // I know it is not pretty, but in my defense my goal was to transfer as many nodes as possible each loop
	void Insert(std::vector<dataType> data); // this was for testing so that I did not need to pass one value at a time

	bool isEmpty() const;
	

	LinkedList operator+(const LinkedList& rvalue)const; 
	LinkedList& operator+=(const LinkedList& rvalue); 
	bool operator==(const LinkedList& rvalue) const;
	bool operator!=(const LinkedList& rvalue) const; 
	LinkedList operator=(const LinkedList& list);
	
	

private:
	struct Node
	{
		dataType* data;
		Node* next;
		
	};
	void resetIterator()const;
	void push_back(dataType* value);
	Node* head;
	Node* tail;
	mutable Node* it;
	

	
};


#include "LinkedList.cpp"
#endif



#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LinkedList.h"
#include <iostream>


template<typename dataType>
LinkedList<dataType>::LinkedList() : head(nullptr), tail(nullptr), it(nullptr)
{

}

template<typename dataType>
LinkedList<dataType>::LinkedList(const LinkedList& list)
{
	list.resetIterator();
	head = nullptr;
	tail = nullptr;
	
	
	while (list.it != nullptr)
	{
		push_back(list.it->data);
		list.it = list.it->next;
	}

		
}

template<typename dataType>
LinkedList<dataType>::~LinkedList()
{
	DeleteList();
}

template<typename dataType>
bool LinkedList<dataType>::BuildList(const std::string& fileName)
{
	dataType temp;
	std::ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (inFile >> temp)
		{
			this->Insert(&temp);
		}

		inFile.close();
		inFile.clear();
		return true;
	}
	else
	{
		std::cout << "\nError opening file.\n";
		return false;
	}
}

template<typename dataType>
bool LinkedList<dataType>::Insert(dataType* object)
{
	resetIterator();	
	bool insertCheck = false;

	if (isEmpty())
	{
		
		Node* temp = new Node;
		temp->data = new dataType(*object);
		temp->next = nullptr;
		head = temp;
		tail = temp;
		insertCheck = true;
	}
	else if (*object < *head->data)
	{
		Node* temp = new Node;
		temp->data = new dataType(*object);
		temp->next = nullptr;
		temp->next = head;
		head = temp;
		insertCheck = true;
	}
	else if (*object > *tail->data)
	{
		Node* temp = new Node;
		temp->data = new dataType(*object);
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
		insertCheck = true;
	}
	else
	{
		while (it != nullptr && *object > *it->next->data)
		{
			it = it->next;
		}
		if (*object != *(it->data) && *object != *(it->next->data))
		{
			Node* temp = new Node;
			temp->data = new dataType(*object);
			temp->next = nullptr;
			temp->next = it->next;
			it->next = temp;
			insertCheck = true;
		}
	}
	resetIterator();
	return insertCheck;
}

template<typename dataType>
bool LinkedList<dataType>::Remove(const dataType& target, dataType& result)
{
	resetIterator();
	Node* temp = head;
	bool found = false;

	while (it != nullptr && target > *(it->data))
	{
		it = it->next;
	}
	if (it != nullptr && *(it->data) == target)
	{
		if (it == head)
		{
			head = it->next;
			result = *(it->data);
			found = true;
			delete it->data;
			delete it;
		}

		else if (it == tail)
		{
			while (temp->next != it)
			{
				temp = temp->next;
			}

			tail = temp;
			temp->next = nullptr;
			result = *(it->data);
			found = true;
			delete it->data;
			delete it;
		}
		else
		{
			while (temp->next != it)
			{
				temp = temp->next;
			}

			temp->next = it->next;
			result = *(it->data);
			found = true;
			delete it->data;
			delete it;
		}		
	}

	resetIterator();
	return found;
}

template<typename dataType>
bool LinkedList<dataType>::Peek(const dataType& target, dataType& result) const
{
	resetIterator();
	bool found = false;

	

	while (it != nullptr && target > *(it->data))
	{
		it = it->next;
	}
	if (it != nullptr && *(it->data) == target)
	{

		result = *(it->data);
		found = true;

	}
	resetIterator();
	return found;
}

template<typename dataType>
void LinkedList<dataType>::DeleteList()
{
	resetIterator();
	
	while (it != nullptr)
	{
		head = head->next;
		delete it->data;
		delete it;
		it = head;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->it = nullptr;
	
}

template<typename dataType>
bool LinkedList<dataType>::Merge(LinkedList& list2)
{
	resetIterator();
	list2.resetIterator();
	Node *list1Ptr = this->it;
	bool mergeCompleted = false;
	
	if (list2.head != nullptr && this->head == nullptr) //list1 is empty, but not list2
	{
		this->head = list2.head;
		this->tail = list2.tail;
		list2.head = list2.tail = list2.it = nullptr;
		
		mergeCompleted = true;
	}
	else if (this->head != list2.head && *this == list2) // list1 and list2 are the same, but have different address locations 
	{
		
		list2.DeleteList();
		mergeCompleted = true;

	}
	else if(this->head != list2.head && list2.head != nullptr)
	{
		
		if (*(list2.head->data) < *(this->head->data)) //deciding where my head should start
		{
			this->head = list2.head;
		}

		while (this->it != nullptr && list2.head != nullptr && !mergeCompleted)
		{
			if (*(list2.head->data) < *(this->it->data))// list2 value is less than list1
			{
				while (list2.head->next != nullptr && *(list2.head->next->data) < *(this->it->data)) //moving list2 head forward
				{
					list2.head = list2.head->next;
				}

				if (list2.head == list2.tail) //reached end of list2
				{
					while (list1Ptr->next != nullptr && *(list1Ptr->next->data) < *(list2.it->data))//moving list1 trailing ptr forward
					{
						list1Ptr = list1Ptr->next;
					}
					if (*(list1Ptr->data) > *(list2.head->data))//deciding to put the data before or after list1 trailing ptr
					{
						list2.head->next = this->it;
						list2.head = list2.tail = list2.it = nullptr;
						mergeCompleted = true;
					}
					else
					{
						list1Ptr->next = list2.it;
						list2.head->next = this->it;
						list2.head = list2.tail = list2.it = nullptr;
						mergeCompleted = true;
					}
					
				}
				else if (*(list2.head->data) < *(list1Ptr->data)) //list2 trailing pointer needs to move up
				{
					list2.it = list2.head;
					list2.head = list2.head->next;
					list2.it->next = this->it;
					list2.it = list2.head;
				}
				else if (*(list2.head->data) > *(list1Ptr->data)) //list2 trailing pointer should move pointers before moving up
				{
					list1Ptr->next = list2.it;
					list1Ptr = this->it;
					list2.it = list2.head;
					list2.head = list2.head->next;
					list2.it->next = this->it;
					list2.it = list2.head;
				}

				
			}
			else if (*(list2.head->data) == *(this->it->data)) // list2 data equals list1
			{
				list2.head = list2.head->next;
				delete list2.it->data;
				delete list2.it;
				list2.it = list2.head; 
			}
			else //list2 value is greater than list1 value, need to move list1 pointer forward
			{
				while (this->it != nullptr && *(this->it->data) < *(list2.head->data))
				{
					this->it = this->it->next;
				}
			}
		}
		if (list2.head != nullptr)//checking if anything is left over in list2
		{
			this->tail->next = list2.head;
			this->tail = list2.tail;
		}
		list2.head = list2.tail = list2.it = nullptr;
		mergeCompleted = true;
	}
	return mergeCompleted;
}

template<typename dataType>
void LinkedList<dataType>::Insert(std::vector<dataType> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		this->Insert(&(data[i]));
	}
}

template<typename dataType>
bool LinkedList<dataType>::isEmpty() const
{
	return (head == nullptr);
}



template<typename dataType>
LinkedList<dataType> LinkedList<dataType>::operator+(const LinkedList& rvalue) const
{
	this->resetIterator();
	rvalue.resetIterator();

	LinkedList<dataType> temp;

	while (this->it != nullptr)
	{
		temp.Insert(this->it->data);
		this->it = this->it->next;
	}

	while (rvalue.it != nullptr)
	{
		temp.Insert(rvalue.it->data);
		rvalue.it = rvalue.it->next;
	}

	this->resetIterator();
	rvalue.resetIterator();
	return temp;
}

template<typename dataType>
LinkedList<dataType> &LinkedList<dataType>::operator+=(const LinkedList& rvalue)
{
	
	*this = *this + rvalue;
	return *this;
}

template<typename dataType>
bool LinkedList<dataType>::operator==(const LinkedList& rvalue) const
{
	bool comparison = false;
	bool areEqual = true;
	resetIterator();
	rvalue.resetIterator();
	
	if (!this->isEmpty() && !rvalue.isEmpty())
	{
		while ( this->it != nullptr &&  rvalue.it != nullptr && areEqual)
		{
			if ( *(this->it->data) != *(rvalue.it->data))
			{
				areEqual = false;
			}

			
			this->it = this->it->next;
			rvalue.it = rvalue.it->next;
		}
	}

	if (areEqual &&  this->it == nullptr &&  rvalue.it == nullptr)
	{
		comparison = true;
	}
	else if (this->isEmpty() && rvalue.isEmpty())
	{
		comparison = true;
	}
	
	resetIterator();
	rvalue.resetIterator();
	return comparison;
}

template<typename dataType>
bool LinkedList<dataType>::operator!=(const LinkedList& rvalue) const
{
	return !(*this == rvalue);
}

template<typename dataType>
LinkedList<dataType> LinkedList<dataType>::operator=(const LinkedList& list)
{
	list.resetIterator();
	if (!this->isEmpty())
	{
		this->DeleteList();
	}
	


	while (list.it != nullptr)
	{
		push_back(list.it->data);
		list.it = list.it->next;
	}

	list.resetIterator();

	return *this;

}





template<typename dataType>
void LinkedList<dataType>::resetIterator()const
{
	
	this->it = this->head;
}

template<typename dataType>
void LinkedList<dataType>::push_back(dataType* value)
{
	Node* temp = new Node;
	temp->data = new dataType(*value);
	temp->next = nullptr;	
	
	

	if (head !=nullptr)
	{
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = temp;
		tail = temp;
	}
	
	
}

template<typename dataType>
std::ostream &operator<<(std::ostream & output, const LinkedList<dataType>& toStream)
{
	typename LinkedList<dataType>::Node *curr = toStream.head;
	while (curr != nullptr)
	{
		output << *(curr->data);
		curr = curr->next;
	}
	return output;
}



#endif // !LinkedList_CPP

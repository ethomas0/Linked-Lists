#include "LinkedList.h"
#include <iostream>
#include <string>
#include "Child.h"
using namespace std;

int main()
{
	//this is all just testing of my merge, print, insert, delete using the insert function that takes a vector
	//also test reading in a file for child class
	/*LinkedList<int> list, list2;
	if (!list.Merge(list2))
	{
		cout << "Merging two empty lists is working" << endl;
	}
	else
	{
		cout << "Merging two empty lists is not working" << endl;
	}


	list2.insert({ 0, 10, 20, 30, 40 });

	

	cout << "Merging list an empty list" << endl;
	cout << "With list2: " << list2 << endl;
	if (list.Merge(list2))
	{
		cout << "This merge is working" << endl;
		cout << list << endl;
	}
	else
	{
		cout << "This merge is not working" << endl;
	}
	
	list.DeleteList();
	list2.DeleteList();

	list.insert( { 0, 5, 10, 15, 20, 25, 30, 35, 40} );	

	cout << "Merging list: " << list << endl;
	cout << "With list2 an empty list" << endl;
	
	if (!list.Merge(list2))
	{
		cout << "This merge is working" << endl;
		cout << list << endl;
	}
	else
	{
		cout << "This merge is not working" << endl;
	}

	list.DeleteList();
	list2.DeleteList();
	
	list.insert({ 1, 3, 40, 47, 54, 61, 68 });

	list2.insert({ 0, 3, 6, 9, 12, 15, 18 });

	cout << "Merging list: " << list << endl;
	cout << "With list2: " << list2 << endl;

	if (list.Merge(list2))
	{
		cout << "This merge is working: " << list << endl;
	}
	else
	{
		cout << "This merge is not working" << endl;
	}

	list.DeleteList();
	list2.DeleteList();

	list.insert({ 10, 17, 21, 28 });

	list2.insert({ 50, 53, 56, 59, 62, 65 });
	int test = 56;
	if (list2.Insert(&test))
	{
		cout << "Duplicate Error" << endl;
	}
	else
	{
		cout << "Its not your inserts problem" << endl;
	}

	cout << "Merging list: " << list << endl;
	cout << "With list2: " << list2 << endl;

	if (list.Merge(list2))
	{
		cout << "This merge is working: " << list << endl;
	}
	else
	{
		cout << "This merge is not working" << endl;
	}

	list.DeleteList();
	list2.DeleteList();

	list.insert({ 0, 9, 18, 27 });

	list2.insert({ -6, -4, -2, 0, 2, 4, 6, 8, 10, 12, 16,
					 18, 20, 22, 24, 27, 28, 30, 32, 34 });

	cout << "Merging list: " << list << endl;
	cout << "With list2: " << list2 << endl;

	if (list.Merge(list2))
	{
		cout << "This merge is working: " << list << endl;
	}
	else
	{
		cout << "This merge is not working" << endl;
	}
	
	list.Merge(list);
	list.DeleteList();
	list2.DeleteList();
	LinkedList<Child> list3;
	list3.BuildList("test.txt");
	cout << list3 << endl;*/

	//Once i felt that my class was ready, I used this to test it:

	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
	LinkedList<Child> class1, class2, soccer, chess;
	int a = 1, b = -1, c = 13;
	class1.Insert(&c1); 
	class1.Insert(&c2); 
	class1.Insert(&c3); 
	class1.Insert(&c4); 
	class1.Insert(&c5); 
	class1.Insert(&c6); 
	class1.Insert(&c5);
	cout << "class1: " << class1 << endl; 
	if (class1.Insert(&c1))
	{ 
		cout << "ERROR::: Duplicate" << endl; 
	}
	class2.Insert(&c4); 
	class2.Insert(&c5); 
	class2.Insert(&c6); 
	class2.Insert(&c7); 
	class2.Insert(&c10); 
	cout << "Class2: " << class2 << endl; 
	class1.Merge(class2); 
	class2.Merge(class1); 
	class1.Merge(class2); 
	class1.Merge(class1); 
	cout << "class1 and 2 Merged: " << class1 << endl; 
	if (!class2.isEmpty())
	{
		cout << "ERROR:: Class2 should be empty empty" << endl; 
	}
	class1.Remove(c4, c11); 
	class1.Remove(c5, c11); 
	class1.Remove(c11, c11);
	if (class1.Remove(c1, c11)) 
	{
		cout << "Removed from class1, student " << c11 << endl;
	}
	cout << "class1: " << class1 << endl; 
	soccer.Insert(&c6); 
	soccer.Insert(&c4); 
	soccer.Insert(&c9); 
	cout << "soccer: " << soccer << endl;
	soccer += class1; 
	cout << "soccer += class1 : " << soccer << endl; 
	LinkedList<Child> football = soccer; 
	if (football == soccer) 
	{
		cout << "football: " << football << endl;
	}
	if (football.Peek(c6, c11)) 
	{
		cout << c11 << " is on the football team" << endl;
	}
	soccer.DeleteList(); 
	if (!soccer.isEmpty()) 
	{ 
		cout << "ERROR: soccer should be empty" << endl;
	}
	LinkedList<int> numbers;
	numbers.Insert(&a); 
	numbers.Insert(&b); 
	numbers.Insert(&c); 
	cout << "These are the numbers: " << numbers << endl;
	numbers.DeleteList();

	return 0;
}

//failing on merge 7;
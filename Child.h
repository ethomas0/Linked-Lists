#ifndef _CHILD_H_
#define _CHILD_H_

#include <string>
#include <iostream>
#include <fstream>

class Child
{
public:
	friend std::ostream& operator << (std::ostream &out, const Child& toStream);
	friend std::istream& operator >> (std::istream &in, Child& fromStream);

	Child();
	Child(const std::string& first, const std::string& last, const int& age);
	~Child();

	bool operator==(const Child& rvalue) const;
	bool operator!=(const Child& rvalue)const;
	bool operator<(const Child& rvalue) const;
	bool operator>(const Child& rvalue) const;
	

private:
	std::string first, last;
	int age;

};

#endif
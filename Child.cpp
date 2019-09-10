#include "Child.h"

Child::Child() : first(""), last(""), age(-1)
{
}

Child::Child(const std::string& first, const std::string& last, const int& age) 
	: first(first), last(last), age(age)
{
}

Child::~Child()
{
}

bool Child::operator==(const Child& rvalue) const
{
	return (this->age == rvalue.age && this->first == rvalue.first && this->last == rvalue.last);
}

bool Child::operator!=(const Child & rvalue) const
{
	return !(*this == rvalue);
}

bool Child::operator<(const Child& rvalue) const
{
	
	if (this->last == rvalue.last)
	{
		if (this->first == rvalue.first)
		{
			return (this->age < rvalue.age);
		}
			
		else
		{
			return (this->first < rvalue.first);
		}
			
	}
	else
	{
		return (this->last < rvalue.last);
	}
		

	
		
}

bool Child::operator>(const Child& rvalue) const
{
	//return (this->age > rvalue.age && this->first > rvalue.first && this->last > rvalue.last);
	if (this->last == rvalue.last)
	{
		if (this->first == rvalue.first)
		{
			return (this->age > rvalue.age);
		}

		else
		{
			return (this->first > rvalue.first);
		}

	}
	else
	{
		return (this->last > rvalue.last);
	}

}

std::ostream& operator << (std::ostream &out, const Child& toStream)
{
	out << toStream.first << toStream.last << toStream.age;
	return out;
}
std::istream& operator >> (std::istream &in, Child& fromStream)
{
	in >> fromStream.first >> fromStream.last >> fromStream.age;
	return in;
}
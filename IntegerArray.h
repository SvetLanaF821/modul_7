#pragma once
#define INTARRAY_H
#include "Bad_length.h"
#include "Bad_range.h"

class IntegerArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntegerArray();
	IntegerArray(int length);
	IntegerArray(const IntegerArray& a);
	~IntegerArray();	

	void erase();	

	int& operator[](int index);	

	void reallocate(int newLength);
	
	void resize(int newLength);	

	IntegerArray& operator=(const IntegerArray& a);	

	void insertBefore(int value, int index);	

	void remove(int index);

	void insertAtBeginning(int value);
	void insertAtEnd(int value);

	int getLength() const;
};
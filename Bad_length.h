#pragma once
#include <iostream>

// Исключения для неправильной длины массива
class Bad_length : public std::exception
{
public:
	virtual const char* what() const noexcept override;	
};
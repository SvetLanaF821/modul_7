#pragma once
#include <iostream>

// Исключения для выхода за пределы массива
class Bad_range : public std::exception
{
public:
	virtual const char* what() const noexcept override;	
};
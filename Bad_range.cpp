#include "Bad_range.h"

const char* Bad_range::what() const noexcept 
{
	return "Ошибка: выход за пределы массива";
}
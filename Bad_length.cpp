#include "Bad_length.h"

const char* Bad_length::what() const noexcept
{
	return "Ошибка: неправильная длина массива";
}
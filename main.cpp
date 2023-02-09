#include <iostream>
#include <exception>
#include "IntegerArray.h"

int main()
{
	setlocale(LC_ALL, "");
	
	try
	{
		// Объявляем массив из -10 элементов
		IntegerArray array(-10);
	}
	catch (std::exception& exceptionBadLength)
	{
		std::cout << "Массив array(-10):\t" << exceptionBadLength.what() << "\n\n" << std::endl;
	}

	// Объявляем массив из 10 элементов
	IntegerArray array(10);

	// Заполняем массив числами от 1 до 10
	for (int i{ 0 }; i < 10; ++i)
		array[i] = i + 1;

	try
	{
		std::cout << array[13] << std::endl;
	}
	catch (std::exception& exceptionBadLength)
	{
		std::cout << "Элемент массива array[13]: " << exceptionBadLength.what() << "\n\n" << std::endl;
	}
		
	try
	{
		// Вставляем число 7 перед элементом с индексом 15
		array.insertBefore(7, 15);
	}
	catch (std::exception& exceptionBadLength)
	{
		std::cout << "Элемент массива array[15]: " << exceptionBadLength.what() << "\n\n" << std::endl;
	}

	try
	{
		// Удаляем элемент с индексом 19
		array.remove(19);
	}
	catch (std::exception& exceptionBadLength)
	{
		std::cout << "Элемент массива array[19]: " << exceptionBadLength.what() << "\n\n" << std::endl;
	}
	
	// Изменяем размер массива до 8 элементов
	array.resize(8);

	// Добавляем 30 и 40 в конец и начало массива
	array.insertAtEnd(30);
	array.insertAtBeginning(40);

	// Несколько тестов, чтобы убедиться, что копирование построено/назначено, ничего не ломает
	{
		IntegerArray b{ array };
		b = array;
		b = b;
		array = array;
	}

	// Вывод всех элементов массива
	for (int i{ 0 }; i < array.getLength(); ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';

	return 0;
}
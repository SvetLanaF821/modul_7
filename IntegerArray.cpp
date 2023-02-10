#include "IntegerArray.h"

IntegerArray::IntegerArray() = default;

IntegerArray::IntegerArray(int length) : m_length{ length }
{	
	if (length < 0)
	{
		throw Bad_length();
	}
	if (length > 0)
		m_data = new int[length] {};
}

IntegerArray::IntegerArray(const IntegerArray& a)
{
	// Устанавливаем размер нового массива 
	reallocate(a.getLength());

	// Затем копируем элементы
	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];
}

IntegerArray::~IntegerArray()
{
	delete[] m_data;
}

void IntegerArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= m_length)
	{
		throw Bad_range();
	}
	return m_data[index];
}

// Изменяем размер массива. Все существующие элементы будут уничтожены. Эта функция работает быстро.
void IntegerArray::reallocate(int newLength)
{
	// Удаляем все существующие элементы
	erase();
	
	if (newLength <= 0)
		return;

	// Выделяем новые элементы
	m_data = new int[newLength];
	m_length = newLength;
}

// resize изменяет размер массива. Все существующие элементы будут сохранены. Эта функция работает медленно.
void IntegerArray::resize(int newLength)
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data{ new int[newLength] };

	// Копируем столько элементов, сколько есть в меньшем из двух массивов.
	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
		return *this;

	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];

	return *this;
}

void IntegerArray::insertBefore(int value, int index)
{
	// Проверяем правильность нашего значения индекса
	if (index < 0 || index > m_length)
	{
		throw Bad_range();
	}
	// Создаем новый массив на один элемент больше, чем старый массив
	int* data{ new int[m_length + 1] };

	// Копируем все элементы до индекса
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	// Вставляем наш новый элемент в новый массив
	data[index] = value;

	// Копируем все значения после вставленного элемента
	for (int after{ index }; after < m_length; ++after)
		data[after + 1] = m_data[after];

	// Удаляем старый массив и используем вместо него новый 
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntegerArray::remove(int index)
{
	// Проверяем правильность нашего значения индекса
	if (index < 0 || index >= m_length)
	{
		throw Bad_range();
	}
	if (m_length == 1)
	{
		erase();
		return;
	}

	// Создаем новый массив на один элемент меньше, чем старый массив
	int* data{ new int[m_length - 1] };

	// Копируем все элементы до индекса
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	// Копируем все значения после удаленного элемента
	for (int after{ index + 1 }; after < m_length; ++after)
		data[after - 1] = m_data[after];

	// Удаляем старый массив и используем вместо него новый массив
	delete[] m_data;
	m_data = data;
	--m_length;
}

// Добавление элемента в начало массива
void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); }

// Добавление элемента в конец массива
void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); }

int IntegerArray::getLength() const { return m_length; }
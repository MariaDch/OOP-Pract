#include "String.h"
#include <iostream>
#include <cstring>

void String::copy(const String& other_string)
{
	array = new char[other_string.capacity];
	strcpy_s(array, other_string.size + 1, other_string.array);
	size = other_string.size;
	capacity = other_string.capacity;
	if (size >= capacity)
		resize();
}

void String::erase()
{
	delete[] array;
}

String::String()
{
	capacity = 2;
	size = 1;
	array = new char[capacity];
	array[0] = '\0';
}

String& String::operator=(const char* other_array) //?????????????????
{
		erase();
		array = new char[strlen(other_array) + 1];
		strcpy_s(array,strlen(other_array)+1, other_array);
	return *this;
}

String::~String()
{
	erase();
}

String::String(const String& other_string)
{
	copy(other_string);
}

void String::setArray(const char* _array)
{
	erase();
	size = strlen(_array);
	array = new char[size + 1];
	strcpy_s(array, size + 1, _array);
}

void String::setCapacity(size_t _capacity)
{
	capacity = _capacity;
}

void String::setSize(size_t _size)
{
	size = _size;
}

const char* String::getArray() const
{
	return array;
}

size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::resize()
{
	capacity = size;
	capacity *= 2;
	char* biggerArray = new char[capacity];

	for (size_t i = 0; i < size; i++)
	{
		biggerArray[i] = array[i];
	}
	
	erase();
	array = biggerArray;
}

void String::add(char newSymbol)
{
	if (size >= capacity)
	{
		resize();
	}

	array[size] = newSymbol;
	array[size+1] = '\0';
}

size_t String::getLength()
{
	size = strlen(array);
	return size;
}

void String::insertAt(size_t index, char symbol)
{
	if (size >= capacity)
	{
		resize();
	}

	for (size_t i = size; i >= index; i--)
	{
		array[i] = array[i-1];
	}
	
	array[index-1] = symbol;
	size++;
	array[size] = '\0';
}

void String::removeAt(size_t index)
{
	for (size_t i = index-1; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
	array[size] = '\0';
}

void String::trimStart()
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
	array[size] = '\0';
}

void String::trimEnd()
{
	size--;
	array[size] = '\0';
}

void String::trimStart(size_t numberOfElements)
{
	for (size_t j = 0; j < numberOfElements; j++)
	{
		for (size_t i = 1; i < size; i++)
		{
			array[i - 1] = array[i];
		}
		size--;
		array[size] = '\0';
	}
}

void String::trimEnd(size_t numberOfElements)
{
	size -= numberOfElements;
	array[size] = '\0';
}

String String:: operator+(const String& other_string)
{
	
	String helper;
	helper.size = size + other_string.size;
	helper.capacity = capacity + other_string.capacity;

	if (helper.size >= helper.capacity)
		helper.resize();

	for (size_t i = 0; i < size; i++)
	{
		helper.array[i] = array[i];
	}

	size_t j = 0;
	for (size_t i = size; i < helper.size; i++,j++)
	{
			helper.array[i] = other_string.array[j];
	}

	helper.array[helper.size] = '\0';
	return helper;
}

String& String:: operator+=(const String& other_string)
{
	if (size >= capacity)
	{
		resize();
	}

	for (size_t i = 0; i < other_string.size; i++)
	{
		array[size] = other_string.array[i];
		size++;
	}
	array[size] = '\0';
	return *this;
}

bool String::operator==(const String& other_string)
{
	if (size == other_string.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] != other_string.array[i])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

bool String:: operator!=(const String& other_string)
{
	if (size != other_string.size)
	{
		return false;
	}
	else 
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] != other_string.array[i])
			{
				return false;
			}
		}
	return true;
}

char String::operator[](size_t index)
{
	if (index > size)
	{
		return 0;
	}
	return array[index-1];
}


void String:: print()const
{
	std::cout <<array<< std::endl;
}

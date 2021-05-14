#include "String.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

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
	capacity = 10;
	size = 1;
	array = new char[capacity];
	array[0] = '\0';
}

String::String(const char* string)                 
{
	array = new char[strlen(string) + 1];
	strcpy_s(array, strlen(string) + 1, string);
	capacity = strlen(string)+1;
	size = strlen(string);
}

String& String::operator=(const String& other_string) 
{
	if (this != &other_string)
	{
		//erase();
		copy(other_string);
	}
	return *this;
}
/*
String& String::operator=(const char* _char)
{
	erase();
	capacity = strlen(_char) + 1;
	array = new char[capacity];
	size = strlen(_char);
	strcpy_s(array, strlen(_char) + 1, _char);

	return *this;
}*/

String::~String()            
{
	erase();
}

String::String(const String& other_string)              
{
	//erase();
	copy(other_string);
}

void String::setArray(const char* _array)
{
	erase();
	size = strlen(_array);
	capacity = size;
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

size_t String::getLength()         
{
	size = strlen(array);
	return size;
}

int String::dateDay()
{
	int Day = convertStringToInt() % 100; //99.12.31;

	return Day;
}

int String::dateMonth()
{
	int Month = convertStringToInt() / 100; //991231 -> 9912;
	Month = Month % 100;

	return Month;
}

int String::dateYear()
{
	int Year = convertStringToInt() / 10000; //991237 -> 99

	return Year;
}

int String::TimeSeconds(String time)
{
	int seconds = time.convertStringToInt() % 100; //12:57 

	return seconds;
}

int String::TimeHours(String time)
{
	int hours = time.convertStringToInt() / 100; // 1257 -> 12

	return hours;
}

int String:: convertCharToNum(char symbol) const
{
	switch (symbol)
	{
	case('1'):
		return 1;
		break;
	case('2'):
		return 2;
		break;
	case('3'):
		return 3;
		break;
	case('4'):
		return 4;
		break;
	case('5'):
		return 5;
		break;
	case('6'):
		return 6;
		break;
	case('7'):
		return 7;
		break;
	case('8'):
		return 8;
		break;
	case('9'):
		return 9;
		break;
	case('0'):
		return 0;
		break;
	}
}

int String::convertStringToInt() const
{
	int stringToInt = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
				stringToInt *= 10;
				stringToInt += convertCharToNum(array[i]);
		}
	}

	return stringToInt;
}

bool String::validateDate()
{
	if (dateYear() > 0)
	{
		if (dateMonth() == 02)
		{
			if (dateYear() % 4 == 0 && dateYear() % 100 != 0)
			{
				if (dateDay() >= 1 && dateDay() <= 29)
				{
					return true;
				}
				else return false;
			}
			else
			{
				if (dateDay() >= 1 && dateDay() <= 28)
				{
					return true;
				}
				else return false;
			}
		}
		else if (dateMonth() == 1 || dateMonth() == 3 || dateMonth() == 5 || dateMonth() == 7 || dateMonth() == 8 || dateMonth() == 10 || dateMonth() == 12)
		{
			if (dateDay() <= 31 && dateDay() >= 1)
			{
				return true;
			}
			else return false;
		}
		else if (dateMonth() == 4 || dateMonth() == 6 || dateMonth() == 9 || dateMonth() == 11)
		{
			if (dateDay() <= 30 && dateDay() >= 1)
			{
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool String::validateTime(String time)
{
	if (TimeHours(time) <= 24 && TimeHours(time) >= 0 && time.getLength() == 5 && time[2] == ':')
	{
		if (TimeSeconds(time) <= 59 && TimeSeconds(time) >= 0)
		{
			return true;
		}
		else return false;
	}
	else return false;
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
	for (size_t i = size; i < helper.size; i++, j++)
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

String& String::operator+=(const char _elem)
{
	if (size >= capacity)
	{
		resize();
	}
	array[size] = _elem;
	array[size + 1] = '\0';
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

bool String::operator==(const char* _char)
{
	if (size == strlen(_char))
	{
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] != _char[i])
			{
				return false;
			}
		}

		return true;
	}
	else
		return false;
}

bool String:: operator!=(const String& other_string)
{
	if (size != other_string.size)
	{
		return true;
	}
	else
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] != other_string.array[i])
			{
				return true;
			}
		}
	return false;
}

char String::operator[](size_t index)
{
	if (index > size)
	{
		return 0;
	}
	return array[index];
}


void String::print()const
{
	std::cout << array << std::endl;
}



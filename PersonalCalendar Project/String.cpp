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

String::String()                                 //da
{
	capacity = 10;
	size = 1;
	array = new char[capacity];
	array[0] = '\0';
}

String::String(const char* string)                  //da
{
	array = new char[strlen(string) + 1];
	strcpy_s(array, strlen(string) + 1, string);
	capacity = strlen(string)+1;
	size = strlen(string);
}

String& String::operator=(const String& other_string) //da
{
	if (this != &other_string)
	{
		erase();
		copy(other_string);
	}
	return *this;
}

String& String::operator=(const char* _char)
{
	erase();
	capacity = strlen(_char) + 1;
	array = new char[capacity];
	size = strlen(_char);
	strcpy_s(array, strlen(_char) + 1, _char);

	return *this;
}

/*String& String::operator=(const char* other_array) //?????????????????
{
	erase();
	array = new char[strlen(other_array) + 1];
	strcpy_s(array, strlen(other_array) + 1, other_array);
	return *this;
}*/

String::~String()            //da
{
	erase();
}

String::String(const String& other_string)              //da
{
	erase();
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

const char* String::getArray() const        //da
{
	return array;
}

size_t String::getSize() const        //da
{
	return size;
}

size_t String::getCapacity() const        //da
{
	return capacity;
}

void String::resize()        //da
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

/*void String::add(char newSymbol)
{
	if (size >= capacity)
	{
		resize();
	}

	array[size] = newSymbol;
	array[size + 1] = '\0';
}*/

size_t String::getLength()         //da
{
	size = strlen(array);
	return size;
}

/*void String::insertAt(size_t index, char symbol)
{
	if (size >= capacity)
	{
		resize();
	}

	for (size_t i = size; i >= index; i--)
	{
		array[i] = array[i - 1];
	}

	array[index - 1] = symbol;
	size++;
	array[size] = '\0';
}

void String::removeAt(size_t index)
{
	for (size_t i = index - 1; i < size; i++)
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
}*/

int String::dateDay()
{
	int Day = convertDateToInt() % 100; //99.12.31;

	return Day;
}

int String::dateMonth()
{
	int Month = convertDateToInt() / 100; //991231 -> 9912;
	Month = Month % 100;

	return Month;
}

int String::dateYear()
{
	int Year = convertDateToInt() / 10000; //991237 -> 99

	return Year;
}

int String::TimeSeconds(String time)
{
	int seconds = time.convertTimeToInt() % 100; //12:57 

	return seconds;
}

int String::TimeHours(String time)
{
	int hours = time.convertTimeToInt() / 100; // 1257 -> 12

	return hours;
}

int String::convertTimeToInt()
{
	int intStartTime = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] >= '0' && array[i] <= '9' || array[i] == ':')
		{
			if (array[i] != ':')
			{
				if (i == 0)
				{
					intStartTime = array[i];
				}
				else
				{
					intStartTime *= 10;
					intStartTime += array[i];
				}
			}
		}
	}
	return intStartTime;
}

int String::convertDateToInt()
{
	int intDate = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= '0' && array[i] <= '9' || array[i] == '.')
		{
			if (array[i] != '.')
			{
				if (i == 0)
				{
					intDate = array[i];
				}
				else
				{
					intDate *= 10;
					intDate += array[i];
				}
			}
		}
		else
			std::cout << "Invalid input for date.";
	}
	return intDate;
}

bool String::validateDate()
{
	if (dateYear() > 0)
	{
		if (dateMonth() == 1 || dateMonth() == 3 || dateMonth() == 5 || dateMonth() == 7 || dateMonth() == 8 || dateMonth() == 10 || dateMonth() == 12)
		{
			if (dateDay() <= 31 && dateDay() >= 1)
			{
				return true;
			}
			else return false;
		}
		if (dateMonth() == 4 || dateMonth() == 6 || dateMonth() == 9 || dateMonth() == 11)
		{
			if (dateDay() <= 30 && dateDay() >= 1)
			{
				return true;
			}
			else return false;
		}
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
	return array[index - 1];
}


void String::print()const
{
	std::cout << array << std::endl;
}



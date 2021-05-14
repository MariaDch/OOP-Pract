#pragma once
#include <iostream>

class String
{
private:
	char* array;
	size_t size;
	size_t capacity;

	void copy(const String& other_string);
	void erase();

public:
	String();
	String& operator=(const String& other_string);
	//String& operator=(const char* _char);
	~String();

	String(const String& other_string);
	String(const char* _name);

	void setArray(const char* _array);
	void setSize(size_t _size);
	void setCapacity(size_t _capacity);

	const char* getArray() const;
	size_t getSize() const;
	size_t getCapacity() const;

	void resize();

	void print()const;
	size_t getLength();
	

	int dateDay();
	int dateMonth();
	int dateYear();
	int TimeHours(String time);
	int TimeSeconds(String time);
	int convertCharToNum(char symbol)const;
	int convertStringToInt() const;
	bool validateDate();
	bool validateTime(String time);

	String operator+ (const String& other_string);
	String& operator+= (const String& other_string);
	String& operator+=(const char _elem);
	bool operator== (const String& other_string);
	bool operator==(const char* _char);
	bool operator!= (const String& other_string);
	char operator[](size_t index);
	friend std::ostream& operator<<(std::ostream& out, const String& str)          //
	{
		out << str.getArray();
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const String& string)        //
	{
		in >> string.array;
		return in;
	}
};


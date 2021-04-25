#pragma once
#include "String.h"

class Date
{
private:
	String date;
	String time;
public:
	Date();
	Date(Date& other_date);

	void setTime(String other_time);
	void setDate(String other_date);

	String getTime()const;
	String getDate()const;

	int convertTimeToInt();
	int convertDateToInt();
	void print();
};


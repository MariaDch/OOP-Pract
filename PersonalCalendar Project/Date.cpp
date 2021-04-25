#include "Date.h"
#include<iostream>

Date::Date()
{
	date.setArray('\0');
	date.setSize(1);
	date.setCapacity(2);

	time.setArray('\0');
	time.setSize(1);
	time.setCapacity(2);
}

Date::Date(Date& other_date)
{
	date = other_date.date;
	time = other_date.time;
}

void Date::setTime(String other_time)
{
	time = other_time;
}

void Date::setDate(String other_date)
{
	date = other_date;
}

String Date::getTime()const
{
	return time;
}

String Date::getDate()const
{
	return date;
}

int Date::convertDateToInt()
{
	int intYear = 0;
	int intMonth = 0;
	int intDay = 0;

	for (int i = 0; i < date.getSize(); i++)
	{
		if (date[i] >= '0' && date[i] <= '9' || date[i]=='.')
		{
			if (i <= 4)
			{
				for (int j = 0; date[j]!='.'; j++)
				{
					if (j == 0)
					{
						intYear = date[j];
					}
					else
					{
						intYear *= 10;
						intYear += date[j];
					}
				}
			}
			
		}
	}
}
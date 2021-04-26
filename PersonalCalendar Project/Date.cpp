#include "Date.h"

Date::Date()
{
	date.setArray("\0");
	date.setSize(1);
	date.setCapacity(2);

	time.setArray("\0");
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
	int intDate = 0;
	for (int i = 0; i < date.getSize(); i++)
	{
		if (date[i] >= '0' && date[i] <= '9' || date[i] == '.')
		{
			if (date.getArray()[i] != '.')
			{
				if (i == 0)
				{
					intDate = date[i];
				}
				else
				{
					intDate *= 10;
					intDate += date[i];
				}
			}
		}
		else
			std::cout << "Invalid input.";
	}
	return intDate;
}

int Date::convertTimeToInt()
{
	int intTime = 0;

	for (int i = 0; i < date.getSize(); i++)
	{
		if (time.getArray()[i] >= '0' && time.getArray()[i] <= '9' || time.getArray()[i] == ':')
		{
			if (time.getArray()[i] != '.')
			{
				if (i == 0)
				{
					intTime = time.getArray()[i];
				}
				else
				{
					intTime *= 10;
					intTime += time.getArray()[i];
				}
			}
		}
	}
	return intTime;
}

/*void Date::print()
{
	std::cout << date;
	std::cout << time;
}*/
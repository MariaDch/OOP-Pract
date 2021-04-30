#include "Meeting.h"
#include <iostream>

Meeting::Meeting()
{
	date = nullptr;
	name = nullptr;
	note = nullptr;
	startTime = nullptr;
	endTime = nullptr;
}

Meeting::Meeting(const Meeting& other_meeting)
{
	name = other_meeting.name;
	note = other_meeting.note;
	startTime = other_meeting.startTime;
	endTime = other_meeting.endTime;
}

void Meeting::setName(String other_name)
{
	name = other_name;
}

void Meeting::setNote(String other_note)
{
	note = other_note;
}

void Meeting::setStartTime(String other_startTime)
{
	startTime = other_startTime;
}

void Meeting::setEndTime(String other_endTime)
{
	endTime = other_endTime;
}

String Meeting::getDate() const
{
	return date;
}

String Meeting::getName()const
{
	return name;
}

String Meeting::getNote()const
{
	return note;
}

String Meeting::getEndTime()const
{
	return endTime;
}

String Meeting::getStartTime()const
{
	return startTime;
}

Meeting& Meeting::operator=(Meeting& other_meeting)
{
	if (this != &other_meeting)
	{	
		date = other_meeting.date;
		name = other_meeting.name;
		note = other_meeting.note;
		startTime = other_meeting.startTime;
		endTime = other_meeting.endTime;
	}
	return *this;
}

bool Meeting::operator==(Meeting& other_meeting)
{
	if (date == other_meeting.date && startTime == other_meeting.startTime && endTime == other_meeting.endTime)
	{
		return true;
	}
	else false;
}

int Meeting::dateDay()
{
	int Day = convertDateToInt() % 100; //99.12.31;

	return Day;
}

int Meeting::dateMonth()
{
	int Month = convertDateToInt() / 100; //991231 -> 9912;
	Month = Month % 100;

	return Month;
}

int Meeting::dateYear()
{
	int Year = convertDateToInt() / 10000; //991237 -> 99

	return Year;
}

int Meeting::TimeSeconds(String time)
{
	int seconds = convertTimeToInt(time) % 100; //12:57 

	return seconds;
}

int Meeting::TimeHours(String time)
{
	int hours = convertTimeToInt(time) / 100; // 1257 -> 12

	return hours;
}

int Meeting::convertTimeToInt(String time)
{
	int intStartTime = 0;

	for (int i = 0; i < time.getSize(); i++)
	{
		if (time.getArray()[i] >= '0' && time.getArray()[i] <= '9' || time.getArray()[i] == ':')
		{
			if (time.getArray()[i] != ':')
			{
				if (i == 0)
				{
					intStartTime = time.getArray()[i];
				}
				else
				{
					intStartTime *= 10;
					intStartTime += time.getArray()[i];
				}
			}
		}
	}
	return intStartTime;
}

int Meeting::convertDateToInt()
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

bool Meeting::validateDate()
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

bool Meeting::validateTime(String time)
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

/*void Meeting::print()const
{
	std::cout << name;
	std::cout << std::endl;
	std::cout << note;
	std::cout << std::endl;
	std::cout << startTime;
	std::cout << std::endl;
	std::cout << endTime;

}*/


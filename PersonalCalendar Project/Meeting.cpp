#include "Meeting.h"
#include <iostream>

Meeting::Meeting()
{
	date = "00.00.00";
	name = "Empty";
	note = "Empty";
	startTime = "00:00";
	endTime = "00:00";
}

Meeting::Meeting(String other_date, String other_startTime, String other_endTime, String other_name, String other_note)
{
	other_date.validateDate();
	other_startTime.validateTime(other_startTime);
	other_endTime.validateTime(other_endTime);

	if (other_startTime.convertStringToInt() < other_endTime.convertStringToInt())
	{
		date = other_date;
		startTime = other_startTime;
		endTime = other_endTime;
		name = other_name;
		note = other_note;
	}
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

void Meeting::setDate(String other_date)
{
	date = other_date;
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

bool Meeting::operator==(Meeting& other_meeting)
{
	if (date == other_meeting.date && startTime == other_meeting.startTime && endTime == other_meeting.endTime)
	{
		return true;
	}
	else false;
}

int Meeting::busyHour()
{
	int hours = 0;
	int helperOne = 0;
	int helperTwo = 0;

	helperTwo = startTime.convertStringToInt() / 100; // 1300 -> 13
	helperOne = endTime.convertStringToInt() / 100;  // 1500 -> 15
	hours += helperOne - helperTwo;

	return hours;
}

void Meeting::print()const
{
	std::cout << name.getArray();
	std::cout << std::endl;
	std::cout << note.getArray();
	std::cout << std::endl;
	std::cout << startTime.getArray();
	std::cout << std::endl;
	std::cout << endTime.getArray();
}

bool Meeting::overlapedMeetings(Meeting& other)
{
		int vectorconvertedStartTime = startTime.convertStringToInt();
		int vectorconvertedEndTime = endTime.convertStringToInt();

		int otherConvertedStartTime = other.startTime.convertStringToInt();
		int otherConvertedEndTime = other.endTime.convertStringToInt();

		if (date.validateDate() && startTime.validateTime(startTime) && endTime.validateTime(endTime))
		{
			if (date == other.date && vectorconvertedEndTime == otherConvertedStartTime)
			{
				return false;
			}
			else if (date == other.date && vectorconvertedStartTime < otherConvertedStartTime && vectorconvertedEndTime == otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime > otherConvertedStartTime && vectorconvertedEndTime == otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime < otherConvertedStartTime && vectorconvertedEndTime < otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime > otherConvertedStartTime && vectorconvertedEndTime > otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime == otherConvertedStartTime && vectorconvertedEndTime > otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime == otherConvertedStartTime && vectorconvertedEndTime > otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime == otherConvertedStartTime && vectorconvertedEndTime == otherConvertedEndTime)
			{
				return true;
			}
			else if (date == other.date && vectorconvertedStartTime > otherConvertedStartTime && vectorconvertedEndTime < otherConvertedEndTime)
			{
				return true;
			}
			else
				return false;
		}
}
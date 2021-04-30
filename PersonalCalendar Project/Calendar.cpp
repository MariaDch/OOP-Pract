#include "Calendar.h"

void Calendar::copy(Calendar& other_calendar)
{
	meetings = other_calendar.meetings;
	date = other_calendar.date;
	startTime = other_calendar.startTime;
	endTime = other_calendar.endTime;
}

Calendar::Calendar()
{
	//meetings; ???????????????????????????????
	date = nullptr;
	startTime = nullptr;
	endTime = nullptr;
}

Calendar::Calendar(Calendar& other_calendar)
{
	copy(other_calendar);
}

void Calendar::setMeetings(Vector<Meeting>& other_meetings)
{
	meetings = other_meetings;
}

void Calendar::setDate(String& other_date)
{
	date = other_date;
}

void Calendar::setStartTime(String& other_startTime)
{
	startTime = other_startTime;
}

void Calendar::setEndTime(String& other_endTime)
{
	endTime = other_endTime;
}

Vector<Meeting> Calendar::getMeetings() const
{
	return meetings;
}

String Calendar::getDate() const
{
	return date;
}

String Calendar::getStartTime()const
{
	return startTime;
}

String Calendar::getEndTime()const
{
	return endTime;
}

void Calendar::book(Meeting meeting)
{
	bool busy = false;
	for (int i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getDate() == meeting.getDate() && meeting[i] == meeting.getStartTime() && meetings[i].getEndTime() == meeting.getEndTime())
		{
			busy = true;
		}
	}

	if (busy == false)
	{
		meetings.increseSize();
		meetings[meetings.getSize()] = meeting;
	}
}

void Calendar::unbook(Meeting meeting)
{
	for (int i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getDate() == meeting.getDate() && meeting[i] == meeting.getStartTime() && meetings[i].getEndTime() == meeting.getEndTime())
		{
			//meetings[i].~Vector(); ????????????????
			meetings[i].setDate(nullptr);
			meetings[i].setStartTime(nullptr);
			meetings[i].setEndTime(nullptr);
			meetings[i].setName(nullptr);
			meetings[i].setNote(nullptr);
			break;
		}
	}
}



void Calendar::agenda(String _date)
{
	for (int i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getDate() == _date)
		{
			std::cout << meetings[i];
		}
	}
}



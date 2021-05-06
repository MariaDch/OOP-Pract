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
	date = "00.00.00";
	startTime = "00:00";
	endTime = "00:00";
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
	if(meetings.duplicateElements(meeting));               //TRQBVA  DA E VQNO
	meetings.pushBack(meeting);
}

void Calendar::unbook(String _date, String start_time, String end_time)
{
	meetings.removeElement(_date, start_time, end_time);		 //PROMQNA NA FUNKCIQTA VUV VEKCTOR.H   napraveno 
}

void Calendar::agenda(String _date)
{
	for (int i = 0; i < meetings.getSize(); i++)
	{
		meetings.sort();

		if (meetings[i].getDate() == _date)
		{
			meetings[i].print();
		}
	}
}


void Calendar::find(String findString)
{
	for (size_t i = 0; i < meetings.getSize(); i++)
	{
		if (meetings[i].getName() == findString || meetings[i].getNote() == findString)
		{
				meetings[i].print();
		}
	}
}

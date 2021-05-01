#pragma once
#include "Meeting.h"
#include "String.h"
#include "Vector.h"

class Calendar
{
private:
	Vector <Meeting> meetings;
	String date;
	String startTime;
	String endTime;

	void copy(Calendar& other_calendar);
public:
	Calendar();
	Calendar(Calendar& other_calendars);

	void setMeetings(Vector<Meeting>& other_meetings);
	void setDate(String& other_date);
	void setStartTime(String& other_startTime);
	void setEndTime(String& other_ednTime);

	Vector <Meeting> getMeetings()const;
	String getDate()const;
	String getStartTime()const;
	String getEndTime()const;

	void book(Meeting meeting);
	void unbook(Meeting meeting);
	void agenda(String _date);
	void change(Meeting meet, String option, String newValue);
	void find(String findString);
	void holiday(String _date);
	void busyDays(String from, String to);
	void findSlot(String date, int hours);
	void findSlotWith(String _date, int hours, Vector<Calendar> calendars);
	void merge(Vector<Calendar> calendars);

};

